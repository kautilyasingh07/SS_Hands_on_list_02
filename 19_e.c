/*
====================================================================================================================================
Name: 19_e.c
Author : KAUTILYA SINGH
Description : 
Create a FIFO file by
	e. mkfifo library function
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
	
	if(mkfifo("myfifo_e", 0666)){
		perror("mkfifo");
		exit(1);
	}

	printf("FIFO created using myfifo library function \n");
	return 0;
}

/*
Output:

Kautilya-Singh:./19_e
FIFO created using myfifo library function 

*/

