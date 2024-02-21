#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // Insert an item into the first empty slot on the buffer.
    // shared.in gets incremented, and Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    r_code InsertItem(buffer_item item) {

        // Acquire mutex semaphore
        // Mutex lock on inserting items
        sem_wait(&shared.mutex);
        r_code code = 0;

        // CRITICAL SECTION
        try {
            shared.buf[shared.in%BUFF_SIZE] = item;
            shared.in++;
            sem_post(&shared.full); // Increment a full spot
        } catch (...) { code = 1; }

        // Release the mutex semaphore
        sem_post(&shared.mutex);
        return code;
    }

    // Retrieve an item out of the first full slot from the buffer.
    // Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    //
    // NOTE: I accidentally made this slightly different from your skeleton, but I think
    //  it is more appropriate for the consumer to handle consumption, and I
    //  also think pointers are cool. So I left this the way it is.
    r_code RetrieveItem(buffer_item *&itemptr) {
        
        // Acquire mutex semaphore
        // Mutex lock on retrieving items
        sem_wait(&shared.mutex);
        r_code code = 0;

        // CRITICAL SECTION
        try {
            itemptr = &shared.buf[shared.out%BUFF_SIZE];
            //shared.out doesn't get incremented because removal is handled somewhere else
        } catch (...) { code = 1; }
        // The item retrieved shouldn't be -1 (it was consumed if this is so)
        if (*itemptr == -1) { code = 2; }
        cout << "ptrval " << *itemptr << endl;

        // Release the mutex semaphore
        sem_post(&shared.mutex);
        return code;
    }
} 
