/*
============================================================================
Name : 60.c
Author : Harsh Jain
Description : Write a C program to ignore a SIGINT signal 
              and then reset it to the default action using 
              the signal system call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT ignored for 5 seconds\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("SIGINT reset to default for 5 seconds\n");
    sleep(5);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$  gcc 60.c -o resetting
harsh@harshjain:~/hands-on-list2$  ./resetting
SIGINT ignored for 5 seconds
SIGINT reset to default for 5 seconds
============================================================================
*/
