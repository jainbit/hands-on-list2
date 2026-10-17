/*
============================================================================
Name : 36d.c
Author : Harsh Jain
Description : Write a C program to create a FIFO file using 
              the mknod system call.
============================================================================
*/

#include <sys/stat.h>

int main() {
    mknod("files/fifo36d", S_IFIFO | 0644, 0);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 36d.c -o mknod
harsh@harshjain:~/hands-on-list2$ ./mknod

============================================================================
*/
