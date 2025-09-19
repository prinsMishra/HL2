/*

============================================================================

Name : 8.c

Author : Prins Mishra

Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
 
Date: 19th sep, 2025.

============================================================================

*/ 

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void signalhandler(int signalid) {
    printf("Caught SIGSEGV %d\n", signalid);
     
}

int main() {
    signal(SIGSEGV, signalhandler);  

    int *p = NULL;
    *p = 100; 

    return 0;
}

//Caught SIGSEGV 11