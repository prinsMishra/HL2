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
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd); 

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD, 0);
        close(fd[0]);
        execlp("wc", "wc", NULL);
         
    } 
    else {
        close(fd[0]);
        close(1);
        fcntl(fd[1], F_DUPFD, 1);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
       
    }

    return 0;
}
/*   33     290    1578 */