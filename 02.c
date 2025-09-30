/*
====================================================================================================================================
Name: 02.c
Author : KAUTILYA SINGH
Description : 
Write a program to print the system resource limits. Use getrlimit system call.
====================================================================================================================================
*/

#include<stdio.h>
#include<sys/resource.h>


void print_limit(const char *name, int resource){	
	struct rlimit limit;

	if(getrlimit(resource, &limit) != 0){
		perror("getrlimit failed");
	}

	printf("%-20s : ", name);

	if(limit.rlim_cur == RLIM_INFINITY)
		printf("Current = unlimited, ");
	else
		printf("Current = %ld ", (long)limit.rlim_cur);
	
	if(limit.rlim_max = RLIM_INFINITY)
		printf("Max = unlimited \n");
	else
		printf("Max = %ld \n ", (long)limit.rlim_max);
}

int main(){
	printf("========== System resource limits ============\n");
	
	print_limit("CPU time ", RLIMIT_CPU);
	print_limit("Maximum file size", RLIMIT_FSIZE);
	print_limit("Data segment", RLIMIT_DATA);
	print_limit("Stack size", RLIMIT_STACK);
	print_limit("Core dump size", RLIMIT_CORE);
	print_limit("Resident set size", RLIMIT_RSS);
 	print_limit("Processes", RLIMIT_NPROC);
 	print_limit("Open files", RLIMIT_NOFILE);
 	print_limit("Locked memory", RLIMIT_MEMLOCK);
 	print_limit("Virtual memory", RLIMIT_AS);
	print_limit("File locks", RLIMIT_LOCKS);
	print_limit("Pending signals", RLIMIT_SIGPENDING);
 	print_limit("Message queue bytes", RLIMIT_MSGQUEUE);
	print_limit("Nice priority", RLIMIT_NICE);
	print_limit("Realtime priority", RLIMIT_RTPRIO);
	print_limit("Realtime CPU time", RLIMIT_RTTIME);

	return 0;
}


/*
Output:

Kautilya-Singh:./02
========== System resource limits ============
CPU time             : Current = unlimited, Max = unlimited 
Maximum file size    : Current = unlimited, Max = unlimited 
Data segment         : Current = unlimited, Max = unlimited 
Stack size           : Current = 8388608 Max = unlimited 
Core dump size       : Current = 0 Max = unlimited 
Resident set size    : Current = unlimited, Max = unlimited 
Processes            : Current = 61524 Max = unlimited 
Open files           : Current = 1024 Max = unlimited 
Locked memory        : Current = 2046164992 Max = unlimited 
Virtual memory       : Current = unlimited, Max = unlimited 
File locks           : Current = unlimited, Max = unlimited 
Pending signals      : Current = 61524 Max = unlimited 
Message queue bytes  : Current = 819200 Max = unlimited 
Nice priority        : Current = 0 Max = unlimited 
Realtime priority    : Current = 0 Max = unlimited 
Realtime CPU time    : Current = unlimited, Max = unlimited 

*/

