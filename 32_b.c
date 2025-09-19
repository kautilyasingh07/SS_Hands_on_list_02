/*
====================================================================================================================================
Name: 32_b.c
Author : KAUTILYA SINGH
Description : 
Write a program to implement semaphore to protect any critical section.
        b. protect shared memory from concurrent write access
      
====================================================================================================================================
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4
char shared_buffer[100];
sem_t sem;

void *write_shared(void *arg){
	
	sem_wait(&sem);
	snprintf(shared_buffer, sizeof(shared_buffer), "Thread %ld wrote this message.", (long)pthread_self());
	printf("%s\n", shared_buffer);

	sem_post(&sem);
	return NULL;
}

int main(){
	pthread_t threads[NUM_THREADS];
	sem_init(&sem, 0, 1);

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_create(&threads[i], NULL, write_shared, NULL);

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	sem_destroy(&sem);
	return 0;
}


/*
Output:

Kautilya-Singh:./32_b
Thread 137260353713856 wrote this message.
Thread 137260328535744 wrote this message.
Thread 137260336928448 wrote this message.
Thread 137260345321152 wrote this message.

*/

