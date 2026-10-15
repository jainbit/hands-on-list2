/*
============================================================================
Name : 33.c
Author : Harsh Jain
Description : Write a C program to send and receive data 
              between the parent and child processes using 
              two-way communication (pipe).
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int p2c[2], c2p[2];
    char buf[50];
    pipe(p2c);
    pipe(c2p);

    if (fork() == 0) {
        close(p2c[1]);
        close(c2p[0]);
        int n = read(p2c[0], buf, sizeof(buf));
        printf("Child received: %.*s", n, buf);
        write(c2p[1], "hello from child\n", 17);
    } else {
        close(p2c[0]);
        close(c2p[1]);
        write(p2c[1], "hello from parent\n", 18);
        int n = read(c2p[0], buf, sizeof(buf));
        printf("Parent received: %.*s", n, buf);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
harsh@harshjain:~/hands-on-list2$ code .
harsh@harshjain:~/hands-on-list2$ gcc 33.c -o communication
harsh@harshjain:~/hands-on-list2$ ./communication

Output - 
Child received: hello from parent
Parent received: hello from child

============================================================================
*/
