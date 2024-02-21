#include "../inc/Common.h"
using namespace std;

// Utility definitions of util
namespace BoundedBufProj {
    namespace UnitTests {

        // Does this work?
        void UnitTestingWorks() {
            cout << "Unit test method successful" << endl;
        }

        // Essentially does what the threads are going to try to do 
        // from the main procedure anyways, but on one main thread, see
        // if we can produce and consume values out of the tin.
        void BufManipTests() {
            cout << "Buffer manipulation tests starting..." << endl;

            // Produce
            Producer((void*)0);
            cout << "In buffer: " << endl;
            for (buffer_item i : shared.buf) {
                cout << '\t' << i << endl;
            }
            
            // Consume
            Consumer((void*)0);
            cout << "In buffer: " << endl;
            for (buffer_item i : shared.buf) {
                cout << '\t' << i << endl;
            }

            cout << "Buffer manipulation successful" << endl;
        }
    }
}

