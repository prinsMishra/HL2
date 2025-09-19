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
#include<sys/time.h>
 
void signalhandler(int signalid) {
    printf("Caught signal prof imer %d\n", signalid);
     
     
}

int main() {
    struct itimerval timer;
     
    
    signal(SIGPROF, signalhandler);  
    
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 10;
    setitimer(ITIMER_PROF ,&timer, NULL);
    
    while(1);

    


    return 0;
}

//Caught signal prof imer 27