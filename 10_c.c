/*
====================================================================================================================================
Name: 10_c.c
Author : KAUTILYA SINGH
Description : 
      Write a separate program using sigaction system call to catch the following signals.
          c. SIGFPE
====================================================================================================================================
*/


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void fpe_handler(int sig, siginfo_t *si, void *ctx){
	printf("Caught signal %d (SIGFPE)\n", sig);

	switch(si->si_code){
		case FPE_INTDIV:
			printf("Integer divide by zero\n");
			break;
		case FPE_INTOVF:
			printf("Integer overflow\n");
			break;
		case FPE_FLTDIV:
			printf("Floating-point divide by zero\n");
			break;
		case FPE_FLTOVF:
			printf("Floating-point overflow\n");
			break;
		case FPE_FLTUND:
			printf("Floating-point underflow\n");
			break;
		case FPE_FLTRES:
			printf("Floating-point inexact result\n");
			break;
		case FPE_FLTINV:
			printf("Floating-point invalid operation\n");
			break;
		case FPE_FLTSUB:
			printf("Subscript out of range\n");
			break;
		default:
			printf("Unknown FPE code %d\n", si->si_code);
			break;
	}

	exit(1);
}

int main(){
	
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = fpe_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	if(sigaction(SIGFPE, &sa, NULL) == -1){
		perror("sigaction");
		return 1;
	}

	volatile int m = 10;
	volatile int n = 0;
	volatile int r = m / n;

	printf("Unreachable Code.");

	return 0;
}


/*
Output:

Kautilya-Singh:./10_c
Caught signal 8 (SIGFPE)
Integer divide by zero

*/

