/*
====================================================================================================================================
Name: 08_e.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          e. SIGALRM (use setitimer system call)
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

static void handler(int sig){
	(void)sig;
	printf("received SIGALRM. Exiting.\n");
	exit(EXIT_SUCCESS);
}

int main(void) {
	
	struct itimerval tv;
	struct sigaction sa;
	
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGALRM, &sa, NULL) == -1) {
        	perror("sigaction");
       		return EXIT_FAILURE;
	}

	tv.it_value.tv_sec = 2;
	tv.it_value.tv_usec = 10;
	tv.it_interval.tv_sec = 0;
	tv.it_interval.tv_usec = 0;

	if (setitimer(ITIMER_REAL, &tv, NULL) == -1) {
        	perror("setitimer");
        	return EXIT_FAILURE;
	}

	printf("Timer started. Waiting for signals...\n");
	pause();

	return EXIT_SUCCESS;
}


/*
Output:

Kautilya-Singh:./08_e
Timer started. Waiting for signals...
received SIGALRM. Exiting.

*/

