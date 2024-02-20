// This is possible instead of include guards in this version
#pragma once

//Includes from skeleton
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
// Includes I added
#include <iostream>
#include <unistd.h>

// Constant fields
#define BUFF_SIZE   5		/* total number of slots */
#define NP          3		/* total number of producers */
#define NC          3		/* total number of consumers */
#define NITERS      4		/* number of items produced/consumed */

// Fields and structs
typedef struct {
    int buf[BUFF_SIZE];   /* shared var */
    int in;         	  /* buf[in%BUFF_SIZE] is the first empty slot */
    int out;        	  /* buf[out%BUFF_SIZE] is the first full slot */
    sem_t full;     	  /* keep track of the number of full spots */
    sem_t empty;    	  /* keep track of the number of empty spots */
    sem_t mutex;    	  /* enforce mutual exclusion to shared data */
} sbuf_t;
sbuf_t weird;

// Functions
// Since producer and consumer are so simple, they don't really need their own headers
void *Producer(void *arg);
void *Consumer(void *arg);
