/*
====================================================================================================================================
Name: 14.c
Author : KAUTILYA SINGH
Description : 
Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
====================================================================================================================================
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
	char read_str[100];
	char *write_str = "Hello World from pipe";

	int fd[2];

	if(pipe(fd) == -1){
		perror("pipe");
		return 1;
	}

	write(fd[1], write_str, strlen(write_str)+1);

	read(fd[0], read_str, sizeof(read_str));

	printf("Message received: %s\n", read_str);


	close(fd[0]);
	close(fd[1]);


	return 0;
}


/*
Output:

Kautilya-Singh:./14
Message received: Hello World from pipe

*/
