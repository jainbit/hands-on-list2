/*
============================================================================
Name : 63.c
Author : Harsh Jain
Description : Write a C program to create an orphan process. 
              Use the kill system call to send SIGKILL signal 
              from the child process to the parent process.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child %d, parent before kill: %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(1);
        printf("Child %d, parent after kill: %d\n", getpid(), getppid());
    } else {
        printf("Parent %d sleeping\n", getpid());
        sleep(10);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 63.c -o sigkill
harsh@harshjain:~/hands-on-list2$ ./sigkill
Parent 16230 sleeping
Child 16231, parent before kill: 16230
Killed                     ./sigkill
harsh@harshjain:~/hands-on-list2$ Child 16231, parent after kill: 2815
============================================================================
*/
