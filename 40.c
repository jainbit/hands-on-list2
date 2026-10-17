/*
============================================================================
Name : 40.c
Author : Harsh Jain
Description : Write a C program to print the maximum number 
              of files that can be opened within a process 
              and the size of a pipe (circular buffer).
============================================================================
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Pipe size: %d\n", fcntl(fd[0], F_GETPIPE_SZ));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 40.c -o pipe
harsh@harshjain:~/hands-on-list2$ ./pipe

Max open files: 524288
Pipe size: 65536

============================================================================
*/
