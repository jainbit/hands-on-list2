/*
============================================================================
Name : 49d.c
Author : Harsh Jain
Description : Write a C program to remove the created 
              semaphore.
============================================================================
*/

#include <sys/sem.h>

int main() {
    semctl(semget(ftok(".", 'c'), 1, 0), 0, IPC_RMID);
    semctl(semget(ftok(".", 'd'), 1, 0), 0, IPC_RMID);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 49d.c -o semaphore
harsh@harshjain:~/hands-on-list2$ ./semaphore

============================================================================
*/
