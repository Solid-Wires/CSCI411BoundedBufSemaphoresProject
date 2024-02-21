#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // The consumer's start routine
    void *Consumer(void *arg)
    {
        // Item it is consuming
        buffer_item item;

        // Loops until it consumes all it's going to consume
        for (i = 0; i < NITERS; i++) {
            /* Interleave producer and consumer execution */
            // Basically ensures that the producers and consumers are not synchronized
            //sleep(sleepTime);

            r_code code = RemoveItem(&item);
            if (code == -1) {
                cerr << "ERR: Consumer failed to extract an item!" << endl;
            }
            else {
                cout << "Consumer consumed " << item << endl;
            }
        }
    }

}
