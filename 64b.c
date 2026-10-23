/*
============================================================================
Name : 64b.c
Author : Harsh Jain
Description : Write a C program that sends the SIGSTOP 
              signal to another process using the kill 
              system call.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    kill(atoi(argv[1]), SIGSTOP);
    printf("Sent SIGSTOP to %s\n", argv[1]);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 64b.c -o kill
harsh@harshjain:~/hands-on-list2$ ./kill
Sent SIGSTOP to 16789
============================================================================
*/
