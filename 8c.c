/*

============================================================================

Name : 8c.c

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
 
void signalhandler(int signalid) {
    printf("Caught SIGPFE %d\n", signalid);
    exit(1);
     
}

int main() {
    signal(SIGFPE, signalhandler);  

     
    int a = 5;
    int b  = 0;
    int c = a/b;

    return 0;
}

//Caught SIGPFE 8