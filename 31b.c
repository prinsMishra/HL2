/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t count_sem;

void* worker(void* arg) {
    int id = *((int*)arg);

    printf("Thread %d waiting for a resource...\n", id);
    sem_wait(&count_sem);  
    printf("Thread %d USING a resource for 5 sec\n", id);
    sleep(5);   
    printf("Thread %d DONE using resource.\n", id);

    sem_post(&count_sem);   
    return NULL;
}

int main() {
    pthread_t threads[8];
    int ids[8];

     
    sem_init(&count_sem, 0, 4);

 
    for (int i = 0; i < 8; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

  
    for (int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }
 
    // sem_destroy(&count_sem);
    return 0;
}


/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 31b.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Thread 1 waiting for a resource...
Thread 1 USING a resource for 5 sec
Thread 3 waiting for a resource...
Thread 3 USING a resource for 5 sec
Thread 2 waiting for a resource...
Thread 2 USING a resource for 5 sec
Thread 4 waiting for a resource...
Thread 4 USING a resource for 5 sec
Thread 5 waiting for a resource...
Thread 6 waiting for a resource...
Thread 7 waiting for a resource...
Thread 8 waiting for a resource...
Thread 2 DONE using resource.
Thread 1 DONE using resource.
Thread 3 DONE using resource.
Thread 4 DONE using resource.
Thread 8 USING a resource for 5 sec
Thread 7 USING a resource for 5 sec
Thread 5 USING a resource for 5 sec
Thread 6 USING a resource for 5 sec
Thread 8 DONE using resource.
Thread 7 DONE using resource.
Thread 5 DONE using resource.
Thread 6 DONE using resource.*/