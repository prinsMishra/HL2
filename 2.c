/*

============================================================================

Name : 2.c

Author : Prins Mishra

Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
 

Date: 19th sep, 2025.

============================================================================

*/ 
#include <stdio.h>
#include <sys/resource.h>



int main() {
    print_limit(RLIMIT_CPU, "CPU time ");
    print_limit(RLIMIT_FSIZE, "Max file size ");
    print_limit(RLIMIT_DATA, "Max data size");
    print_limit(RLIMIT_STACK, "Max stack size");
   
    return 0;
}
void print_limit(int resource, const char *name) {
    struct rlimit findlimit;
    getrlimit(resource, &findlimit);
    printf("%s: soft=%ld hard=%ld\n", name, (long)findlimit.rlim_cur, (long)findlimit.rlim_max);

}


/*CPU time : soft=-1 hard=-1
Max file size : soft=-1 hard=-1
Max data size: soft=-1 hard=-1
Max stack size: soft=8388608 hard=-1
*/