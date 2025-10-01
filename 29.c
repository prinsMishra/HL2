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

   
    k = ftok("file5", 1);
    id = msgget(k, 0666 | IPC_CREAT);

     
    msgctl(id, IPC_RMID, NULL);

    printf("Message queue removed with id :%d\n", id);
    return 0;
}
/*
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 3          prins      666        0            0           

prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 29.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Message queue removed with id :3
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages   */