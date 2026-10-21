/*
============================================================================
Name : 59e.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch SIGALRM using the setitimer system 
              call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGALRM (setitimer)\n");
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGALRM, handler);
    setitimer(ITIMER_REAL, &t, NULL);
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59e.c -o sigalarm
harsh@harshjain:~/hands-on-list2$ ./sigalarm
Caught SIGALRM (setitimer)
============================================================================
*/
