/*
============================================================================
Name : 38a.c
Author : Harsh Jain
Description : Write a C program to establish two-way 
              communication through FIFO (Program 1).
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buf[50];
    mkfifo("files/fifo38_1", 0644);
    mkfifo("files/fifo38_2", 0644);
    int wfd = open("files/fifo38_1", O_WRONLY);
    int rfd = open("files/fifo38_2", O_RDONLY);

    write(wfd, "hello from 38a\n", 15);
    int n = read(rfd, buf, sizeof(buf));
    printf("38a received: %.*s", n, buf);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 38a.c -o fifo
harsh@harshjain:~/hands-on-list2$ ./fifo
38a received:

============================================================================
*/
