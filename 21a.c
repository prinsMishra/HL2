/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description :  21. Write two programs so that both can communicate by FIFO -Use two way communications.
 
Date: 30th sep, 2025.

============================================================================

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
 

int main() {
    mkfifo("fifo1",0644);
    mkfifo("fifo2", 0644);

    int wfd = open("fifo1", O_WRONLY);
    

    int rfd = open("fifo2",O_RDONLY);

    
    char buffer[100];
    int n;

     
        printf(" Enter message: \n");
        

        n = read(0, buffer, sizeof(buffer));  
         

        write(wfd, buffer, n);
        

       
        n = read(rfd, buffer, sizeof(buffer));
        

        printf("Messege Received: %.*s", n, buffer);
        
    

    close(wfd);
    close(rfd);
    return 0;
}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 21a.c 
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out 
 Enter message: 
hello
Messege Received: hii
*/