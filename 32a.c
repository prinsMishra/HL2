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
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int ticketno = 0;
sem_t binary_sem;

void* helper(void* arg) {
    int id = *((int*)arg);

    printf("Thread %d waiting for semaphore...\n", id);
    sem_wait(&binary_sem);  
    
    printf("Thread %d ENTERED critical section with ticketno %d\n", id, ticketno);
    ticketno++;
    printf("Thread %d LEAVING critical section with ticketno.%d\n", id, ticketno);

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
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 32a.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Thread 1 waiting for semaphore...
Thread 1 ENTERED critical section with ticketno 0
Thread 1 LEAVING critical section with ticketno.1
Thread 2 waiting for semaphore...
Thread 2 ENTERED critical section with ticketno 1
Thread 2 LEAVING critical section with ticketno.2
*/