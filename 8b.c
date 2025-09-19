/*

============================================================================

Name : 8b.c

Author : Prins Mishra

Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
 
Date: 20th sep, 2025.

============================================================================

*/ 

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int stop = 1;
void signalhandler(int signalid) {
    printf("Caught SIGINT %d\n", signalid);
    stop = 0;
     
}

int main() {
    signal(SIGINT, signalhandler);  

     while(stop){

     }

    return 0;
}

//Caught SIGINT 2