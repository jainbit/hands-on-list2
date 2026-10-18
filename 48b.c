/*
============================================================================
Name : 48b.c
Author : Harsh Jain
Description : Write a C program to create a counting 
              semaphore and initialize its value.
============================================================================
*/

#include <stdio.h>
#include <sys/sem.h>

union semun {
    int val;
};

int main() {
    union semun arg;
    int semid = semget(ftok(".", 'd'), 1, IPC_CREAT | 0644);
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);
    printf("Counting semaphore id: %d, value: %d\n", semid, semctl(semid, 0, GETVAL));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 48b.c -o semaphore
harsh@harshjain:~/hands-on-list2$ ./semaphore
Counting semaphore id: 2, value: 2

============================================================================
*/
