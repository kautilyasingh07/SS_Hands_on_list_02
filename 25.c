/*
====================================================================================================================================
Name: 25.c
Author : KAUTILYA SINGH
Description : 
Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
    a. access permission
    b. uid, gid
    c. time of last message sent and received
    d. time of last change in the message queue
    d. size of the queue
    f. number of messages in the queue
    g. maximum number of bytes allowed
    h. pid of the msgsnd and msgrcv

====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
	
	key_t key;
	int msgid;
	struct msqid_ds buf;

	//Generate key
	key = ftok("msgqprog", 'a');
	if(key == -1){
		perror("ftok");
		exit(EXIT_FAILURE);
	}

	//get message queue id
	msgid = msgget(key, IPC_CREAT | 0766);
	if(msgid == -1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	//get message queue information
	if(msgctl(msgid, IPC_STAT, &buf) == -1){
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	
	// Message queue details
	printf("Message queue ID: %d\n", msgid);
	
	//a. Access permission
	printf("Access permissions: %o\n", buf.msg_perm.mode & 0777);

	// b. uid, gid
	printf("Owner UID: %d\n", buf.msg_perm.uid);
	printf("Owner GID: %d\n", buf.msg_perm.gid);
	printf("Creator UID: %d\n", buf.msg_perm.cuid);
	printf("Creator UID: %d\n", buf.msg_perm.cgid);

	// c.time of last msg sent and received
	printf("Time of last msg sent: %s", ctime(&buf.msg_stime));	
	printf("Time of last msg received: %s", ctime(&buf.msg_rtime));	

	// d. time of last change in msg queue
	printf("Time of last change in message queue: %s", ctime(&buf.msg_ctime));

	// e. size of the deque(bytes currently in queue)
	printf("Current size of deque: %ld bytes\n", buf.msg_cbytes);

	// f. number of messages in queue
	printf("Number of messages in queue: %ld\n", buf.msg_qnum);

	// g. Maximum number of bytes allowed
	printf("Maximum bytes allowed in queue: %ld\n", buf.msg_qbytes);

	// h. pid of msgsnd and msgrcv
	printf("PID of last msgsnd: %d\n", buf.msg_lspid);
	printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

	return 0;
}

/*
Output:

Kautilya-Singh:./25
Message queue ID: 0
Access permissions: 766
Owner UID: 1000
Owner GID: 1000
Creator UID: 1000
Creator UID: 1000
Time of last msg sent: Thu Jan  1 05:30:00 1970
Time of last msg received: Thu Jan  1 05:30:00 1970
Time of last change in message queue: Wed Oct  1 23:18:47 2025
Current size of deque: 0 bytes
Number of messages in queue: 0
Maximum bytes allowed in queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0

*/

