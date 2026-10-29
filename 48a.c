/*
============================================================================
Name : 48a.c
Author : Harsh Jain
Description : Write a C program to create a binary semaphore 
              and initialize its value.
============================================================================
*/

#include <stdio.h>
#include <sys/sem.h>

union semun {
    int val;
};

int main() {
    union semun arg;
    int semid = semget(ftok(".", 'c'), 1, IPC_CREAT | 0644);
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    printf("Binary semaphore id: %d, value: %d\n", semid, semctl(semid, 0, GETVAL));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 48a.c -o semaphore
harsh@harshjain:~/hands-on-list2$ ./semaphore
Binary semaphore id: 0, value: 1

============================================================================
*/
