/*
====================================================================================================================================
Name: 11.c
Author : KAUTILYA SINGH
Description : 
      Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	struct sigaction ignore_action, default_action;

	memset(&ignore_action, 0, sizeof(ignore_action));
	ignore_action.sa_handler = SIG_IGN;
	sigemptyset(&ignore_action.sa_mask);

	if(sigaction(SIGINT, &ignore_action, NULL) == -1){
        	perror("sigaction");
        	return 1;
	}

	printf("SIGINT ignored. Press Ctrl+C...\n");
	
	sleep(5);

	memset(&default_action, 0, sizeof(default_action));
	default_action.sa_handler = SIG_DFL;
	sigemptyset(&default_action.sa_mask);

	if(sigaction(SIGINT, &default_action, NULL) == -1){
        	perror("sigaction");
        	return 1;
	}

	printf("SIGINT restored to default. Press Ctrl+C again...\n");

	for (;;)
        	pause();

	return 0;
}

/*
Output:

Kautilya-Singh:./11
SIGINT ignored. Press Ctrl+C...
^C^C^CSIGINT restored to default. Press Ctrl+C again...
^C

*/
