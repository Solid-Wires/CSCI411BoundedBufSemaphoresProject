#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // The program's main procedure; interaction between consumers and producers.
    r_code InteractionProcedure(int secRunTime, int numProducers, int numConsumers) {
        cout << "Running producer consumer interaction procedure..." << endl;

        // The pthread objects
        pthread_t idP[numProducers];
        pthread_t idC[numConsumers];

        // Acquire the semaphore
        sem_wait(&shared.mutex);

        // CRITICAL SECTION
        // Initialize Producer threads
        for (int i = 0; i < numProducers; i++)
        {  
            /* Create a new producer */
            pthread_create(&idP[i], NULL, Producer, (void*)(i + 1));
        }
        // Initialize Consumer threads
        for (int i = 0; i < numConsumers; i++)
        {  
            /* Create a new consumer */
            pthread_create(&idC[i], NULL, Consumer, (void*)(i + 1));
        }

        cout << "Started " << numProducers << " producer threads" << endl;
        cout << "Started " << numConsumers << " consumer threads" << endl;
        cout << "Main thread is waiting for " << secRunTime << " seconds..." << endl;
        // Release the semaphore
        sem_post(&shared.mutex);

        // Sleep for a defined amount of seconds before terminating.
        sleep(secRunTime);

        // Procedure is complete.
        cout << "End of producer consumer interaction procedure" << endl;
        return 0;
    }
}
