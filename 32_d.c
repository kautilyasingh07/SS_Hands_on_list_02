/*
====================================================================================================================================
Name: 32_d.c
Author : KAUTILYA SINGH
Description : 
Write a program to implement semaphore to protect any critical section.
        d. remove the created semaphore
      
====================================================================================================================================
*/

#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	sem_t *sem;

	sem = sem_open("/mysem", O_CREAT, 0644, 1);

	printf("Named semaphore created\n");
	
	sem_close(sem);
	sem_unlink("/mysem");

	printf("Named semaphore removed\n");
	
	return 0;
}

/*
Output:

Kautilya-Singh:./32_d
Named semaphore created
Named semaphore removed

*/

