/*
============================================================================
Name : 59a.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch the SIGSEGV signal.
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
    signal(SIGSEGV, handler);
    int *p = NULL;
    *p = 10;
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59a.c -o signal
harsh@harshjain:~/hands-on-list2$ ./signal
Caught SIGSEGV
============================================================================
*/
