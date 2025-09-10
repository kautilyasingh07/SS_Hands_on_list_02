/*
====================================================================================================================================
Name: 17_b.c
Author : KAUTILYA SINGH
Description : 
      Write a program to execute ls -l | wc.
          b. use dup2
====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	int pipefds[2];

	if(pipe(pipefds) == -1){
		perror("pipe");
		exit(1);
	}

	if(fork() == 0){	// first child : run ls -l
		close(pipefds[0]);	//close read
		if(dup2(pipefds[1], STDOUT_FILENO) == -1){
			perror("dup2");
			exit(1);
		}

		close(pipefds[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(1);
	}
	
	if(fork() == 0){	//Second child : run wc
		close(pipefds[1]);	// close write
		if(dup2(pipefds[0], STDIN_FILENO) == -1){
			perror("dup2");
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

Kautilya-Singh:./17_b
    119    1064    8029

*/
