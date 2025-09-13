/*
====================================================================================================================================
Name: 20_receiver.c
Author : KAUTILYA SINGH
Description : 
      Write two programs so that both can communicate by FIFO -Use one way communication.
====================================================================================================================================
*/

#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	
	const char* fifo_path = "myfifo";


	if(mkfifo(fifo_path, 0666) == -1){
		if(errno != EEXIST){
			perror("mkfifo");
			exit(1);
		}
	}

	int fd = open(fifo_path, O_RDONLY);
	if(fd == -1){
		perror("open");
		exit(1);
	}

	char buffer[100];
	read(fd, buffer, sizeof(buffer));
	printf("Message received: %s\n", buffer);

	close(fd);
	return 0;
}


/*
Output:

Kautilya-Singh:./20_receiver 
Message received: HEllo

*/

