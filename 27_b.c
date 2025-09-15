/*
====================================================================================================================================
Name: 27_b.c
Author : KAUTILYA SINGH
Description : 
    Write a program to receive messages from the message queue.
        b. with IPC_NOWAIT as a flag
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

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
	int flag = IPC_NOWAIT;

	printf("Receiving message with non-blocking ...\n");

	if(msgrcv(msgid, &message, sizeof(message.mtext), message.mtype, flag) == -1){
		if(errno == ENOMSG){
			printf("No message available in the message queue!...\n");
		}
		else{
		perror("msgrcv");
		exit(EXIT_FAILURE);
		}
	}
	else
		printf("Received (Non-blocking): %s\n", message.mtext);



	return 0;
}

/*
Output:

Kautilya-Singh:./27_b
Receiving message with non-blocking ...
No message available in the message queue!...
Kautilya-Singh:ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6108010c 0          kautilya-s 766        0            0
0x4108010c 1          kautilya-s 666        0            0


*/
