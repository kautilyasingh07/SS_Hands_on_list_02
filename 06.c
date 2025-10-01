/*
====================================================================================================================================
Name: 06.c
Author : KAUTILYA SINGH
Description : 
      Write a simple program to create three threads.
====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Work to be done by each thread
void* worker(void* param) {
	int id = *(int*)param;
	printf("Thread %d is running.\n", id);
	return NULL; // Equivalent to pthread_exit(NULL)
}


int main(){
	
	pthread_t tid[3];   // thread identifiers
	int ids[3];         // arguments for threads

	for(int i = 0; i < 3; i++){
        	ids[i] = i + 1;  // assign thread id (1,2,3)
		if (pthread_create(&tid[i], NULL, worker, &ids[i]) != 0) {
			fprintf(stderr, "Error: could not create thread %d\n", i + 1);
			exit(1);
        }
    }

	// Wait for all threads to complete
	for(int i = 0; i < 3; i++)
		pthread_join(tid[i], NULL);

	printf("Main program ends after all threads complete.\n");
	
	return 0;
}


/*
Output:

Kautilya-Singh:./06
Thread 2 is running.
Thread 1 is running.
Thread 3 is running.
Main program ends after all threads complete.

*/

