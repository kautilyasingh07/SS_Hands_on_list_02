/*
====================================================================================================================================
Name: 09.c
Author : KAUTILYA SINGH
Description : 
      Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

	struct sigaction act;
	
	puts("Step 1: SIGINT is being ignored (press Ctrl+C now if you want)...");
	act.sa_handler = SIG_IGN;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	
	if(sigaction(SIGINT, &act, NULL) == -1){
        	perror("sigaction");
        	exit(EXIT_FAILURE);
	}

	sleep(5);

	puts("\nStep 2: Restoring default SIGINT behavior.");
	act.sa_handler = SIG_DFL;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	
	if(sigaction(SIGINT, &act, NULL) == -1){
		perror("sigaction");
        	exit(EXIT_FAILURE);
	}

    sleep(5);

    puts("\nProgram exiting normally (if Ctrl+C was not pressed).");
    return 0;
}



/*
Output:

Kautilya-Singh:./09
Step 1: SIGINT is being ignored (press Ctrl+C now if you want)...
^C^C^C^C^C^C^C
Step 2: Restoring default SIGINT behavior.
^C

*/

