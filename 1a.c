/*

============================================================================

Name : 1a.c

Author : Prins Mishra

Description : 1. Write a separate program (for each time domain) to set an interval timer in 10 sec and 10 micro second
a. ITIMER_REAL

Date: 19th sep, 2025.

============================================================================

*/ 





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handle_alarm(int signum) {
    printf("Timer expired! Caught signal %d\n", signum);
}
 
int main() {
    struct itimerval timer;

     signal(SIGALRM, handle_alarm);
     
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

     
    setitimer(ITIMER_REAL, &timer, NULL);
         
   
    pause();
   
    
    return 0;
}

//Timer expired! Caught signal 14