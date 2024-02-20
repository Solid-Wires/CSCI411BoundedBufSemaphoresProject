// This is possible instead of include guards in this version
#pragma once

//Includes from skeleton
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <cstring>
// Includes I added
#include <iostream>
#include <unistd.h>

// The project's namespace
// I played around with namespaces here. I think you only initialize them in headers?
// Basically, if you don't need this namespace, then you won't need to use it from this
// definition file.
namespace BoundedBufProj {
    // Constant fields
    #define BUFF_SIZE   5		/* total number of slots */
    #define NP          3		/* total number of producers */
    #define NC          3		/* total number of consumers */
    #define NITERS      4		/* number of items produced/consumed */

    // Fields and structs
    typedef int buffer_item[BUFF_SIZE]; // Just an int array of BUF_SIZE
    typedef struct {
        buffer_item buf;      /* shared var */
        buffer_item in;       /* buf[in%BUFF_SIZE] is the first empty slot */
        buffer_item out;      /* buf[out%BUFF_SIZE] is the first full slot */
        sem_t full;     	  /* keep track of the number of full spots */
        sem_t empty;    	  /* keep track of the number of empty spots */
        sem_t mutex;    	  /* enforce mutual exclusion to shared data */
    } sbuf_t;
    sbuf_t shared;

    // Functions
    // Since producer and consumer are so simple, they don't really need their own headers
    void *Producer(void *arg);
    void *Consumer(void *arg);
    int InsertItem(buffer_item item);
    int RemoveItem(buffer_item *item);
}
