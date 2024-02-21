#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // Insert an item into the first empty slot on the buffer.
    // shared.in gets incremented, and Mod BUFF_SIZE wraps around
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

    // Pop an item out of the first full slot from the buffer.
    // shared.out gets incremented, and Mod BUFF_SIZE wraps around
    // Mutex lock makes sure that the buffer doesn't get modified everywhere
    //
    // This used to be a clever retrieval, but a nasty bug with pointer addresses
    // afflicted my code. The item == -1 check from Consumer.cpp tells quite a story.
    r_code RemoveItem(buffer_item &item) {
        
        // Acquire mutex semaphore
        // Mutex lock on retrieving items
        sem_wait(&shared.mutex);
        r_code code = 0;

        // CRITICAL SECTION
        try {
            item = shared.buf[shared.out%BUFF_SIZE];
            shared.buf[shared.out%BUFF_SIZE] = -1;
            shared.out++;
            sem_post(&shared.empty); // Increment an empty spot
        } catch (...) { code = 1; }

        // Release the mutex semaphore
        sem_post(&shared.mutex);
        return code;
    }
} 
