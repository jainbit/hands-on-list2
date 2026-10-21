/*
============================================================================
Name : 59b.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch the SIGINT signal.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT\n");
}

int main() {
    signal(SIGINT, handler);
    printf("Press Ctrl+C\n");
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59b.c -o signal
harsh@harshjain:~/hands-on-list2$ ./signal
Press Ctrl+C
^CCaught SIGINT
============================================================================
*/
