#include "../inc/Common.h"

// Defined within namespace
namespace BoundedBufProj {

    // The program's main procedure; interaction between consumers and producers.
    r_code InteractionProcedure() {
        // Initialize Producer threads
        for (int i = 0; i < numProducerThreads; i++)
        {  
            /* Create a new producer */
            pthread_create(&idP, NULL, Producer, (void*)i);
        }
        // Initialize Consumer threads
        for (int i = 0; i < numConsumerThreads; i++)
        {  
            /* Create a new producer */
            pthread_create(&idC, NULL, Consumer, (void*)i);
        }

        // Any threads up to this point, terminate.
        // Procedure is complete.
        pthread_exit(NULL);
        return 0;
    }
}
