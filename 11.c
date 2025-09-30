/*

============================================================================

Name : 9.c

Author : Prins Mishra

Description :11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
 

 
Date: 20th sep, 2025.

============================================================================

*/ 
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main (){
    struct  sigaction sastruct;

    sastruct.sa_handler = SIG_IGN;
    sigemptyset(&sastruct.sa_mask);
    sastruct.sa_flags = 0;

    sigaction(SIGINT , &sastruct , NULL);

    printf("sigint ignore  7 sec for crt + c \n");
    sleep(7);

    
    sastruct.sa_handler = SIG_DFL;
    sigemptyset(&sastruct.sa_mask);
    sastruct.sa_flags = 0;
    
    sigaction(SIGINT , &sastruct , NULL);
    
    printf("after 7 sec it will recoginized crt + c\n");
    while(1);



    
    
}
/*sigint ignore  7 sec for crt + c 
after 7 sec it will recoginized crt + c*/