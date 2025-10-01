/*
====================================================================================================================================
Name: 07.c
Author : KAUTILYA SINGH
Description : 
      Write a simple program to print the created thread ids.
====================================================================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* threadFunction(void* arg) {
	pthread_t tid = pthread_self();  // Get thread ID
	printf("Thread ID: %lu\n", tid);
	return NULL;
}

int main() {
	pthread_t thread1, thread2, thread3;
	int ret;

	// Create first thread
	ret = pthread_create(&thread1, NULL, threadFunction, NULL);
	if (ret != 0) {
		printf("Error creating thread 1\n");
		exit(1);
	}

	// Create second thread
	ret = pthread_create(&thread2, NULL, threadFunction, NULL);
	if (ret != 0) {
		printf("Error creating thread 2\n");
		exit(1);
	}

	// Create third thread
	ret = pthread_create(&thread3, NULL, threadFunction, NULL);
	if (ret != 0) {
		printf("Error creating thread 3\n");
		exit(1);
	}

	// Wait for threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("All threads have finished execution.\n");
	return 0;
}

/*
Output:

Kautilya-Singh:./07
Thread ID: 137640663836352
Thread ID: 137640672229056
Thread ID: 137640655443648
All threads have finished execution.

*/

