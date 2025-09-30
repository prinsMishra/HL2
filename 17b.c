    /*

============================================================================

Name : 15.c

Author : Prins Mishra

Description :  17b. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
 
Date: 30th sep, 2025.

============================================================================

*/
 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); 

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        execlp("wc", "wc", NULL);
      
    } 
    else {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
         
    }

    return 0;
}

/*     32     281    1528
      lines    words char*/