/*
====================================================================================================================================
Name: 08_b.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          b. SIGINT
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    if (sig == SIGINT) {
        printf("\nSIGINT received! Exiting gracefully...\n");
        exit(0);
    }
}

int main() {
	// Set up handler for SIGINT (Ctrl+C)
	if(signal(SIGINT, handle_sigint) == SIG_ERR){
		perror("Error: cannot handle SIGINT");
		return 1;
	}

	printf("Program running. Press Ctrl+C to trigger SIGINT.\n");
	
	while (1) {
		sleep(1);
	}

    return 0;
}


/*
Output:

Kautilya-Singh:./08_b
Program running. Press Ctrl+C to trigger SIGINT.
^C
SIGINT received! Exiting gracefully...

*/

