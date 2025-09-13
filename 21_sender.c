/*
====================================================================================================================================
Name: 21_sender.c
Author : KAUTILYA SINGH
Description : 
      Write two programs so that both can communicate by FIFO -Use two way communications.
====================================================================================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main(){

	const char* fifo_path1 = "fifo1";
	const char* fifo_path2 = "fifo2";
	char buffer[100];

	if(mkfifo(fifo_path1, 0666) == -1){
		if(errno != EEXIST){
			perror("mkfifo");
			exit(1);
		}
	}

	if(mkfifo(fifo_path2, 0666) == -1){
		if(errno != EEXIST){
			perror("mkfifo");
			exit(1);
		}
	}

	printf("press 'bye' to close the chat\n");
	while(1){
		//Open fifo_path1 for writing
		int fd1 = open(fifo_path1, O_WRONLY);
		if(fd1 == -1){
			perror("fd1");
			exit(1);
		}
		printf("Send message: ");
		fgets(buffer, sizeof(buffer), stdin);
		
		write(fd1, buffer, strlen(buffer)+1);
		close(fd1);

		if(strncmp(buffer, "bye", 3) == 0)	break;

		//open fifo_path2 for reading
		int fd2 = open(fifo_path2, O_RDONLY);
		if(fd2 == -1){
			perror("fd2");
			exit(1);
		}

		read(fd2, buffer, sizeof(buffer));
		close(fd2);

		if(strncmp(buffer, "bye", 3) == 0)	break;
		printf("Received: %s\n", buffer);
	}

	return 0;

}

/*
Output:

Kautilya-Singh:./21_sender
press 'bye' to close the chat
Send message: Hello
Received: How are you!

Send message: bye

*/

