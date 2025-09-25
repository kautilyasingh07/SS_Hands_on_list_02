/*
====================================================================================================================================
Name: 08_d.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          d. SIGALRM (use alarm system call)
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigalrm(int sig){
	printf("Signal %d received: Alarm triggered! Exiting...\n", sig);
	exit(EXIT_FAILURE);
}

int main(){
	if (signal(SIGALRM, handle_sigalrm) == SIG_ERR) {
		perror("Cannot handle SIGALRM");
		return 1;
	}

	printf("Alarm will go off in 2 seconds...\n");
	alarm(2);

	while (1) {
        	sleep(1);
    	}

	return 0;
}

/*
Output:

Kautilya-Singh:./08_d
Alarm will go off in 2 seconds...
Signal 14 received: Alarm triggered! Exiting...

*/
