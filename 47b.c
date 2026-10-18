/*
============================================================================
Name : 47b.c
Author : Harsh Jain
Description : Write a C program to create shared memory, 
              attach with O_RDONLY and check whether you are 
              able to overwrite.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    char *data = shmat(shmid, NULL, SHM_RDONLY);
    printf("Read: %s\n", data);
    printf("Trying to overwrite...\n");
    fflush(stdout);
    strcpy(data, "overwrite");
    printf("Overwritten: %s\n", data);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 47b.c -o memory
harsh@harshjain:~/hands-on-list2$ ./memory
Segmentation fault         (core dumped) ./memory

============================================================================
*/
