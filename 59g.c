/*
============================================================================
Name : 59g.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch SIGPROF using the setitimer system 
              call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGPROF\n");
    _exit(0);
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGPROF, handler);
    setitimer(ITIMER_PROF, &t, NULL);
    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59g.c -o sigprof
harsh@harshjain:~/hands-on-list2$ ./sigprof
Caught SIGPROF
============================================================================
*/
