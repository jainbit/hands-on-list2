/*
============================================================================
Name : 44a.c
Author : Harsh Jain
Description : Write a C program to receive messages from the 
              message queue with 0 as a flag.
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
    msgrcv(msqid, &m, sizeof(m.text), 0, 0);
    printf("Received (type %ld): %s\n", m.type, m.text);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 44a.c -o queue
harsh@harshjain:~/hands-on-list2$ ./queue
Received (type 1): first message

============================================================================
*/
