/*
====================================================================================================================================
Name: 23.c
Author : KAUTILYA SINGH
Description : 
      Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	long max_files = sysconf(_SC_OPEN_MAX);
	if(max_files == -1){
		perror("sysconf(_SC_OPEN_MAX)");
		exit(EXIT_FAILURE);
	}

	printf("Maximum number of files a process can open: %ld\n", max_files);
	
	int fd[2];

	if(pipe(fd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	long pipe_size = fpathconf(fd[0], _PC_PIPE_BUF);

	if(pipe_size == -1){
		perror("fpathconf");
		exit(EXIT_FAILURE);
	}

	printf("size of the pipe(circular buffer): %ld\n", pipe_size);


	return 0;
}


/*
Output:

Kautilya-Singh:./23
Maximum number of files a process can open: 1024
size of the pipe(circular buffer): 4096

*/
