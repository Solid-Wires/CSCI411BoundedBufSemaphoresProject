#include "../inc/Common.h"
using namespace BoundedBufProj;
using namespace std;

// Namespace field definitions
namespace BoundedBufProj {
    sbuf_t shared;
}

// Main point of entry
int main(int argc, char *argv[])
{
    // For pthreads
    pthread_t idP, idC;
    int index;

    // Get command line arguments
    //  Must pass 3 arguments (plus the command itself)
    int sleepTime = 0;
    int numProducerThreads;
    int numConsumerThreads;
    if (argc == 1 + 3) {
        sleepTime = stoi(argv[1]);
        numProducerThreads = stoi(argv[2]);
        numConsumerThreads = stoi(argv[3]);
    }
    else {
        cerr << "ERR: Invalid num of params. Must provide 3 params." << endl;
        return 1;
    }

    // Initialize buffer
    buffer_item buffer;

    /* Insert code here to initialize semaphores */

    for (index = 0; index < NP; index++)
    {  
        /* Create a new producer */
        pthread_create(&idP, NULL, Producer, (void*)index);
    }

    /* Insert code here to create NC consumers */

    pthread_exit(NULL);
}