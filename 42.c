/*
============================================================================
Name : 42.c
Author : Harsh Jain
Description : Write a C program to print information about 
              a message queue using msqid_ds and ipc_perm 
              structures.
============================================================================
*/

#include <stdio.h>
#include <time.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds ds;
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_STAT, &ds);

    printf("Access permission: %o\n", ds.msg_perm.mode);
    printf("UID: %d, GID: %d\n", ds.msg_perm.uid, ds.msg_perm.gid);
    printf("Last msg sent: %s", ctime(&ds.msg_stime));
    printf("Last msg received: %s", ctime(&ds.msg_rtime));
    printf("Last change: %s", ctime(&ds.msg_ctime));
    printf("Current size of queue (bytes): %lu\n", ds.__msg_cbytes);
    printf("Number of messages: %lu\n", ds.msg_qnum);
    printf("Max bytes allowed: %lu\n", ds.msg_qbytes);
    printf("PID of last msgsnd: %d, msgrcv: %d\n", ds.msg_lspid, ds.msg_lrpid);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 42.c -o information
harsh@harshjain:~/hands-on-list2$ ./information
Access permission: 644
UID: 1000, GID: 1000
Last msg sent: Thu Jan  1 05:30:00 1970
Last msg received: Thu Jan  1 05:30:00 1970
Last change: Tue Oct 27 07:36:50 2026
Current size of queue (bytes): 0
Number of messages: 0
Max bytes allowed: 16384
PID of last msgsnd: 0, msgrcv: 0

============================================================================
*/
