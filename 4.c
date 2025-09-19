/*

============================================================================

Name : 4.c

Author : Prins Mishra

Description : 4. Write a program to measure how much time is taken to execute 100 getppid() system calls. Use time stamp counter.
 

Date: 19th sep, 2025.

============================================================================

*/ 
#include<stdio.h>
#include<unistd.h>
#include<x86intrin.h>

int main(){
    unsigned long long start, finish;
    int x;
    start = _rdtsc();

    for(int x =0;x<100;x++){
        getpid();
    }

    finish = _rdtsc();

    printf("cycle taken : %lld\n", finish - start);

    return 0;
}

//cycle taken : 313788