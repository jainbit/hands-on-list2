/*
============================================================================
Name : 32.c
Author : Harsh Jain
Description : Write a C program to send data from the parent
              process to the child process using pipe.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[50];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        int n = read(fd[0], buf, sizeof(buf));
        printf("Child received: %.*s", n, buf);
    } else {
        close(fd[0]);
        write(fd[1], "hello from parent\n", 18);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 32.c -o parent
harsh@harshjain:~/hands-on-list2$ ./parent

Output -
Child received: hello from parent

============================================================================
*/
