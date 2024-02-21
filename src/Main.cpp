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
        if (sleepTime < 0) {
            cerr << "ERR: Cannot make sleep time less than 0" << endl;
            return -1;
        }
    }
    else if (argc > 2) {
        // Number of producer threads (optional)
        numProducerThreads = stoi(argv[2]);
    }
    else if (argc > 3) {
        // Number of consumer threads (optional)
        numConsumerThreads = stoi(argv[3]);
    }
    // Buffer is defined in shared.buf
    // All semaphores are defined in shared

    // Sometimes, I ran unit tests.
    Util::UnitTest();

    // Run the main interaction procedure.
    //InteractionProcedure();
    
    // End of program
    cout << endl << "Main procedure finished." << endl;
    return 0;
}