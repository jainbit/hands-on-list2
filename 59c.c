/*
============================================================================
Name : 59c.c
Author : Harsh Jain
Description : Write a C program using the signal system call 
              to catch the SIGFPE signal.
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
    signal(SIGFPE, handler);
    int a = 10, b = 0;
    printf("%d\n", a / b);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 59c.c -o signal
harsh@harshjain:~/hands-on-list2$ ./signal
Caught SIGFPE
============================================================================
*/
