/*
============================================================================
Name : 39.c
Author : Harsh Jain
Description : Write a C program to wait for data to be 
              written into a FIFO within 10 seconds, 
              utilizing the select system call with the FIFO.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/select.h>

int main() {
    char buf[50];
    mkfifo("files/fifo39", 0644);
    int fd = open("files/fifo39", O_RDONLY | O_NONBLOCK);

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    struct timeval tv = {10, 0};

    if (select(fd + 1, &rfds, NULL, NULL, &tv) > 0) {
        int n = read(fd, buf, sizeof(buf));
        printf("Data available: %.*s", n, buf);
    } else
        printf("No data within 10 seconds\n");
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 39.c -o waiting
harsh@harshjain:~/hands-on-list2$ ./waiting
No data within 10 seconds

printf "hello through fifo\n" > files/fifo39

Data available: hello through fifo

============================================================================
*/
