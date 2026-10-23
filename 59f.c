/*
============================================================================
Name : 59f.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch SIGVTALRM using the setitimer system 
              call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGVTALRM\n");
    _exit(0);
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGVTALRM, handler);
    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59f.c -o sigvtalrm
harsh@harshjain:~/hands-on-list2$ ./sigvtalrm
Caught SIGVTALRM
============================================================================
*/
