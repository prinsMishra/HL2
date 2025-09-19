/*

============================================================================

Name : 5.c

Author : Prins Mishra

Description : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files.
e. size of a page.
f. total number of pages in the physical memory.
g. number of currently available pages in the physical memory.
Date: 19th sep, 2025.

============================================================================

*/ 

#include <stdio.h>
#include <unistd.h>

int main() {
    printf(" Max length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf(" Max simultaneous processes per user: %ld\n", sysconf(_SC_CHILD_MAX));
    printf(" Clock ticks per second (jiffy): %ld\n", sysconf(_SC_CLK_TCK));
    printf(" Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf(" Page size (bytes): %ld\n", sysconf(_SC_PAGESIZE));
    printf(" Total pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf(" Available pages in physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));

    return 0;
}
/*
 Max length of arguments to exec: 2097152
 Max simultaneous processes per user: 30921
 Clock ticks per second (jiffy): 100
 Max open files: 1048576
 Page size (bytes): 4096
 Total pages in physical memory: 2007984
 Available pages in physical memory: 566261
 */