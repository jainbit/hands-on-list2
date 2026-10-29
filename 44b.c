/*
============================================================================
Name : 44b.c
Author : Harsh Jain
Description : Write a C program to receive messages from the 
              message queue with IPC_NOWAIT as a flag.
============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[50];
};

int main() {
    struct msg m;
    int msqid = msgget(ftok(".", 'a'), 0);
    if (msgrcv(msqid, &m, sizeof(m.text), 0, IPC_NOWAIT) == -1)
        printf("No message in queue\n");
    else
        printf("Received (type %ld): %s\n", m.type, m.text);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 44b.c -o queue
harsh@harshjain:~/hands-on-list2$ ./queue
No message in queue

ipcs -q
ipcrm -q <msqid>
============================================================================
*/
