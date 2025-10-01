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

    fd = open("fifo", O_RDONLY);

    printf("messege from  pipe\n");

     
     
    n = read(fd,buffer, sizeof(buffer));

   
    printf("Messege received from pipe : %.*s\n", n, buffer);
     
    
    close(fd);
    return 0;




}
/*
rins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
messege from  pipe
heMessege received from pipe : hello
*/