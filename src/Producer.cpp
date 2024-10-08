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
    for (int i = 0; i < NITERS; i++) {
      /* Interleave producer and consumer execution */
      // Basically ensures that the producers and consumers are not synchronized
      if (i % 2 == 1) sleep((rand() % 4) + 1); // Sleep between 1 to 4 seconds

      // Make sure we wait for the buffer to be flushed by other consumers
      // So we don't overflow the buffer unnecessarily (wait for an empty slot)
      sem_wait(&shared.empty);
      item = rand();
      r_code code = InsertItem(item);

      // Acquire a mutex lock for outputting to the terminal
      // I had some... interesting results when threads tried to output
      // stuff on the same terminal.
      // Acquire the semaphore
      sem_wait(&shared.mutex);

      // CRITICAL SECTION
      if (code == 1) {
        cerr << "ERR: Producer " << (int)arg << " failed to insert an item!" << endl;
        pthread_exit(NULL);
      }
      else {
        cout <<  " << " <<  "Producer " << (int)arg << " produced " << item << endl;
      }
      
      // Release the semaphore
      sem_post(&shared.mutex);
    }
    // Terminate the thread.
    pthread_exit(NULL);
  }
  
}
