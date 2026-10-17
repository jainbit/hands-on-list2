/*
============================================================================
Name : 37b.c
Author : Harsh Jain
Description : Write a C program to enable one-way 
              communication through FIFO (Reader program).
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buf[50];
    mkfifo("files/fifo37", 0644);
    int fd = open("files/fifo37", O_RDONLY);
    int n = read(fd, buf, sizeof(buf));
    printf("Received: %.*s", n, buf);
    close(fd);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 37b.c -o fifo
harsh@harshjain:~/hands-on-list2$ ./fifo
Received: harsh@harshjain:~/hands-on-list2$ 

============================================================================
*/
