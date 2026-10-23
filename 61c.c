/*
============================================================================
Name : 61c.c
Author : Harsh Jain
Description : Write a C program using the sigaction system 
              call to catch the SIGFPE signal.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGFPE\n");
    _exit(1);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGFPE, &sa, NULL);

    int a = 10, b = 0;
    printf("%d\n", a / b);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 61c.c -o sigfpe
harsh@harshjain:~/hands-on-list2$ ./sigfpe
Caught SIGFPE
============================================================================
*/
