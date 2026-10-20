/*
============================================================================
Name : 54.c
Author : Harsh Jain
Description : Write a C program to print system resource 
              limits using the getrlimit system call.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit r;
    int res[] = {RLIMIT_CPU, RLIMIT_FSIZE, RLIMIT_DATA, RLIMIT_STACK, RLIMIT_CORE,
                 RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_AS, RLIMIT_MEMLOCK};
    char *names[] = {"CPU", "FSIZE", "DATA", "STACK", "CORE",
                     "NOFILE", "NPROC", "AS", "MEMLOCK"};

    for (int i = 0; i < 9; i++) {
        getrlimit(res[i], &r);
        printf("%-8s soft: %lu, hard: %lu\n", names[i], r.rlim_cur, r.rlim_max);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 54.c -o limits
harsh@harshjain:~/hands-on-list2$ ./limits
CPU      soft: 18446744073709551615, hard: 18446744073709551615
FSIZE    soft: 18446744073709551615, hard: 18446744073709551615
DATA     soft: 18446744073709551615, hard: 18446744073709551615
STACK    soft: 8388608, hard: 18446744073709551615
CORE     soft: 0, hard: 18446744073709551615
NOFILE   soft: 524288, hard: 524288
NPROC    soft: 10155, hard: 10155
AS       soft: 18446744073709551615, hard: 18446744073709551615
MEMLOCK  soft: 8388608, hard: 8388608
============================================================================
*/
