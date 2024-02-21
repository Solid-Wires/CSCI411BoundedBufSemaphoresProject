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
#include <array>

// The project's namespace
// I played around with namespaces here. I think you only initialize them in headers?
// Basically, if you don't need this namespace, then you won't need to use it from this
// definition file.
namespace BoundedBufProj {
    // Constant fields
    #define BUFF_SIZE   5		/* total number of slots */
    #define RT          3		/* default time to run */
    #define NP          3		/* default number of producers */
    #define NC          3		/* default number of consumers */
    #define NITERS      4		/* number of items produced/consumed */

    // Fields and structs
    typedef int buffer_item; // Just an int with a special name
    typedef int r_code;
    typedef struct {
        buffer_item buf[BUFF_SIZE]; /* shared var */
        int in;               /* buf[in%BUFF_SIZE] is the first empty slot */
        int out;              /* buf[out%BUFF_SIZE] is the first full slot */
        sem_t full;     	  /* keep track of the number of full spots */
        sem_t empty;    	  /* keep track of the number of empty spots */
        sem_t mutex;    	  /* enforce mutual exclusion to shared data */
    } sbuf_t;
    extern sbuf_t shared;

    // Functions
    // Since producer and consumer are so simple, they don't really need their own headers
    void *Producer(void *arg);
    void *Consumer(void *arg);
    r_code InteractionProcedure(int secRunTime, int numProducers, int numConsumers);
    r_code InsertItem(buffer_item item);
    r_code RemoveItem(buffer_item &item);

    //Unit testing stuff, mostly for helping with debugging and verifying procedure calls
    namespace UnitTests {
        // Functions
        void UnitTestingWorks(void);
        void BufManipTests(void);
    }
}
