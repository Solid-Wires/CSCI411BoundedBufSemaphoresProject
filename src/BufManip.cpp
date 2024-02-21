#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // Insert an item into the first empty slot on the buffer.
    // shared.in gets incremented, and Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    r_code InsertItem(buffer_item item) {

        // Acquire semaphores
        // Make sure we wait for the buffer to be flushed by other consumers
        // So we don't overflow the buffer unnecessarily (wait for an empty slot)
        sem_wait(&shared.empty);
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

    // Take an item out of the first full slot from the buffer.
    // shared.out gets incremented, and Modulo BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    r_code RemoveItem(buffer_item *&itemptr) {
        
        // Acquire semaphores
        // Make sure we wait for the buffer to be filled by some producer
        // So we don't grab an empty slot on accident (wait for a full slot)
        sem_wait(&shared.full);
        // Mutex lock on removing items
        sem_wait(&shared.mutex);
        r_code code = 0;

        // CRITICAL SECTION
        try {
            itemptr = &shared.buf[shared.out%BUFF_SIZE];
            shared.out++;
            sem_post(&shared.empty); // Increment an empty spot
        } catch (...) { code = 1; }

        // Release the mutex semaphore
        sem_post(&shared.mutex);
        return code;
    }
} 
