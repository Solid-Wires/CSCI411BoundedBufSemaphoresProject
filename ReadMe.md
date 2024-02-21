# CSCI 411 Bounded Buffer (Semaphore) Project LAB

Jared Whytsell

This assignment was about understanding threads, semaphores, and about solving the bounded buffer problem.

# Assumptions

* How I consume out of the buffer is arbitrary, although setting "consumed" places to -1 made the most sense to me.
* Random wait times for both instances are randomized between 1 to 4 seconds.
* I'm fairly confident that if the main thread terminates, all of the child threads will also get killed. I checked if this was so with top -H and it appears so.
* Some skeleton code parts of the lab document indicated infinite loops for the producer and consumers, although the provided skeleton code had finite loops. I mostly followed along with the provided skeleton over the document's skeletons.

# How to run
Simply run make to create the executables. You should see bin and obj directories created in the workspace.

bin/BoundBuf executes the program. It doesn't require any arguments, but if you do provide arguments, here's the rundown of them:
* arg 1 - secRunTime: How long the main thread runs before terminating itself and all of the child threads. Defaults to 6 seconds.
* arg 2 - numProducerThreads: How many producer threads to start in the procedure. Defaults to 3 threads.
* arg 3 - numConsumerThreads: How many consumer threads to start in the procedure. Defaults to 3 threads.

When you do run the program, what you should see are interactions between producers and consumers over a shared buffer. Each producer and consumer will attempt their actions a total of 4 fixed times. The program will eventually terminate after the defined amount of seconds. Notice that the threads may not entirely cover their executions if long random wait times are selected over a short run duration or if there aren't an equal number of producers and consumers.