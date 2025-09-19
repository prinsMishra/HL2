/*

============================================================================

Name : 6.c

Author : Prins Mishra

Description : 6. Write a simple program to create three threads.
Date: 19th sep, 2025.

============================================================================

*/ 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

 
void* thread_function(void* arg) {
    int id = *((int*)arg);
    printf(" thread %d (Thread ID: %lu)\n", id, pthread_self());
    
     
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

     
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &ids[i]);
            
    }

     
      for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");
    return 0;
}

/*
 thread 1 (Thread ID: 140737349940928)
 thread 2 (Thread ID: 140737341548224)
 thread 3 (Thread ID: 140737333155520)
All threads finished.
*/