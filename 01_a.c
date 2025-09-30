/*
====================================================================================================================================
Name: 01_a.c
Author : KAUTILYA SINGH
Description : 
    Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
          a. ITIMER_REAL
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void alarm_handler(int signum){
	printf("ITIMER_REAL : Timer expired!\n");
}
int main(){
	
	struct itimerval real_timer;

	//register signal handler for SIGALRM 
	signal(SIGALRM, alarm_handler);
	
	real_timer.it_value.tv_sec = 10;
	real_timer.it_value.tv_usec = 0;
	real_timer.it_interval.tv_sec = 0;
	real_timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &real_timer, NULL);
	
	//pause until we get signal
	pause();

	return 0;
}


/*
Output:

Kautilya-Singh:./01_a
ITIMER_REAL : Timer expired!

*/

