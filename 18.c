/*
====================================================================================================================================
Name: 18.c
Author : KAUTILYA SINGH
Description : 
      Write a program to find out total number of directories on the pwd.
            execute ls -l | grep ^d | wc ? Use only dup2.
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	
	int fd1[2];
	int fd2[2];

	if(pipe(fd1) == -1){
		perror("pipe");
		exit(1);
	}

	if(pipe(fd2) == -1){
		perror("pipe");
		exit(1);
	}

	if(fork() == 0){	// child 1: ls -l
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		if(dup2(fd1[1], STDOUT_FILENO) == -1){
			perror("dup2");
			exit(1);
		}

		close(fd1[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(1);
	}

	if(fork() == 0){	// child 2: grep ^d
		close(fd1[1]);
		if(dup2(fd1[0], STDIN_FILENO) == -1){
			perror("dup2");
			exit(1);
		}
		
		close(fd1[0]);

		close(fd2[0]);
		if(dup2(fd2[1], STDOUT_FILENO) == -1){
			perror("dup2");
			exit(1);
		}

		close(fd2[1]);
		execlp("grep", "grep", "^d", NULL);
		perror("execlp");
		exit(1);
	}


	if(fork() == 0){	// child 3: wc
		close(fd2[1]);
		close(fd1[0]);
		close(fd1[1]);
		if(dup2(fd2[0], STDIN_FILENO) == -1){
			perror("dup2");
			exit(1);
		}

		close(fd2[0]);
		execlp("wc", "wc", "-l", NULL);
		perror("execlp");
		exit(1);
	}

	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);
	
	wait(NULL);
	wait(NULL);
	wait(NULL);

	return 0;
}

/*
Output:

Kautilya-Singh:./18
4

*/

