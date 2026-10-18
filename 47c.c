/*
============================================================================
Name : 47c.c
Author : Harsh Jain
Description : Write a C program to detach the shared memory.
============================================================================
*/

#include <stdio.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    char *data = shmat(shmid, NULL, 0);
    printf("Attached, data: %s\n", data);
    shmdt(data);
    printf("Detached\n");
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 47c.c -o memory
harsh@harshjain:~/hands-on-list2$ ./memory
Attached, data: hello shared memory
Detached

============================================================================
*/
