 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description :  22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
 
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include <sys/select.h>

int main(){
    mkfifo("fifo", 0644);
    int fd;
    char buffer[100];
    int n;

    fd = open("fifo", O_RDONLY | O_NONBLOCK);
    printf("waiting for 10 sec \n");

    fd_set readfds;
    struct timeval tv;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    tv.tv_sec = 10;    
    tv.tv_usec = 0;

    int retval = select(fd + 1, &readfds, NULL, NULL, &tv);

    

     
    if(retval == 0){
        printf("No data received timeout\n");
    }
    else{
    
        n = read(fd,buffer, sizeof(buffer));
        if(n>0){

   
       printf("Messege received from pipe : %.*s\n", n, buffer);
    }
    }

     
    
    close(fd);
    return 0;




}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
waiting for 10 sec 
Messege received from pipe : hello*/

/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ echo "hello" > fifo*/