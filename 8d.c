/*

============================================================================

Name : 8d.c

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
#include<unistd.h>
 
void signalhandler(int signalid) {
    printf("Caught SIGALM %d\n", signalid);
     
     
}

int main() {
    signal(SIGALRM, signalhandler);  

     
   alarm(10);
     pause();


    return 0;
}

//Caught SIGALM 14