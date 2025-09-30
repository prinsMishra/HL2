/*

============================================================================

Name : 9.c

Author : Prins Mishra

Description : 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE , 

 
Date: 20th sep, 2025.

============================================================================

*/ 

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
 
#include<stdlib.h>
 
 void segv_handler(int signal){
    printf("caught sigint");
    exit(1);
 }

int main() {
     
     
    
    struct sigaction sa;
    sa.sa_handler = segv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while(1);

    return 0;
}

// caught sigsegv/*

 