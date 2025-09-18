/*

============================================================================

Name : 3.c

Author : Prins Mishra

Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
 

Date: 19th sep, 2025.

============================================================================

*/ 

#include<stdio.h>
#include<sys/resource.h>

int main(){
    struct rlimit limit;

    getrlimit(RLIMIT_STACK, &limit);
    printf("Before : soft limit= %ld , hard limit = %ld\n", 
    (long)limit.rlim_cur, (long)limit.rlim_max);

    limit.rlim_cur = 5 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &limit);
     printf("After : soft limit= %ld , hard limit = %ld\n", 
    (long)limit.rlim_cur, (long)limit.rlim_max);
   
    return 0;
    
}
//Before : soft limit= 8388608 , hard limit = -1
//After : soft limit= 5242880 , hard limit = -1