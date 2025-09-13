/*
====================================================================================================================================
Name: 22.c
Author : KAUTILYA SINGH
Description : 
      Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024
#define FIFO_NAME "myfifo"

int main(){

	int fifo_fd;
	char data_buf[BUF_SIZE];


	// Create a named pipe (FIFO)
	if(mkfifo(FIFO_NAME, 0666) == -1 && errno != EEXIST){
		perror("mkfifo");
		exit(EXIT_FAILURE);
	}

	// Open FIFO for reading in non-blocking mode
	fifo_fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
	if (fifo_fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	fd_set rfds;
	struct timeval tv;
	FD_ZERO(&rfds);
	FD_SET(fifo_fd, &rfds);

	// Set timeout to 10 seconds
	tv.tv_sec = 10;
	tv.tv_usec = 0;

	printf("Waiting for input on FIFO '%s' (10 seconds)...\n", FIFO_NAME);

	int sel_ret = select(fifo_fd + 1, &rfds, NULL, NULL, &tv);
	if(sel_ret < 0){
		perror("select");
	}
	else if(sel_ret == 0){
		printf("No data received within 10 seconds.\n");
	}
	else{
		if(FD_ISSET(fifo_fd, &rfds)){
			ssize_t n = read(fifo_fd, data_buf, BUF_SIZE - 1);
			if(n > 0){
				data_buf[n] = '\0';
				printf("Data received: %s\n", data_buf);
			}
			else if(n == 0){
				printf("Writer closed the FIFO.\n");
			}
			else{
				perror("read");
			}
		}
	}

	close(fifo_fd);
	return 0;
}


/*
Output:

Kautilya-Singh:./22
Waiting for input on FIFO 'myfifo' (10 seconds)...
No data received within 10 seconds.

*/
