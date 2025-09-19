/*
====================================================================================================================================
Name: 32_c.c
Author : KAUTILYA SINGH
Description : 
Write a program to implement semaphore to protect any critical section.
        c. protect multiple pseudo resources ( may be two) using counting semaphore
      
====================================================================================================================================
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 6

sem_t printer_sem;

void *use_printer(void *arg) {
	sem_wait(&printer_sem);

	printf("Thread %ld is using a printer...\n", (long)pthread_self());
	sleep(2);
	printf("Thread %ld finished printing.\n", (long)pthread_self());

	sem_post(&printer_sem);
	
	return NULL;
}

int main(){
	pthread_t threads[NUM_THREADS];

	sem_init(&printer_sem, 0, 2);

	for(int i = 0; i < NUM_THREADS; i++)
		pthread_create(&threads[i], NULL, use_printer, NULL);

	for(int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	sem_destroy(&printer_sem);
	
	return 0;
}


/*
Output:

Kautilya-Singh:./32_c
Thread 137417023547072 is using a printer...
Thread 137417031939776 is using a printer...
Thread 137417031939776 finished printing.
Thread 137417023547072 finished printing.
Thread 137417015154368 is using a printer...
Thread 137417006761664 is using a printer...
Thread 137417006761664 finished printing.
Thread 137417015154368 finished printing.
Thread 137416998368960 is using a printer...
Thread 137416989976256 is using a printer...
Thread 137416998368960 finished printing.
Thread 137416989976256 finished printing.

*/

