/*

============================================================================

Name : 15.c

Author : Prins Mishra

Description :  15. Write a simple program to send some data from parent to the child process.

 
Date: 30th sep, 2025.

============================================================================

*/ 


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd[2];
    char writebuff[] = "messege from child";
    char buff[100];
    
    pipe(fd);
    pid_t pid = fork();
   
    if(pid >0){
         sleep(4);
        close(fd[1]);
       read(fd[0], buff, sizeof(buff));
        close(fd[0]);
        printf("parent has read  data from other end : %s\n", buff);
    }

    else{
        close(fd[0]);
         write(fd[1], writebuff,  strlen(writebuff)+1);
        
        close(fd[1]);
        printf("child write data from on end :\n");
    }

    return 0;
}
/*child write data from on end :
parent has read  data from other end : messege from child*/