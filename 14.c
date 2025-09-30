
/*

============================================================================

Name : 14.c

Author : Prins Mishra

Description :  14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
 

 
Date: 30th sep, 2025.

============================================================================

*/ 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd[2];
    char writebuff[] = "messege from parent";
    char buff[100];
    
    pipe(fd);
    pid_t pid = fork();
   
    if(pid >0){
        
        close(fd[0]);
        write(fd[1], writebuff,  strlen(writebuff)+1);
        close(fd[1]);
        printf("parent has written from on end\n");
    }

    else{
        close(fd[1]);
        read(fd[0], buff, sizeof(buff));
        close(fd[0]);
        printf("child read this messege from other end : %s\n", buff);
    }

    return 0;
}
/*parent has written from on end
child read this messege from other end : messege from parent*/