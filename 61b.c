/*
============================================================================
Name : 61b.c
Author : Harsh Jain
Description : Write a C program using the sigaction system 
              call to catch the SIGINT signal.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT\n");
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C\n");
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 61b.c -o sigint
harsh@harshjain:~/hands-on-list2$ ./sigint
Press Ctrl+C
^CCaught SIGINT
============================================================================
*/
