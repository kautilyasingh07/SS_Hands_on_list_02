/*
====================================================================================================================================
Name: 12.c
Author : KAUTILYA SINGH
Description : 
      Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void){
	pid_t f = fork();
	
	if (f < 0) {
        	perror("fork");
		return EXIT_FAILURE;
	}

	if(f == 0){
		printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
		fflush(stdout);

		sleep(1);

		printf("Child: Sending SIGKILL to parent (PID = %d)\n", getppid());
		fflush(stdout);


		kill(getppid(), SIGKILL);

		sleep(2);

		printf("Child: Now my new parent is PID = %d\n", getppid());
		fflush(stdout);

		for (int i = 1; i <= 5; ++i) {
			printf("Child: Still alive (iteration %d)\n", i);
			fflush(stdout);
			sleep(1);
		}
		return EXIT_SUCCESS;
	}
	else{
		printf("Parent: PID = %d, Child PID = %d\n", getpid(), f);
		fflush(stdout);
		for (;;)
			sleep(1);
	}
	return 0;
}

/*
Output:

Kautilya-Singh:./12
Parent: PID = 13646, Child PID = 13647
Child: PID = 13647, Parent PID = 13646
Child: Sending SIGKILL to parent (PID = 13646)
Killed
Kautilya-Singh:Child: Now my new parent is PID = 2217
Child: Still alive (iteration 1)
Child: Still alive (iteration 2)
Child: Still alive (iteration 3)
Child: Still alive (iteration 4)
Child: Still alive (iteration 5)

*/
