#!/bin/bash

:<<'END_COMMENT'

====================================================================================================================================
Name: 19_a.sh
Author : KAUTILYA SINGH
Description : 
Create a FIFO file by
    a. mknod command
====================================================================================================================================

END_COMMENT

mknod myfifo_a p

:<<'END_COMMENT'
Output:

Kautilya-Singh:./19_a.sh
Kautilya-Singh:./19_a.sh
mknod: myfifo_a: File exists
Kautilya-Singh:ls -l myfifo_a
prw-rw-r-- 1 kautilya-singh kautilya-singh 0 Sep 29 19:15 myfifo_a

END_COMMENT
