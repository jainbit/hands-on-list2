/*
============================================================================
Name : 45.c
Author : Harsh Jain
Description : Write a C program to change the existing 
              message queue permissions using the msqid_ds 
              structure.
============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds ds;
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_STAT, &ds);
    printf("Old permission: %o\n", ds.msg_perm.mode);

    ds.msg_perm.mode = 0666;
    msgctl(msqid, IPC_SET, &ds);

    msgctl(msqid, IPC_STAT, &ds);
    printf("New permission: %o\n", ds.msg_perm.mode);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 45.c -o permission
harsh@harshjain:~/hands-on-list2$ ./permission
Old permission: 0
New permission: 666

============================================================================
*/
