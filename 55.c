/*
============================================================================
Name : 55.c
Author : Harsh Jain
Description : Write a C program to set a system resource 
              limit using the setrlimit system call.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit r;
    getrlimit(RLIMIT_NOFILE, &r);
    printf("Before: soft %lu, hard %lu\n", r.rlim_cur, r.rlim_max);

    r.rlim_cur = 100;
    setrlimit(RLIMIT_NOFILE, &r);

    getrlimit(RLIMIT_NOFILE, &r);
    printf("After:  soft %lu, hard %lu\n", r.rlim_cur, r.rlim_max);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 55.c -o setlimit
harsh@harshjain:~/hands-on-list2$ ./setlimit
Before: soft 524288, hard 524288
After:  soft 100, hard 524288
============================================================================
*/
