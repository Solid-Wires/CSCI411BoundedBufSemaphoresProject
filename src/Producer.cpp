#include "../inc/Common.h"

// Defined within namespace
namespace BoundedBufProj {

  // The producer's start routine
  void *Producer(void *arg)
  {
      int i, item, index;
  
    /* Fill in the code here */
      for (i=0; i < NITERS; i++) {

        /* Fill in the code here */

          /* Interleave  producer and consumer execution */
          if (i % 2 == 1) sleep(sleepTime);
      }
      return NULL;
  }
  
}
