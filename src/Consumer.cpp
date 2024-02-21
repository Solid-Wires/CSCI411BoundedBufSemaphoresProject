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

            r_code code = RemoveItem(item);

            // Acquire a mutex lock for outputting to the terminal
            // Acquire the semaphore
            sem_wait(&shared.mutex);

            // CRITICAL SECTION
            if (code == -1) {
                cerr << "ERR: Consumer failed to extract an item!" << endl;
            }
            else {
                cout << " >> " << "Consumer " << pthread_self() << " consumed " << *item << endl;
            }
            // Consume the item. Delicious.
            *item = 0;

            // Release the semaphore
            sem_post(&shared.mutex);
        }
        // Terminate the thread.
        pthread_exit(0);
    }

}
