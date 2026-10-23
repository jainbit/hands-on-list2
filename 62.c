/*
============================================================================
Name : 62.c
Author : Harsh Jain
Description : Write a C program to ignore a SIGINT signal 
              and then reset it to the default action using 
              the sigaction system call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa = {0};

    sa.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT ignored for 5 seconds\n");
    sleep(5);

    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT reset to default for 5 seconds\n");
    sleep(5);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 62.c -o sigaction
harsh@harshjain:~/hands-on-list2$ ./sigaction
SIGINT ignored for 5 seconds
SIGINT reset to default for 5 seconds
============================================================================
*/
