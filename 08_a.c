/*
====================================================================================================================================
Name: 08_a.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          a. SIGSEGV
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigsegv(int sig) {
	printf("Signal %d caught! Segmentation fault detected.\n", sig);
	exit(EXIT_FAILURE);
}

int main() {
	// Register handler for SIGSEGV
	if (signal(SIGSEGV, handle_sigsegv) == SIG_ERR) {
		perror("Unable to catch SIGSEGV");
		return 1;
	}

	printf("Triggering a segmentation fault intentionally...\n");

	int *invalid_ptr = NULL;
	*invalid_ptr = 42;  // This will cause SIGSEGV

	printf("This message will never be printed.\n");

	return 0;
}



/*
Output:

Kautilya-Singh:./08_a
Triggering a segmentation fault intentionally...
Signal 11 caught! Segmentation fault detected.

*/
