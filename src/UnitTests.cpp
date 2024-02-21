#include "../inc/Common.h"
using namespace std;

// Utility definitions of util
namespace BoundedBufProj {
    namespace UnitTests {

        // Does this work?
        void UnitTestingWorks() {
            cout << "Unit test method successful" << endl;
            return 0;
        }

        // Essentially does what the threads are going to try to do 
        // from the main procedure anyways, but on one main thread, see
        // if we can produce and consume values out of the tin.
        void BufManipTests() {
            int i = 0;
            cout << "Buffer manipulation tests starting..." << endl;

            // Produce
            Producer(&i);
            
            // Consume
            Consumer(&i);

            cout << "Buffer manipulation successful" << endl;
            return 0;
        }
    }
}

