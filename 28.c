 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t k;
    int id;
    struct msqid_ds buf;
 
    k = ftok("file5", 1);
    id = msgget(k, 0666 | IPC_CREAT);
 
    msgctl(id, IPC_STAT, &buf);
    printf("Old permission of the Messege Q: %o\n", buf.msg_perm.mode);

     
    buf.msg_perm.mode = 0600;
 
    printf("Setting Permission to 0600\n");   
    msgctl(id, IPC_SET, &buf);

  
    msgctl(id, IPC_STAT, &buf);
    printf("New permission of Messege Q: %o\n", buf.msg_perm.mode);

    return 0;
}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 28.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Old permission of the Messege Q: 600
Setting Permission to 0600
New permission of Messege Q: 600
*/
