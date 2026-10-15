/*
============================================================================
Name : 35.c
Author : Harsh Jain
Description : Write a C program to find the total number of 
              directories in the present working directory 
              using ls -l | grep ^d | wc. Implement the 
              solution using only dup2.
============================================================================
*/

#include <unistd.h>

int main() {
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    if (fork() == 0) {
        dup2(p1[1], 1);
        close(p1[0]); close(p2[0]); close(p2[1]);
        execlp("ls", "ls", "-l", NULL);
    }
    if (fork() == 0) {
        dup2(p1[0], 0);
        dup2(p2[1], 1);
        close(p1[1]); close(p2[0]);
        execlp("grep", "grep", "^d", NULL);
    }
    dup2(p2[0], 0);
    close(p1[0]); close(p1[1]); close(p2[1]);
    execlp("wc", "wc", NULL);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 35.c -o dir
harsh@harshjain:~/hands-on-list2$ ./dir

Output - 
      0       0       0

============================================================================
*/
