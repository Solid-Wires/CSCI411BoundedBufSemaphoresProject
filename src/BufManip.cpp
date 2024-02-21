#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {
    // Insert an item into the first empty slot on the buffer.
    // shared.in gets incremented, and Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    r_code InsertItem(buffer_item item) {

        // Mutex lock on inserting items
        // Acquire the semaphore
        sem_wait(&shared.mutex);
        cout << "Mutex lock acquired" << endl;

        // CRITICAL SECTION
        try {
            shared.buf[shared.in%BUFF_SIZE] = item;
            shared.in++;
            return 0;
        } catch (...) {}

        // Release the semaphore
        sem_post(&shared.mutex);
        cout << "Mutex lock released" << endl;
        return -1;
    }

    // Take an item out of the first full slot from the buffer.
    // shared.out gets incremented, and Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    r_code RemoveItem(buffer_item *&itemptr) {

        // Mutex lock on removing items
        // Acquire the semaphore
        sem_wait(&shared.mutex);

        // CRITICAL SECTION
        try {
            itemptr = &shared.buf[shared.out%BUFF_SIZE];
            shared.out++;
            return 0;
        } catch (...) {}

        // Release the semaphore
        sem_post(&shared.mutex);

        return -1;
    }
} 
