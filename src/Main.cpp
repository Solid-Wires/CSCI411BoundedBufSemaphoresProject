#include "../inc/Common.h"
using namespace BoundedBufProj;
using namespace std;

// Namespace field definitions
namespace BoundedBufProj {
    sbuf_t shared;
}

// Main point of entry
int main()
{
    pthread_t idP, idC;
    int index;

    // Initialize buffer

    /* Insert code here to initialize semaphores */

    for (index = 0; index < NP; index++)
    {  
        /* Create a new producer */
        pthread_create(&idP, NULL, Producer, (void*)index);
    }

    /* Insert code here to create NC consumers */

    pthread_exit(NULL);
}