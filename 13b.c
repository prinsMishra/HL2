/*

============================================================================

Name : 13b.c

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

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("not getting pid");
    }
  
     pid_t pid = atoi(argv[1]);

    printf("sending the signstop to process %d\n", pid);

    kill(pid, SIGSTOP);

    return 0;

}
/*sending the signstop to process 10094*/