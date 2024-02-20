#include "../inc/Common.h"

int main()
{
    pthread_t idP, idC;
    int index;

    /* Insert code here to initialize semaphores */

    for (index = 0; index < NP; index++)
    {  
        /* Create a new producer */
        //pthread_create(&idP, NULL, Producer, (void*)index);
        cout << "Running" << endl;
    }

    /* Insert code here to create NC consumers */

    pthread_exit(NULL);
}
