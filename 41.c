/*
============================================================================
Name : 41.c
Author : Harsh Jain
Description : Write a C program to create a message queue, 
              and print the key and message queue ID.
============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0644);
    printf("Key: 0x%x\nMessage queue id: %d\n", key, msqid);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 41.c -o queue
harsh@harshjain:~/hands-on-list2$ ./queue

Key: 0x61021895
Message queue id: 0

============================================================================
*/
