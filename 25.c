 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
 
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    key_t k;
    int id;
    struct msqid_ds buf;

    int f = open("f2", O_CREAT | O_RDWR, 0666);
    close(f);

    k = ftok("f2", 1);
    

    id = msgget(k, IPC_CREAT | 0666);
   

    msgctl(id, IPC_STAT, &buf);

    printf("perm = %o\n", buf.msg_perm.mode);
    printf("uid = %d\n", buf.msg_perm.uid);
    printf("gid = %d\n", buf.msg_perm.gid);
    printf("last snd = %ld\n", buf.msg_stime);
    printf("last rcv = %ld\n", buf.msg_rtime);
    printf("last change = %ld\n", buf.msg_ctime);
    printf("no of msg = %d\n", (int)buf.msg_qnum);
    printf("max bytes = %d\n", (int)buf.msg_qbytes);
    printf("snd pid = %d\n", buf.msg_lspid);
    printf("rcv pid = %d\n", buf.msg_lrpid);

    return 0;
}
/*
perm = 666
uid = 1000
gid = 1000
last snd = 0
last rcv = 0
last change = 1759300105
no of msg = 0
max bytes = 16384
snd pid = 0
rcv pid = 0
*/