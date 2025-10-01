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

sem_t binary_sem;

void* helper(void* arg) {
    int id = *((int*)arg);

    printf("Thread %d waiting for semaphore...\n", id);
    sem_wait(&binary_sem);  
    
    printf("Thread %d ENTERED critical section.\n", id);
    sleep(5);   
    printf("Thread %d LEAVING critical section.\n", id);

    sem_post(&binary_sem);  
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    
    sem_init(&binary_sem, 0, 1);

    pthread_create(&t1, NULL, helper, &id1);
    pthread_create(&t2, NULL, helper, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    //sem_destroy(&binary_sem);
    return 0;
}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 31a.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Thread 1 waiting for semaphore...
Thread 1 ENTERED critical section.
Thread 2 waiting for semaphore...
Thread 1 LEAVING critical section.
Thread 2 ENTERED critical section.
Thread 2 LEAVING critical section.*/