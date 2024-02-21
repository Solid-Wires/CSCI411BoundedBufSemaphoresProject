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
        r_code code = 0;

        // CRITICAL SECTION
        try {
            shared.buf[shared.in%BUFF_SIZE] = item;
            shared.in++;
        } catch (...) { code = 1; }

        // Release the semaphore
        sem_post(&shared.mutex);
        return code;
    }

    // Take an item out of the first full slot from the buffer.
    // shared.out gets incremented, and Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    r_code RemoveItem(buffer_item *&itemptr) {

        // Mutex lock on removing items
        // Acquire the semaphore
        sem_wait(&shared.mutex);
        r_code code = 0;

        // CRITICAL SECTION
        try {
            itemptr = &shared.buf[shared.out%BUFF_SIZE];
            shared.out++;
            return 0;
        } catch (...) { code = 1; }

        // Release the semaphore
        sem_post(&shared.mutex);

        return code;
    }
} 
