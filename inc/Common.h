// This is possible instead of include guards in this version
#ifndef JW_COMMON
#define JW_COMMON

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
int test;

// Functions
// Since producer and consumer are so simple, they don't really need their own headers
void *Producer(void *arg);
void *Consumer(void *arg);

#endif
