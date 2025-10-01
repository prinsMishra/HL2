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

    
    
    int rfd = open("fifo1", O_RDONLY);
    int wfd = open("fifo2", O_WRONLY);
     

    char buffer[100];
    int n;

     
        n = read(rfd, buffer, sizeof(buffer));
         

        printf("Messege Received: %.*s", n, buffer);
         
        

        n = read(0, buffer, sizeof(buffer));
         

        write(wfd, buffer, n);
    

    close(wfd);
    close(rfd);
    return 0;
}
/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Messege Received: hello
hii*/
