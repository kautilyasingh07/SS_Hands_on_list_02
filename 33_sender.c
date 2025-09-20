/*
====================================================================================================================================
Name: 33_sender.c
Author : KAUTILYA SINGH
Description : 
    Write a program to communicate between two machines using socket.
      
====================================================================================================================================
*/

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
	int sock = 0;
	struct sockaddr_in serv_addr;
	char buffer[BUF_SIZE] = {0};
	char *hello = "Hello from Client";

	sock = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	send(sock, hello, strlen(hello), 0);
	printf("Message sent to server\n");

	read(sock, buffer, BUF_SIZE);
	printf("Server: %s\n", buffer);

	close(sock);
	return 0;
}

/*
Output:

Kautilya-Singh:./33_sender
Message sent to server
Server: Hello from Server

*/
