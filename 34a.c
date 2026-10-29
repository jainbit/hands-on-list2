/*
============================================================================
Name : 34a.c
Author : Harsh Jain
Description : Write a C program to execute ls -l | wc 
              using dup.
============================================================================
*/

#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(0);
        dup(fd[0]);
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
harsh@harshjain:~/hands-on-list2$ gcc 34a.c -o dup
harsh@harshjain:~/hands-on-list2$ ./dup

Output - 
      73      650     3599

============================================================================
// Uses pipe() and dup2() to redirect ls -l output to wc, 
// counting its lines, words, and bytes.
*/
