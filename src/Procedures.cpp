#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // The program's main procedure; interaction between consumers and producers.
    r_code InteractionProcedure(int secRunTime, int numProducers, int numConsumers) {
        cout << "Running producer consumer interaction procedure..." << endl;

        // The pthread objects
        pthread_t idP, idC;

        // Initialize Producer threads
        for (int i = 0; i < numProducers; i++)
        {  
            /* Create a new producer */
            pthread_create(&idP, NULL, Producer, (void*)i);
        }
        // Initialize Consumer threads
        for (int i = 0; i < numConsumers; i++)
        {  
            /* Create a new consumer */
            pthread_create(&idC, NULL, Consumer, (void*)i);
        }

        // Any threads up to this point, terminate.
        pthread_exit(NULL);

        // Sleep for a defined amount of seconds before terminating.
        // Once the main program terminates, all other threads will follow suit.
        sleep(secRunTime);

        // Procedure is complete.
        cout << "End of producer consumer interaction procedure" << endl;
        return 0;
    }
}
