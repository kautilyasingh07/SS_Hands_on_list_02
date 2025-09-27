/*
====================================================================================================================================
Name: 10_b.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using sigaction system call to catch the following signals.
          b. SIGINT
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void handle_sigint(int sig, siginfo_t *si, void *ucontext){
	printf("Caught signal %d (SIGINT)\n", sig);
	exit(1);
}

int main(){
	
	struct sigaction action;
	
	memset(&action, 0, sizeof(action));
	action.sa_sigaction = handle_sigint;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;

	if(sigaction(SIGINT, &action, NULL) == -1){
		perror("sigaction");
		return 1;
	}

	printf("Press Ctrl + C to raise a signal...\n");

	for (;;){
		pause();
	}

	return 0;
}

/*
Output:

Kautilya-Singh:./10_b
Press Ctrl + C to raise a signal...
^CCaught signal 2 (SIGINT)

*/

