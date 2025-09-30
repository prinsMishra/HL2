/*

============================================================================

Name : 16.c

Author : Prins Mishra

Description :  16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
 
Date: 30th sep, 2025.

============================================================================

*/ 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd1[2];
    int fd2[2];
    char parentbuff[]= "parent write";
    char childbuff[] = "child write";
    char buff[100];

    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();

    if(pid>0){
        close(fd1[0]);
        close(fd2[1]);
        
        printf("write parent from  one pipe\n");
        write(fd1[1], parentbuff, strlen(parentbuff)+1 );
        close(fd1[1]);
        
        read(fd2[0], buff, sizeof(buff));
        printf("read parent from another pipe : %s\n" ,buff);
        close(fd2[0]);


    }
    else{
        close(fd1[1]);
        close(fd2[0]);
        
       
        read(fd1[0], buff, sizeof(buff));
         printf("read child from one pipe: %s\n", buff);
        close(fd1[0]);

        printf("write child from another pipe\n");
        write(fd2[1], childbuff, strlen(buff)+1);
        close(fd2[1]);

    }
    return 0;
}
/*write parent from  one pipe
read child from one pipe: parent write
write child from another pipe
read parent from another pipe : child write*/