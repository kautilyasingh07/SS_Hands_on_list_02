/*
====================================================================================================================================
Name: 10_a.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using sigaction system call to catch the following signals.
          a. SIGSEGV
====================================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void segv_catcher(int signo, siginfo_t *si, void *ctx){
	printf("Caught signal %d (SIGSEGV)\n", signo);
	printf("Fault address: %p\n", si->si_addr);
	exit(1);
}

int main() {
	struct sigaction sa = {0};
	sa.sa_sigaction = segv_catcher;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        	perror("sigaction");
        	return 1;
	}

	printf("Triggering a segmentation fault...\n");
	volatile int *bad = (int *)(uintptr_t)6767;
	*bad = 123;
	printf("This will never be printed.\n");

	return 0;
}

/*
Output:

Kautilya-Singh:./10_a
Triggering a segmentation fault...
Caught signal 11 (SIGSEGV)
Fault address: 0x1a6f

*/

