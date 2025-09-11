#!/bin/bash

:<<'END_COMMENT'
====================================================================================================================================
Name: 19_b.sh
Author : KAUTILYA SINGH
Description :
Create a FIFO file by
    b. mkfifo command
====================================================================================================================================
END_COMMENT


mkfifo myfifo_b


:<<'END_COMMENT'
Output:

Kautilya-Singh:./19_b.sh
Kautilya-Singh:./19_b.sh
mkfifo: cannot create fifo 'myfifo_b': File exists
Kautilya-Singh:ls -l myfifo_b
prw-rw-r-- 1 kautilya-singh kautilya-singh 0 Sep 29 19:27 myfifo_b

END_COMMENT

