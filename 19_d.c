/*
====================================================================================================================================
Name: 19_d.c
Author : KAUTILYA SINGH
Description : 
Create a FIFO file by
    d. mknod system call
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
	if(mknod("myfifo_d", S_IFIFO | 0666, 0) == -1){
		perror("mknod");
		exit(1);
	}
	printf("FIFO created using mknod system call\n");

	return 0;
}


/*
Output:

Kautilya-Singh:./19_d
FIFO created using mknod system call

*/

