/*
====================================================================================================================================
Name: 32_a.c
Author : KAUTILYA SINGH
Description : 
Write a program to implement semaphore to protect any critical section.
        a. rewrite the ticket number creation program using semaphore
      
====================================================================================================================================
*/


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

int ticket = 0;
sem_t sem;

void *issue_ticket(void *arg){
	sem_wait(&sem);
	ticket++;
	
	printf("Thread %ld issued ticket #%d\n", (long)pthread_self(), ticket);

	sem_post(&sem);
	
	return NULL;
}

int main() {
	pthread_t threads[NUM_THREADS];
	sem_init(&sem, 0, 1);

	for(int i = 0; i < NUM_THREADS; i++)
		pthread_create(&threads[i], NULL, issue_ticket, NULL);

	for(int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	sem_destroy(&sem);
	return 0;
}

/*
Output:

Kautilya-Singh:./32_a
Thread 125371072636608 issued ticket #1
Thread 125371081029312 issued ticket #2
Thread 125370967783104 issued ticket #3
Thread 125371064243904 issued ticket #4
Thread 125371055851200 issued ticket #5

*/

