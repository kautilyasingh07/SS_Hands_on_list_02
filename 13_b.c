/*
====================================================================================================================================
Name: 13_b.c
Author : KAUTILYA SINGH
Description : 
      Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call).
      Find out whether the first program is able to catch the signal or not.
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *end;
	errno = 0;
	long val = strtol(argv[1], &end, 10);
	
	if(errno || *end != '\0' || val <= 0){
		fprintf(stderr, "Invalid PID: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	pid_t pid = (pid_t)val;
	if(kill(pid, SIGSTOP) == -1){
		perror("kill");
		return EXIT_FAILURE;
	}

	printf("Sent SIGSTOP to process %ld\n", (long)pid);
	return EXIT_SUCCESS;
}

/*
Output:

Kautilya-Singh:./13_a
sigaction: Invalid argument
Process PID = 13804
Waiting for signals (try sending SIGSTOP)...

[1]+  Stopped                 ./13_a


Kautilya-Singh:./13_b 13804
Sent SIGSTOP to process 13804
Kautilya-Singh:


*/

