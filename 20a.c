/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description :  20. Write two programs so that both can communicate by FIFO -Use one way communication.
 
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>

int main(){
    mkfifo("fifo", 0644);
    int fd;
    char buffer[100];
    int n;

    fd = open("fifo", O_WRONLY);

    printf("Enter some messege to pipe\n");

    n = read(0,buffer, sizeof(buffer));


 
    write(fd,buffer,n);
     

    close(fd);
    return 0;

}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out 
Enter some messege to pipe
hello*/