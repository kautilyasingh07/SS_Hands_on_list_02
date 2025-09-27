/*
====================================================================================================================================
Name: 13_a.c
Author : KAUTILYA SINGH
Description : 
      Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call).
      Find out whether the first program is able to catch the signal or not.
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void sig_handler(int s){
	printf("Caught signal %d\n", s);
	fflush(stdout);
}

int main(){
	
	struct sigaction act;
	memset(&act, 0, sizeof act);
	act.sa_handler = sig_handler;
	sigemptyset(&act.sa_mask);

	if(sigaction(SIGSTOP, &act, NULL) == -1){
        	perror("sigaction");
	}

	printf("Process PID = %d\n", getpid());
	printf("Waiting for signals (try sending SIGSTOP)...\n");

	for (;;)
        	pause();

    return EXIT_SUCCESS;
}


