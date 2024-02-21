#include "../inc/Common.h"
using namespace BoundedBufProj;
using namespace std;

// Namespace field definitions
namespace BoundedBufProj {
    int sleepTime = ST;
    sbuf_t shared;
}

// Main point of entry
int main(int argc, char *argv[])
{
    // The pthread objects
    pthread_t idP, idC;

    // Get command line arguments
    int numProducerThreads = NP;
    int numConsumerThreads = NC;
    if (argc > 1) {
        // Sleep time (optional)
        sleepTime = stoi(argv[1]);
    }
    else if (argc > 2) {
        // Number of producer threads (optional)
        numProducerThreads = stoi(argv[2]);
    }
    else if (argc > 3) {
        // Number of consumer threads (optional)
        numConsumerThreads = stoi(argv[3]);
    }

    // Initialize buffer
    buffer_item buffer;

    // Semaphores (already defined in shared)
    
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

    pthread_exit(NULL);
}