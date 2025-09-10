/*
====================================================================================================================================
Name: 15.c
Author : KAUTILYA SINGH
Description : 
Write a simple program to send some data from parent to the child process
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){

	int fd[2];	// fd[0] = read end, fd[1] = write end
	pid_t pid;
	char *write_msg = "Hello from pipe!";
	char read_msg[100];

	if(pipe(fd) == -1){
		perror("pipe");
		return 1;
	}


	pid = fork();

	if(pid < 0){
		perror("pid");
		return 1;
	}

	else if(pid > 0){
		//parent process : read message
		close(fd[0]);
		write(fd[1], write_msg, strlen(write_msg)+1);
		close(fd[1]);
	}
	else{	
		//child process : write message
		close(fd[1]);
		read(fd[0], read_msg, sizeof(read_msg));
		printf("Read message: %s\n", read_msg);
		close(fd[0]);
	}

	return 0;
}



/*
Output:

Kautilya-Singh:./15
Read message: Hello from pipe!

*/
