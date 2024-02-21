#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

  // The producer's start routine
  void *Producer(void *arg)
  {
    // Item it is producing
    buffer_item item;

    // Loops until it produces all it's going to produce
    for (i = 0; i < NITERS; i++) {
      /* Interleave producer and consumer execution */
      // Basically ensures that the producers and consumers are not synchronized
      //if (i % 2 == 1) sleep(sleepTime);

      item = rand();
      r_code code = InsertItem(item);
      if (code == -1) {
        cerr << "ERR: Producer failed to insert an item!" << endl;
      }
      else {
        cout << "Producer produced " << item << endl;
      }
    }
    return NULL;
  }
  
}
