/*
============================================================================
Name : 53b.c
Author : Harsh Jain
Description : Write a C program to set an interval timer 
              using ITIMER_VIRTUAL for 10 seconds and 
              10 microseconds.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Timer expired\n");
}

int main() {
    struct itimerval t;
    signal(SIGVTALRM, handler);

    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    setitimer(ITIMER_VIRTUAL, &t, NULL);

    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 53b.c -o interval
harsh@harshjain:~/hands-on-list2$ ./interval
Timer expired
Timer expired
Timer expired

============================================================================
*/
