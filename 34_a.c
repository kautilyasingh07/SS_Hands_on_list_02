/*
====================================================================================================================================
Name: 34_a.c
Author : KAUTILYA SINGH
Description : 
      Write a program to create a concurrent server.
            a. use fork
      
====================================================================================================================================
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 8080
#define BACKLOG 5
#define BUF_SIZE 1024

void sigchld_handler(int signo) {
  (void)signo;
  while (waitpid(-1, NULL, WNOHANG) > 0)
    ;
}

int main() {
	int sockfd, new_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t sin_size;
	char buffer[BUF_SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);


	int opt = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	
	memset(&(server_addr.sin_zero), '\0', 8);

	bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));

	listen(sockfd, BACKLOG);

	signal(SIGCHLD, sigchld_handler);

	printf("Server listening on port %d...\n", PORT);

	while(1){
		sin_size = sizeof(struct sockaddr_in);
		new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);

		printf("Server: got connection from %s\n", inet_ntoa(client_addr.sin_addr));
		
		if (!fork()) {
			close(sockfd);
			memset(buffer, 0, BUF_SIZE);
			
			int n = recv(new_fd, buffer, BUF_SIZE - 1, 0);
			if (n > 0) {
				printf("Received: %s\n", buffer);
				send(new_fd, "Hello from server!\n", 19, 0);
			}
			close(new_fd);
			exit(0);
		}
		close(new_fd);
	}
	return 0;
}

/*
Output:

Kautilya-Singh:./34_a
Server listening on port 8080...
Server: got connection from 127.0.0.1
Received: Hello from Client
Server: got connection from 127.0.0.1
Received: Hello from Client

*/

