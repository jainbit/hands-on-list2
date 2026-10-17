/*
============================================================================
Name : 36e.c
Author : Harsh Jain
Description : Write a C program to create a FIFO file using 
              the mkfifo library function.
============================================================================
*/

#include <sys/stat.h>

int main() {
    mkfifo("files/fifo36e", 0644);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 36e.c -o mkfifo
harsh@harshjain:~/hands-on-list2$ ./mkfifo

============================================================================
*/
