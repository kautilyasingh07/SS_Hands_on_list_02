/*
====================================================================================================================================
Name: 08_g.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          g. SIGPROF (use setitimer system call)
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

static void prof_handler(int sig){

	printf("received SIGPROF. Exiting.\n");
	exit(EXIT_SUCCESS);
}

int main(void){
	struct itimerval tv;
	struct sigaction sa;

	memset(&sa, 0, sizeof sa);
	sa.sa_handler = prof_handler;
	sigemptyset(&sa.sa_mask);
	
	if(sigaction(SIGPROF, &sa, NULL) == -1){
		perror("sigaction");
		return EXIT_FAILURE;
	}

	tv.it_value.tv_sec = 2;
	tv.it_value.tv_usec = 0;
	tv.it_interval.tv_sec = 0;
	tv.it_interval.tv_usec = 0;

	if(setitimer(ITIMER_PROF, &tv, NULL) == -1){
        	perror("setitimer");
        	return EXIT_FAILURE;
	}

	printf("Timer started. Waiting for signals...\n");

	for (;;) { }

	return EXIT_SUCCESS;
}

/*
Output:

Kautilya-Singh:./08_g
Timer started. Waiting for signals...
received SIGPROF. Exiting.

*/
