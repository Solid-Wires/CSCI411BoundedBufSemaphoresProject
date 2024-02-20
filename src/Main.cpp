#include "../inc/Common.h"
using namespace std;

typedef struct {
    int buf[BUFF_SIZE];   /* shared var */
    int in;         	  /* buf[in%BUFF_SIZE] is the first empty slot */
    int out;        	  /* buf[out%BUFF_SIZE] is the first full slot */
    sem_t full;     	  /* keep track of the number of full spots */
    sem_t empty;    	  /* keep track of the number of empty spots */
    sem_t mutex;    	  /* enforce mutual exclusion to shared data */
} sbuf_t;
sbuf_t shared;

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
