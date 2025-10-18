/*
====================================================================================================================================
Name: 30.c
Author : KAUTILYA SINGH
Description : 
Write a program to create a shared memory.
      a. write some data to the shared memory
      b. attach with O_RDONLY and check whether you are able to overwrite.
      c. detach the shared memory
      d. remove the shared memory
====================================================================================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>

#define SHM_SIZE 1024

int main(){
	
	key_t key;
	int shmid;
	char *ptr;

	//Generate key
	key = ftok("msgqprog", 65);

	// Create shared memory segment
	shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
	
	printf("Shared memory created with ID: %d\n", shmid);
	
	shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
	if(shmid == -1){
		perror("shmid");
		exit(EXIT_FAILURE);
	}
	
	// Attach with read-write and write data
	ptr = (char*) shmat(shmid, NULL, 0);	//0 = read-write
	
	printf("Writing data to shared memory...\n");
	strcpy(ptr, "Hello from shared memory");
	printf("Data written: %s\n", ptr);

	//Detach from shared memory
	shmdt(ptr);

	ptr = (char*) shmat(shmid, NULL, SHM_RDONLY);

	printf("Now attached in READ-ONLY mode\n");
	printf("Read data: %s\n", ptr);

		
	printf("Trying to overwrite in read-only mode...\n");
//	strcpy(ptr, "New data");

	shmdt(ptr);

	//Remove shared memory
	shmctl(shmid, IPC_RMID, NULL);
	printf("Shared memory removed.\n");

	return 0;
}

/*
Output:
Kautilya-Singh:./30
Shared memory created with ID: 2
Writing data to shared memory...
Data written: Hello from shared memory
Now attached in READ-ONLY mode
Read data: Hello from shared memory
Trying to overwrite in read-only mode...
Shared memory removed.

*/

