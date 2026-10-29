/*
============================================================================
Name : 56.c
Author : Harsh Jain
Description : Write a C program to measure the time taken 
              to execute 100 getppid() system calls using 
              a time stamp counter.
============================================================================
*/

// #include <stdio.h>
// #include <unistd.h>
// #include <x86intrin.h>

// int main() {
//     unsigned long long start = __rdtsc();
//     for (int i = 0; i < 100; i++)
//         getppid();
//     unsigned long long end = __rdtsc();
//     printf("Cycles for 100 getppid(): %llu\n", end - start);
//     return 0;
// }

//ARM-compatible version: measures elapsed time, not timestamp-counter cycles.

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 100; i++)
        getppid();

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long elapsed =
        (end.tv_sec - start.tv_sec) * 1000000000LL +
        (end.tv_nsec - start.tv_nsec);

    printf("Time for 100 getppid() calls: %lld nanoseconds\n",
           elapsed);

    return 0;
}


/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$  gcc 56.c -o timecal
harsh@harshjain:~/hands-on-list2$  ./timecal
Time for 100 getppid() calls: 33000 nanoseconds
============================================================================
*/
