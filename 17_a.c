/*
====================================================================================================================================
Name: 17_a.c
Author : KAUTILYA SINGH
Description : 
      Write a program to execute ls -l | wc.
          a. use dup
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

	if(fork() == 0){	// First child : run ls -l
		close(pipefds[0]);	//close read, i.e no need to read
		close(STDOUT_FILENO);
		if(dup(pipefds[1]) == -1){
			perror("dup");
			exit(1);
		}

		close(pipefds[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(1);
	}
	
	if(fork() == 0){	// Second child : run wc
		close(pipefds[1]);	//close write
		close(STDIN_FILENO);
		if(dup(pipefds[0]) == -1){
			perror("dup");
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

Kautilya-Singh:./17_a
    119    1064    8029

*/
