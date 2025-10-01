/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 33. Write a program to communicate between two machines using socket.

============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081
#define BUFFER_SIZE 512

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
 
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
     printf("Socket created \n"); 

    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);
     
    printf("bind\n");
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));       

     
    printf("listen\n");
    listen(server_fd, 1);
         
    printf("Server listening on port %d...\n", PORT);

    
    printf("Connected\n");
    new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen);
       

  
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Message from client: %s\n", buffer);

     
    char *response = "Hello from server!";
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");

    close(new_socket);
    close(server_fd);
    return 0;
}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 33a.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out 
Socket created 
bind
listen
Server listening on port 8081...
Connected
Message from client: Hello from client!
Response sent to client.
*/