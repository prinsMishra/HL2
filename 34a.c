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
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8081
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);
       // write(client_socket, buffer, strlen(buffer)); 

        char *response = "Hello from server 2!";
        send(client_socket, response, strlen(response), 0);


    }

    close(client_socket);
    exit(0); 
}

int main() {
    int server_fd, client_socket;
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
        client_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

        if (fork() == 0) { 
            close(server_fd); 
            handle_client(client_socket);
        } else {
            close(client_socket); 
        }
    }

    return 0;
}
/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
Server listening on port 8081...
Client: Hello from client!
^C*/

/*
prins@prins-HP-Laptop-15-da0xxx:~/linux/HL2$ ./a.out
connected
Message sent to server.
Message from server: Hello from server 2!
*/