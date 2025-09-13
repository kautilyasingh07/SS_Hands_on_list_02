/*
====================================================================================================================================
Name: 21_receiver.c
Author : KAUTILYA SINGH
Description : 
      Write two programs so that both can communicate by FIFO -Use two way communications.
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

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
		// open fifo_path1 to read
		int fd1 = open(fifo_path1, O_RDONLY);
		if(fd1 == -1){
			perror("fd1");
			exit(1);
		}
		read(fd1, buffer, sizeof(buffer));
		close(fd1);

		if(strncmp(buffer, "bye", 3) == 0)	break;
		printf("Received: %s\n", buffer);

		// open fifo_path2 to write
		int fd2 = open(fifo_path2, O_WRONLY);
		if(fd2 == -1){
			perror("fd2");
			exit(1);
		}
		printf("Send message: ");
		fgets(buffer, sizeof(buffer), stdin);
		write(fd2, buffer, strlen(buffer)+1);
		close(fd2);

		if(strncmp(buffer, "bye", 3) == 0)	break;
			
	}

	return 0;
}

/*
Output:

Kautilya-Singh:./21_receiver 
press 'bye' to close the chat
Received: Hello

Send message: How are you!

*/
