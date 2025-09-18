
/*

============================================================================

Name : 1c.c

Author : Prins Mishra

Description : 1. Write a separate program (for each time domain) to set an interval timer in 10 sec and 10 micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMERPROF

Date: 19th sep, 2025.

============================================================================

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

int flag =1;
void handle_alarm(int signum) {
    printf("SIGPROF  Timer expired! Caught signal %d\n", signum);
    flag =0;
}
 
int main() {
    struct itimerval timer;

     signal(SIGPROF, handle_alarm);
     
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

     
    setitimer(ITIMER_PROF, &timer, NULL);
         
   
    
    while(flag){

    }
   
    printf("kernal returned the signal breaks the code\n");
    
    return 0;
}
 //SIGPROF  Timer expired! Caught signal 27