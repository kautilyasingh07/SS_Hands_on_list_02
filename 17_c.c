/*
====================================================================================================================================
Name: 17_c.c
Author : KAUTILYA SINGH
Description : 
      Write a program to execute ls -l | wc.
          c. use fcntl
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	
	int pipefds[2];
	
	if(pipe(pipefds) == -1){
		perror("pipe");
		exit(1);
	}
	
	if(fork() == 0){	// Child one : ls -l
		close(pipefds[0]);
		close(STDOUT_FILENO);
		if(fcntl(pipefds[1], F_DUPFD, STDOUT_FILENO) == -1){
			perror("fcntl");
			exit(1);
		}
		close(pipefds[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(1);
	}

	if(fork() == 0){	//child two : wc
		close(pipefds[1]);
		close(STDIN_FILENO);
		if(fcntl(pipefds[0], F_DUPFD, STDIN_FILENO) == -1){
			perror("fcntl");
			exit(1);
		}
		close(pipefds[0]);
		execlp("wc", "wc", NULL);
		perror("execlp");
		exit(1);
	}
	
	close(pipefds[0]);
	close(pipefds[1]);
	wait(NULL);
	wait(NULL);

	return 0;
}


/*
Output:

Kautilya-Singh:./17_c
    119    1064    8029

*/
