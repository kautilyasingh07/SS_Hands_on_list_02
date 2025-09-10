/*
====================================================================================================================================
Name: 16.c
Author : KAUTILYA SINGH
Description : 
Write a program to send and receive data from parent to child vice versa. Use two way communication.
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	int parent_to_child[2];	// Pipe 1: Parent writes, Child reads
	int child_to_parent[2];	// Pipe 2: Child writes, Parent reads
	
	if(pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1){
		perror("pipe");
		exit(1);
	}
	
	pid_t pid = fork();
	
	if(pid <0){
		perror("fork");
		exit(1);
	}
	else if(pid == 0){
		//Child process
		close(parent_to_child[1]); // close read end
		close(child_to_parent[0]); // close write end

		char *child_msg = "Hello Parent!";
		write(child_to_parent[1], child_msg, strlen(child_msg)+1);
		printf("Child sent: %s\n", child_msg);

		char parent_msg[100];
		read(parent_to_child[0], parent_msg, sizeof(parent_msg));
		printf("Child received: %s\n", parent_msg);

		close(parent_to_child[0]);
		close(child_to_parent[1]);
	}
	else{
		//Parent process
		close(parent_to_child[0]); // close read end of parent_to_child
		close(child_to_parent[1]); // close write end of child_to_parent
		
		char *parent_msg = "Hello Child";
		write(parent_to_child[1], parent_msg, strlen(parent_msg)+1);
		printf("Parent sent: %s\n", parent_msg);

		char child_msg[100];
		read(child_to_parent[0], child_msg, sizeof(child_msg));
		printf("Parent received: %s\n", child_msg);

		close(parent_to_child[1]);
		close(child_to_parent[0]);
	}

	return 0;
}


/*
Output:

Kautilya-Singh:./16
Parent sent: Hello Child
Child sent: Hello Parent!
Child received: Hello Child
Parent received: Hello Parent!

*/

