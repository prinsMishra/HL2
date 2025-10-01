/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description :  32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define SIZE 1024
sem_t binary_sem;

void* helper(void* arg) {

    int id = *((int*)arg);
    key_t key = ftok("sharedmem", 65); 
    int shmid;
    shmid = shmget(key, SIZE, 0666 | IPC_CREAT);
    char *pointer1 = (char*) shmat(shmid, NULL, 0);

    printf("Thread %d waiting for semaphore...\n", id);
    sem_wait(&binary_sem);  
    
    printf("Thread %d ENTERED critical section \n", id);


    sprintf(pointer1, "Written in Shared Memory from Thread %d\n", id);
    printf("Data : %s\n", pointer1);

    printf("Thread %d LEAVING critical section \n", id);

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

    sem_destroy(&binary_sem);
    return 0;
}