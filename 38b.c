/*
============================================================================
Name : 38b.c
Author : Harsh Jain
Description : Write a C program to establish two-way 
              communication through FIFO (Program 2).
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
    int rfd = open("files/fifo38_1", O_RDONLY);
    int wfd = open("files/fifo38_2", O_WRONLY);

    int n = read(rfd, buf, sizeof(buf));
    printf("38b received: %.*s", n, buf);
    write(wfd, "hello from 38b\n", 15);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 38b.c -o fifo
harsh@harshjain:~/hands-on-list2$ ./fifo
38b received:

============================================================================
*/
