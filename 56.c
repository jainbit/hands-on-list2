/*
============================================================================
Name : 56.c
Author : Harsh Jain
Description : Write a C program to measure the time taken 
              to execute 100 getppid() system calls using 
              a time stamp counter.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main() {
    unsigned long long start = __rdtsc();
    for (int i = 0; i < 100; i++)
        getppid();
    unsigned long long end = __rdtsc();
    printf("Cycles for 100 getppid(): %llu\n", end - start);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$  gcc 56.c -o timecal
harsh@harshjain:~/hands-on-list2$  ./timecal
Cycles for 100 getppid(): 32827
============================================================================
*/
