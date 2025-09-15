/*
====================================================================================================================================
Name: 26.c
Author : KAUTILYA SINGH
Description : 
    Write a program to send messages to the message queue. Check $ipcs -q

====================================================================================================================================
*/

#include<stdio.h>
#include<string.h>
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

	msgid = msgget(key, IPC_CREAT | 0666);

	//get message type from user
	message.mtype = 1;
	printf("Enter message: ");
	fgets(message.mtext, sizeof(message.mtext), stdin);
	
	//send message
	if(msgsnd(msgid, &message, strlen(message.mtext)+1, 0) == -1){
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}

	printf("Message sent successfully!\n");

	return 0;
}


/*
Output:

Kautilya-Singh:./26
Enter message: Hello
Message sent successfully!
Kautilya-Singh:ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6108010c 0          kautilya-s 766        0            0
0x4108010c 1          kautilya-s 666        7            1

*/
