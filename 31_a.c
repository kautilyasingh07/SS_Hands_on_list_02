/*
====================================================================================================================================
Name: 31_a.c
Author : KAUTILYA SINGH
Description : 
Write a program to create a semaphore and initialize value to the semaphore.
      a. create a binary semaphore
      
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *arr;
};

int main(){
	key_t key;
	int semid;

	key = ftok("binsem", 65);

	semid = semget(key, 1, IPC_CREAT | 0666);

	// Initialize binary semaphore to 1 (unlocked state)
	union semun arg;
	arg.val = 1;

	if(semctl(semid, 0, SETVAL, arg) == -1){
		perror("semctl");
		exit(EXIT_FAILURE);
	}

	printf("Counting semaphore created with ID: %d, initial value = 1\n", semid);
	return 0;
}

/*
Output:

Kautilya-Singh:./31_a
Counting semaphore created with ID: 0, initial value = 1

*/

