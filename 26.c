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
#include <string.h>

struct msgbuf {
    long type;
    char text[50];
};

int main() {
    key_t k;
    int id;
    struct msgbuf m;

    k = ftok("f4", 1);
    id = msgget(k, 0666 | IPC_CREAT);

    m.type = 1;
    strcpy(m.text, "Hello Messege queue!");

    msgsnd(id, &m, sizeof(m.text), 0);

    printf("Message sent to the queue : messege q id :%d\n", id);
     
    return 0;
}
/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Message sent to the queue : messege q id :2
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x410212d1 0          prins      666        0            0           
0x0102134b 1          prins      666        0            0           
0xffffffff 2          prins      666        100          2           
*/