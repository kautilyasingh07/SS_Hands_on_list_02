/*
====================================================================================================================================
Name: 04.c
Author : KAUTILYA SINGH
Description : 
      Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.
====================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdint.h>

static __inline__ uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main(){
	
	uint64_t start, end;
	int i;

	start = rdtsc();
	
	for(i = 0; i < 100; i++)
		getppid();
	
	// Take the ending timestamp
	end = rdtsc();
	
	printf("Time taken for 100 getppid() calls: %llu CPU cycles\n",(unsigned long long)(end - start));
	printf("Average per call: %llu CPU cycles\n", (unsigned long long)(end - start) / 100);



	return 0;
}

/*
Output:

Kautilya-Singh:./04
Time taken for 100 getppid() calls: 134726 CPU cycles
Average per call: 1347 CPU cycles

*/
