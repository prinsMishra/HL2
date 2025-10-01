/*

============================================================================

Name : 18.c

Author : Prins Mishra

Description : 34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create


============================================================================

*/

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8081
#define BUFFER_SIZE 1024

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    free(arg);  
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);
         
        char *response = "Hello from server 3!";
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, *client_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 5);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_socket = malloc(sizeof(int)); 
        *client_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client_socket);
        pthread_detach(tid); 
    }

    return 0;
}

/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Server listening on port 8081...
Client: Hello from client!*/

/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ cc 33b.c
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
connected
Message sent to server.
Message from server: Hello from server 3!*/