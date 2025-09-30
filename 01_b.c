/*
====================================================================================================================================
Name: 01_b.c
Author : KAUTILYA SINGH
Description : 
    Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
          b. ITIMER_VIRTUAL
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void alarm_handler(int signum){
	printf("ITIMER_VIRTUAL: Timer expired!\n");
}

int main(){

	struct itimerval timer;
		
	signal(SIGVTALRM, alarm_handler);

	timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
	
	setitimer(ITIMER_VIRTUAL, &timer, NULL);	
	
	//Busy work loop
	while(1){
		for(volatile long i = 0; i < 1000000; i++){
			// busy work in kernel space
			getpid();
		}
	}
	return 0;
}

/*
Output:

Kautilya-Singh:./01_b
ITIMER_VIRTUAL: Timer expired!

*/
