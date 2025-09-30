#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>

void alarm_handler(int signum){
	printf("ITIMER_PROF: Timer expired!\n");
}

int main(){
	
	struct itimerval timer;

	signal(SIGPROF, alarm_handler);

	timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
	
	setitimer(ITIMER_PROF, &timer, NULL);

	// Mixed workload to generate user + kernel CPU time
	while (1) {
		for (volatile long i = 0; i < 1000000; i++)
			if (i % 2 == 0) {
				getpid();
      
			}
	}
	
	return 0;
}

/*
Output:

Kautilya-Singh:./01_c
ITIMER_PROF: Timer expired!

*/
