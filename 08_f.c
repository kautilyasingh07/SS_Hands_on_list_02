/*
====================================================================================================================================
Name: 08_f.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          f. SIGVTALRM (use setitimer system call)
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

static void on_vtalrm(int signo){
	(void)signo;
	printf("received SIGVTALRM. Exiting.\n");
	exit(EXIT_SUCCESS);
}

int main(void){
	struct itimerval timer;
	struct sigaction sa;

	memset(&sa, 0, sizeof sa);
	sa.sa_handler = on_vtalrm;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGVTALRM, &sa, NULL) == -1){
		perror("sigaction");
		return EXIT_FAILURE;
	}

	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 0;

	if(setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1){
        	perror("setitimer");
        	return EXIT_FAILURE;
	}

	printf("Timer started. Waiting for signals...\n");

	for (;;) { }

	return EXIT_SUCCESS;
}

/*
Output:

Kautilya-Singh:./08_f
Timer started. Waiting for signals...
received SIGVTALRM. Exiting.

*/
