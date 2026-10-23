/*
============================================================================
Name : 31.c
Author : Harsh Jain
Description : Write a C program to create a pipe, write to 
              the pipe, read from the pipe, and display the 
              content on the monitor.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[50];
    pipe(fd);
    write(fd[1], "hello through pipe\n", 19);
    int n = read(fd[0], buf, sizeof(buf));
    write(1, buf, n);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 31.c -o pipe
harsh@harshjain:~/hands-on-list2$ ./pipe

Output - hello through pipe

============================================================================
*/
