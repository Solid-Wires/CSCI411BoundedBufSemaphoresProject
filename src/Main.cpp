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
    // Get command line arguments
    int secRunTime = RT;
    int numProducerThreads = NP;
    int numConsumerThreads = NC;
    try {
        if (argc > 1) {
            // Sleep time (optional)
            secRunTime = stoi(argv[1]);
            if (secRunTime < 1) {
                throw invalid_argument("ERR: Cannot make run time less than 1");
            }
        }
        if (argc > 2) {
            // Number of producer threads (optional)
            numProducerThreads = stoi(argv[2]);
            if (numProducerThreads < 1) {
                throw invalid_argument("ERR: Cannot make number of producer threads made less than 1");
            }
        }
        if (argc > 3) {
            // Number of consumer threads (optional)
            numConsumerThreads = stoi(argv[3]);
            if (numConsumerThreads < 1) {
                throw invalid_argument("ERR: Cannot make number of consumer threads made less than 1");
            }
        }
    // Catch any invalid arguments
    } catch(invalid_argument e) {
        cerr << e.what() << endl;
        return -1;
    }
    // Buffer is defined in shared.buf
    // All semaphores are defined in shared

    // Initialize semaphores.
    cout << "Initializing semaphores..." << endl;
    sem_init(&shared.full, 0, 0);           // The buffer is initialized empty
    sem_init(&shared.empty, 0, BUFF_SIZE);  // Only as big as the empty buf size
    sem_init(&shared.mutex, 0, 1);          // Only one thread is allowed to touch mutex areas or wait for a release
    cout << "All semaphores successfully initialized" << endl;

    // Sometimes, I ran unit tests.
    //UnitTests::UnitTestingWorks();
    //UnitTests::BufManipTests();

    // Run the main interaction procedure.
    InteractionProcedure(secRunTime, numProducerThreads, numConsumerThreads);
    
    // End of program
    cout << endl << "Program successfully executed" << endl;
    return 0;
}