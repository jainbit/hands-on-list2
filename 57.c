/*
============================================================================
Name : 57.c
Author : Harsh Jain
Description : Write a C program to print system limitations 
              for max exec argument length, max processes per 
              user, clock ticks per second, max open files, 
              page size, total and available physical memory 
              pages.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Max length of exec arguments: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Max processes per user: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %ld\n", sysconf(_SC_PAGESIZE));
    printf("Total physical pages: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Available physical pages: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 57.c -o limitations
harsh@harshjain:~/hands-on-list2$ ./limitations
Max length of exec arguments: 2097152
Max processes per user: 10155
Clock ticks per second: 100
Max open files: 524288
Page size: 4096
Total physical pages: 1145376
Available physical pages: 181760
============================================================================
*/
