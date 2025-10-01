
/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 30th sep, 2025.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

 #define SIZE 256

int main() {

    key_t key = ftok("sharedmem", 65); 
    int shmid;
    

     
    shmid = shmget(key, SIZE, 0666 | IPC_CREAT);
    
     printf("%d\n",shmid);
    char *pointer1 = (char*) shmat(shmid, NULL, 0);
    

    
    strcpy(pointer1, "Written in Shared Memory with pointer1!");
    printf("Data : %s\n", pointer1);

  
    char *pointer2 = (char*) shmat(shmid, NULL, SHM_RDONLY);
    
    //strcpy(pointer2, "Written in Shared Memory with pointer2!");
    printf("Read-only mode : %s\n", pointer2);

    
      

   
    shmdt(pointer2);

     
   shmdt(pointer1);
 
    shmctl(shmid, IPC_RMID, NULL);

   printf("Shared memory detached and removed.\n");
    return 0;
}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 30.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Data : Written in Shared Memory with pointer1!
Segmentation fault (core dumped)*/

/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 30.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Data : Written in Shared Memory with pointer1!
Read-only mode : Written in Shared Memory with pointer1!
Shared memory detached and removed.
*/