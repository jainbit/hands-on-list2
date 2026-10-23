/*
============================================================================
Name : 61a.c
Author : Harsh Jain
Description : Write a C program using the sigaction system 
              call to catch the SIGSEGV signal.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSEGV\n");
    _exit(1);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 61a.c -o sigaction
harsh@harshjain:~/hands-on-list2$ ./sigaction
Caught SIGSEGV
============================================================================
*/
