/*
============================================================================
Name : 34b.c
Author : Harsh Jain
Description : Write a C program to execute ls -l | wc 
              using dup2.
============================================================================
*/

#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        dup2(fd[1], 1);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        dup2(fd[0], 0);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 34b.c -o dup2
harsh@harshjain:~/hands-on-list2$ ./dup2

Output -
      3      20     132

============================================================================
*/
