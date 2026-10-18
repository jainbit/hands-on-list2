/*
============================================================================
Name : 47d.c
Author : Harsh Jain
Description : Write a C program to remove the shared memory.
============================================================================
*/

#include <stdio.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 47d.c -o memory
harsh@harshjain:~/hands-on-list2$ ./memory

============================================================================
*/
