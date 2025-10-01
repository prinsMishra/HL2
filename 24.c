 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 24. Write a program to create a message queue and print the key and message queue id.
 
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    key_t key;
    int msgid;

    int fd = open("file1", O_CREAT | O_RDWR, 0666);
     
    close(fd);

    key = ftok("file1", 65);
     

    msgid = msgget(key, 0666 | IPC_CREAT);
    

    printf("key: %d\n", key);
    printf("message queue id: %d\n", msgid);

    return 0;
}
/*key: 1090654929
message queue id: 0*/