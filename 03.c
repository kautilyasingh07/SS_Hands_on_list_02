/*
====================================================================================================================================
Name: 03.c
Author : KAUTILYA SINGH
Description : 
Write a program to set (any one) system resource limit. Use setrlimit system call.
====================================================================================================================================
*/


#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit limit;

	getrlimit(RLIMIT_NOFILE, &limit);
	printf("Soft limit: %ld, Hard limit: %ld\n", limit.rlim_cur, limit.rlim_max);
	
	// Increase soft limit 
	limit.rlim_cur = 2048;
	setrlimit(RLIMIT_NOFILE, &limit);

	getrlimit(RLIMIT_NOFILE, &limit);
	printf("After change: soft limit: %ld, Hard limit: %ld\n", limit.rlim_cur, limit.rlim_max);

	return 0;

}


/*
Output:

Kautilya-Singh:./03
Soft limit: 1024, Hard limit: 1048576
After change: soft limit: 2048, Hard limit: 1048576

*/

