 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 23. Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
system call with FIFO.
 
Date: 30th sep, 2025.

============================================================================

*/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main(){
    struct rlimit limit;

     
    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Soft limit (max open files): %ld\n", (long)limit.rlim_cur);
    printf("Hard limit (max open files): %ld\n", (long)limit.rlim_max);


    int fd[2];
    pipe(fd);
    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    printf("pipe buffer size: %d\n", pipe_size);

    close(fd[0]);
    close(fd[1]);
    return 0;

}
/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Soft limit (max open files): 1048576
Hard limit (max open files): 1048576
pipe buffer size: 65536*/