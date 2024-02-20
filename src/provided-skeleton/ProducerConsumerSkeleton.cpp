#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

// Skeleton code provided

#define BUFF_SIZE   5		/* total number of slots */
#define NP          3		/* total number of producers */
#define NC          3		/* total number of consumers */
#define NITERS      4		/* number of items produced/consumed */

typedef struct {
    int buf[BUFF_SIZE];   /* shared var */
    int in;         	  /* buf[in%BUFF_SIZE] is the first empty slot */
    int out;        	  /* buf[out%BUFF_SIZE] is the first full slot */
    sem_t full;     	  /* keep track of the number of full spots */
    sem_t empty;    	  /* keep track of the number of empty spots */
    sem_t mutex;    	  /* enforce mutual exclusion to shared data */
} sbuf_t;

sbuf_t shared;

void *Producer(void *arg)
{
    int i, item, index;
 
   /* Fill in the code here */
    for (i=0; i < NITERS; i++) {

      /* Fill in the code here */

        /* Interleave  producer and consumer execution */
        if (i % 2 == 1) sleep(1);
    }
    return NULL;
}

void *Consumer(void *arg)
{
    /* Fill in the code here */
}

int main()
{
    pthread_t idP, idC;
    int index;

   

    /* Insert code here to initialize semaphores */

    for (index = 0; index < NP; index++)
    {  
       /* Create a new producer */
       pthread_create(&idP, NULL, Producer, (void*)index);
    }

    /* Insert code here to create NC consumers */

    pthread_exit(NULL);
}
//Important note: You must link the pthread library to any program that uses pthreads. You must also link the runtime library rt to any program that uses semaphores. So the compile command for the program above (call it prodcon.c) would be
//    gcc -o prodcon prodcon.c -lpthread -lrt