/*
====================================================================================================================================
Name: 28.c
Author : KAUTILYA SINGH
Description : 
    Write a program to change the exiting message queue permission. (use msqid_ds structure)
====================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/types.h>


int main(){
	
	key_t key;
	int msgid;
	struct msqid_ds buf;

	key = ftok("msgqprog", 65);
	msgid = msgget(key, 0666);

	if(msgctl(msgid, IPC_STAT, &buf) == -1){
		perror("msgctl - IPC_STAT");
		exit(EXIT_FAILURE);
	}

	printf("Old permissions: %o\n", buf.msg_perm.mode & 0777);

	//change permission to new value
	if((buf.msg_perm.mode & 0777) == 0666)
		buf.msg_perm.mode = 0644;
	else
		buf.msg_perm.mode = 0666;

	if(msgctl(msgid, IPC_SET, &buf) == -1){
		perror("msgctl - IPC_SET");
		exit(EXIT_FAILURE);
	}

	printf("New permissions: %o\n", buf.msg_perm.mode & 0777);

	return 0;
}


/*
Output:

Kautilya-Singh:./28
Old permissions: 666
New permissions: 644

*/

