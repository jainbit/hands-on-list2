/*
============================================================================
Name : 59d.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch SIGALRM using the alarm system call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM (alarm)\n");
}

int main() {
    signal(SIGALRM, handler);
    alarm(2);
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59d.c -o sigalarm
harsh@harshjain:~/hands-on-list2$ ./sigalarm
Caught SIGALRM (alarm)
============================================================================
*/
