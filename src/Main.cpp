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
    // Get command line arguments
    int numProducerThreads = NP;
    int numConsumerThreads = NC;
    try {
        if (argc > 1) {
            // Sleep time (optional)
            sleepTime = stoi(argv[1]);
            if (sleepTime < 0) {
                throw invalid_argument("ERR: Cannot make sleep time less than 0");
            }
        }
        else if (argc > 2) {
            // Number of producer threads (optional)
            numProducerThreads = stoi(argv[2]);
            if (numProducerThreads < 1) {
                throw invalid_argument("ERR: Cannot make number of producer threads made less than 1");
            }
        }
        else if (argc > 3) {
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

    // Sometimes, I ran unit tests.
    //UnitTests::UnitTestingWorks();
    UnitTests::BufManipTests();

    // Run the main interaction procedure.
    //InteractionProcedure(numProducerThreads, numConsumerThreads);
    
    // End of program
    cout << endl << "Main procedure finished." << endl;
    return 0;
}