/*
====================================================================================================================================
Name: 08_c.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using signal system call to catch the following signals.
          c. SIGFPE
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigfpe(int sig){
	printf("Caught signal %d: Floating Point Exception occurred! Exiting...\n", sig);
	exit(EXIT_FAILURE);
}

int main() {
	
	if(signal(SIGFPE, handle_sigfpe) == SIG_ERR){
		perror("Unable to catch SIGFPE");
		return 1;
	}

	printf("Triggering a divide-by-zero operation...\n");

	int numerator = 10;
	int denominator = 0;
	
	int result = numerator / denominator; // Causes SIGFPE
	(void)result;  // Suppress unused variable warning

	printf("This line will never be executed.\n");

	return 0;
}

/*
Output:

Kautilya-Singh:./08_c
Triggering a divide-by-zero operation...
Caught signal 8: Floating Point Exception occurred! Exiting...

*/

