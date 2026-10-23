/*
============================================================================
Name : 64a.c
Author : Harsh Jain
Description : Write a C program that awaits the SIGSTOP 
              signal and determines whether it successfully 
              catches the signal or not.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSTOP\n");
}

int main() {
    if (signal(SIGSTOP, handler) == SIG_ERR)
        printf("Cannot set handler for SIGSTOP\n");
    printf("pid %d waiting for SIGSTOP\n", getpid());
    while (1)
        sleep(1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 64a.c -o sigstop
harsh@harshjain:~/hands-on-list2$ ./sigstop
Cannot set handler for SIGSTOP
pid 16789 waiting for SIGSTOP
============================================================================
*/
