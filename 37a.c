/*
============================================================================
Name : 37a.c
Author : Harsh Jain
Description : Write a C program to enable one-way 
              communication through FIFO (Writer program).
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("files/fifo37", 0644);
    int fd = open("files/fifo37", O_WRONLY);
    write(fd, "hello through fifo\n", 19);
    close(fd);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 37a.c -o fifo
harsh@harshjain:~/hands-on-list2$ ./fifo

============================================================================

*/
