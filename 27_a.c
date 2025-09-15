/*
====================================================================================================================================
Name: 27_a.c
Author : KAUTILYA SINGH
Description : 
    Write a program to receive messages from the message queue.
        a. with 0 as a flag
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf{
	long mtype;
	char mtext[100];
};

int main(){
	
	key_t key;
	int msgid;
	struct msgbuf message;
	
	key = ftok("msgqprog", 65);
	msgid = msgget(key, 0666);
	message.mtype = 1;
	int flag = 0;

	printf("Receiving message with blocking (flag 0)...\n");

	if(msgrcv(msgid, &message, sizeof(message.mtext), message.mtype, flag) == -1){
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}

	printf("Received (blocking): %s\n", message.mtext);


	return 0;
}


/*
Output:

Kautilya-Singh:ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6108010c 0          kautilya-s 766        0            0
0x4108010c 1          kautilya-s 666        7            1

Kautilya-Singh:./27_a
Receiving message with blocking (flag 0)...
Received (blocking): Hello

*/

