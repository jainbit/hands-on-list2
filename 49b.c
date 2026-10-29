/*
============================================================================
Name : 49b.c
Author : Harsh Jain
Description : Write a C program to implement a semaphore to 
              protect shared memory from concurrent write 
              access.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main() {
    struct sembuf op = {0, -1, 0};
    int semid = semget(ftok(".", 'c'), 1, 0);
    int shmid = shmget(ftok(".", 'e'), 1024, IPC_CREAT | 0644);
    char *data = shmat(shmid, NULL, 0);

    printf("Waiting to enter critical section\n");
    semop(semid, &op, 1);
    printf("Inside critical section\n");

    sprintf(data, "written by pid %d", getpid());
    sleep(3);
    printf("Shared memory: %s\n", data);

    op.sem_op = 1;
    semop(semid, &op, 1);
    printf("Left critical section\n");
    shmdt(data);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 49b.c -o semaphore
harsh@harshjain:~/hands-on-list2$ ./semaphore
Waiting to enter critical section
Inside critical section
Shared memory: written by pid 16267
Left critical section

============================================================================
*/
