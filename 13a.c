/*

============================================================================

Name : 13a.c

Author : Prins Mishra

Description :  13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
 

 
Date: 30th sep, 2025.

============================================================================

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
void signalhandler(int signalno){
    printf("cought signal %d\n", signalno);
}
int main(){
    signal(SIGSTOP, signalhandler);

    printf("this program will wait for signstop %d\n", getpid());

    while(1){

    }
}
/*this program will wait for signstop 10094


[1]+  Stopped                 ./a.out*/