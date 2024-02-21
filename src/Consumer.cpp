#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // The consumer's start routine
    void *Consumer(void *arg)
    {
        // Item it is consuming (a pointer)
        buffer_item* item;

        // Loops until it consumes all it's going to consume
        for (int i = 0; i < NITERS; i++) {
            /* Interleave producer and consumer execution */
            // Basically ensures that the producers and consumers are not synchronized
            sleep(1);

            // Make sure we wait for the buffer to be filled by some producer
            // So we don't grab an empty slot on accident (wait for a full slot)
            sem_wait(&shared.full);
            // CRITICAL SECTION
            r_code code = RetrieveItem(item);

            // Acquire a mutex lock for outputting to the terminal
            // and incrementing the number of empty slots
            // Acquire the semaphore
            sem_wait(&shared.mutex);

            // CRITICAL SECTION
            if (code == 1) {
                cerr << "ERR: Consumer " << (int)arg << " failed to extract an item!" << endl;
            }
            else if (code == 2) {
                cerr << "ERR: Retrieved an empty item! Buffer: " << endl;
                for (int j = 0; j < BUFF_SIZE; j++) {
                    cerr << "\ti" << j << " = " << shared.buf[j] << endl;
                }
                cerr << "Buffer in was at idx " << shared.in << endl;
                cerr << "Buffer out was at idx " << shared.out << endl;
            }
            else {
                cout << " >> " << "Consumer " << (int)arg << " consumed " << *item << endl;
            }
            // Consume the item. Delicious.
            *item = -1;
            shared.out++;
            sem_post(&shared.empty); // Increment an empty spot

            // Release the semaphore
            sem_post(&shared.mutex);
        }
        // Terminate the thread.
        pthread_exit(0);
    }

}
