/*
============================================================================
Name : 43.c
Author : Harsh Jain
Description : Write a C program to send messages to the 
              message queue.
============================================================================
*/

#include <string.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[50];
};

int main() {
    struct msg m;
    int msqid = msgget(ftok(".", 'a'), 0);

    m.type = 1;
    strcpy(m.text, "first message");
    msgsnd(msqid, &m, strlen(m.text) + 1, 0);

    m.type = 2;
    strcpy(m.text, "second message");
    msgsnd(msqid, &m, strlen(m.text) + 1, 0);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 43.c -o ipcs
harsh@harshjain:~/hands-on-list2$ ./ipcs

============================================================================
*/
