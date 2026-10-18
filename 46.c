/*
============================================================================
Name : 46.c
Author : Harsh Jain
Description : Write a C program to remove the message queue.
============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

int main() {
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_RMID, NULL);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 46.c -o queue
harsh@harshjain:~/hands-on-list2$ ./queue

============================================================================
*/
