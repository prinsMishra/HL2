 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description :  18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
 
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {
         close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        dup2(pipe1[1], 1);  
        close(pipe1[1]);
        execlp("ls", "ls", "-l", NULL);
        
    }
    if (fork() == 0){
        close(pipe1[1]);
        close(pipe2[0]);

        dup2(pipe1[0], 0);   
        dup2(pipe2[1], 1);  
        close(pipe1[0]);
        
       
        close(pipe2[1]);
        execlp("grep", "grep", "^d", NULL);



    }
    if(fork() == 0){
      
        close(pipe1[0]);
        close(pipe2[1]);
        close(pipe1[1]);
        dup2(pipe2[0], 0); 
        close(pipe2[0]);
        execlp("wc", "wc" , NULL);
    }

   
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

     
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}



/*    0       0       0
0 dir */








 