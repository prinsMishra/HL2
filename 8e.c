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
    printf("Caught SIGTIMER %d\n", signalid);
     
     
}

int main() {
    struct itimerval timer;
     
    
    signal(SIGALRM, signalhandler);  
    
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 10;
    setitimer(ITIMER_REAL ,&timer, NULL);
     pause ();
    


    return 0;
}

//Caught SIGTIMER 14