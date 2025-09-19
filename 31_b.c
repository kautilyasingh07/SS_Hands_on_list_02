/*
====================================================================================================================================
Name: 31_b.c
Author : KAUTILYA SINGH
Description : 
Write a program to create a semaphore and initialize value to the semaphore.
      b. create a counting semaphore
      
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

union senum{
	int val;
	struct semid_ds *buf;
	unsigned short *arr;
};

int main(){
	key_t key;
	int semid;

	key = ftok("countsem", 75);

	semid = semget(key, 1, IPC_CREAT | 0666);
	
	//initialize counting semaphore with count 3
	union senum arg;
	arg.val = 3;

	if(semctl(semid, 0, SETVAL, arg) == -1){
		perror("semctl");
		exit(EXIT_FAILURE);
	}

	printf("Counting semaphore creating with id: %d, initial value = 3\n", semid);

	return 0;
}

/*
Output:

Kautilya-Singh:./31_b
Counting semaphore creating with id: 1, initial value = 3

*/

