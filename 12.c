/*

============================================================================

Name : 9.c

Author : Prins Mishra

Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
 

 
Date: 30th sep, 2025.

============================================================================

*/ 
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main (){
     

    pid_t pid;
    pid = fork();
    if(pid == 0){
        printf("i am the child my parent id is %d\n", getpid());

        printf("sending signal to kill parent manully\n");
        kill(getppid(), SIGKILL);

        sleep(5);
    }
    else{
        printf("i am parent my pig is %d\n=", getpid());

        while(1){
            
        }
        
    }
   return 0;


    
    
}
/*i am parent my pig is 9897
i am the child my parent id is 9898
sending signal to kill parent manully
Killed*/