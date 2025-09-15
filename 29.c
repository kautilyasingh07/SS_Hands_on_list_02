/*
====================================================================================================================================
Name: 29.c
Author : KAUTILYA SINGH
Description : 
    Write a program to remove the message queue.
====================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>


int main(){
	
	key_t key;
	int msgid;

	key = ftok("msgqprog", 65);
	if(key == -1){
		perror("ftok");
		exit(EXIT_FAILURE);
	}

	msgid = msgget(key, 0666);
	if(msgid == -1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	if(msgctl(msgid, IPC_RMID, NULL) == -1){
		perror("msgctl - IPC_RMID");
		exit(EXIT_FAILURE);
	}
	else
		printf("Message queue removed Successfully.\n");
	return 0;
}

/*
Output:

Kautilya-Singh:./29
Message queue removed Successfully.
Kautilya-Singh:ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6108010c 0          kautilya-s 766        0            0

*/


