 /*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 27. Write a program to receive messages from the message queue. 
a. with 0 as a flag 
b. with IPC_NOWAIT as a flag
 
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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
    

     
    msgrcv(id, &m, sizeof(m.text), 1, 0);
    
    printf(" messege q id :%d\n", id);

    printf("Received message: %s\n", m.text);

    return 0;

}
/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 27a.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
 messege q id :2
Received message: Hello Messege queue!*/

/*prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 26.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Message sent to the queue : messege q id :2*/