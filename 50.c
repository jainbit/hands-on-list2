/*
============================================================================
Name : 50.c
Author : Harsh Jain
Description : Write a C program that intentionally induces 
              a deadlock scenario using semaphores.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

int main() {
    struct sembuf lockA = {0, -1, 0}, lockB = {1, -1, 0};
    int semid = semget(ftok(".", 'f'), 2, IPC_CREAT | 0644);
    semctl(semid, 0, SETVAL, 1);
    semctl(semid, 1, SETVAL, 1);

    if (fork() == 0) {
        semop(semid, &lockB, 1);
        printf("Child locked B, waiting for A\n");
        sleep(1);
        semop(semid, &lockA, 1);
        printf("Child got A\n");
    } else {
        semop(semid, &lockA, 1);
        printf("Parent locked A, waiting for B\n");
        sleep(1);
        semop(semid, &lockB, 1);
        printf("Parent got B\n");
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 50.c -o deadlock
harsh@harshjain:~/hands-on-list2$ ./deadlock
Parent locked A, waiting for B
Child locked B, waiting for A

============================================================================
*/
