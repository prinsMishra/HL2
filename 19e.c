/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description :  19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
 
Date: 30th sep, 2025.

============================================================================

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    mkfifo("myfifofile4", S_IFIFO | 0666);
     
    return 0;
}
/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ls -l myfifofile4
prw-rw-r-- 1 prins prins 0 Sep 30 19:23 myfifofile4
*/