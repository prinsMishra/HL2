#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
   
    printf("connected\n") ;
    sock = socket(AF_INET, SOCK_STREAM, 0);
       
     
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
     
    inet_pton(AF_INET, "SERVER_IP_HERE", &serv_addr.sin_addr);
        

    
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
       

     
    char *message = "Hello from client!";
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");

    
    read(sock, buffer, BUFFER_SIZE);
    printf("Message from server: %s\n", buffer);

    close(sock);
    return 0;
}
/*
rins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 33b.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
connected
Message sent to server.
Message from server: Hello from server!*/