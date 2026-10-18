/*
============================================================================
Name : 47a.c
Author : Harsh Jain
Description : Write a C program to create shared memory and 
              write some data to the shared memory.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, IPC_CREAT | 0644);
    char *data = shmat(shmid, NULL, 0);
    strcpy(data, "hello shared memory");
    printf("Written: %s\n", data);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 47a.c -o memory
harsh@harshjain:~/hands-on-list2$ ./memory
Written: hello shared memory

============================================================================
*/
