/*

============================================================================

Name : 9.c

Author : Prins Mishra

Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

 
Date: 20th sep, 2025.

============================================================================

*/ 

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>
 
 

int main() {
     
     
    
    signal(SIGINT, SIG_IGN);  
    sleep(5);
    

    signal(SIGINT , SIG_DFL);

    
    while(1);

    


    return 0;
}

// ingnore signal for 5 sec after, it recognised the crtl + c