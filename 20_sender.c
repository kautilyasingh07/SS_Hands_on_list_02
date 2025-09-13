/*
====================================================================================================================================
Name: 20_sender.c
Author : KAUTILYA SINGH
Description : 
      Write two programs so that both can communicate by FIFO -Use one way communication.
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	const char *fifo_path = "myfifo";
	
	if(mkfifo(fifo_path, 0666) == -1){
		if(errno != EEXIST){	// ignore "already exists"
			perror("mkfifo");
			exit(1);
		}
	}

	int fd = open(fifo_path, O_WRONLY);
	if(fd == -1){
		perror("open");
		exit(1);
	}

	char msg[100];
	printf("Enter a message: \n");
	fgets(msg, sizeof(msg), stdin);
	
	write(fd, msg, sizeof(msg));
	close(fd);

	return 0;
}


/*
Output:

Kautilya-Singh:./20_sender
Enter a message:
HEllo

*/

