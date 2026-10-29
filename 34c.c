/*
============================================================================
Name : 34c.c
Author : Harsh Jain
Description : Write a C program to execute ls -l | wc 
              using fcntl.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(1);
        fcntl(fd[1], F_DUPFD, 1);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(0);
        fcntl(fd[0], F_DUPFD, 0);
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
harsh@harshjain:~/hands-on-list2$ gcc 34c.c -o fcntl
harsh@harshjain:~/hands-on-list2$ ./fcntl

Output - 
      71      632     3502

============================================================================
*/
