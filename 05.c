/*
====================================================================================================================================
Name: 05.c
Author : KAUTILYA SINGH
Description : 
      Write a program to print the system limitation of
          a. maximum length of the arguments to the exec family of functions.
          b. maximum number of simultaneous process per user id.
          c. number of clock ticks (jiffy) per second.
          d. maximum number of open files
          e. size of a page
          f. total number of pages in the physical memory
          g. number of currently available pages in the physical memory.
====================================================================================================================================
*/

#include<stdio.h>
#include<stdint.h>
#include<unistd.h>

int main(){
  long val;

	val = sysconf(_SC_ARG_MAX);
	printf("a. Maximum length of arguments to exec family: %ld\n", val);

	val = sysconf(_SC_CHILD_MAX);
	printf("b. Maximum number of simultaneous processes per user id: %ld\n", val);

	val = sysconf(_SC_CLK_TCK);
	printf("c. Number of clock ticks (jiffy) per second: %ld\n", val);

	val = sysconf(_SC_OPEN_MAX);
	printf("d. Maximum number of open files: %ld\n", val);

	val = sysconf(_SC_PAGESIZE);
	printf("e. Size of a page: %ld bytes\n", val);

	val = sysconf(_SC_PHYS_PAGES);
	printf("f. Total number of pages in physical memory: %ld\n", val);

	val = sysconf(_SC_AVPHYS_PAGES);
	printf("g. Number of currently available pages in physical memory: %ld\n", val);


	return 0;
}



/*
Output:

Kautilya-Singh:./05
a. Maximum length of arguments to exec family: 2097152
b. Maximum number of simultaneous processes per user id: 61524
c. Number of clock ticks (jiffy) per second: 100
d. Maximum number of open files: 1024
e. Size of a page: 4096 bytes
f. Total number of pages in physical memory: 3996421
g. Number of currently available pages in physical memory: 2583910

*/

