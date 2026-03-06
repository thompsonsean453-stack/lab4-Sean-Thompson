# lab4
This lab implements a program that reads a list of integers from a file and prints their sum. The file parsing and memory allocation are written in C, and the actual summation loop is implemented in x86-64 assembly.

## Files

- main.c — Reads an input file, allocates an integer array, calls the assembly routine, prints the result. 
- sum_array.s — Assembly implementation of sum_array(int *arr, long n) that returns the sum in %eax. 


## How it works

### Input format
The input file must contain:
1. A non-negative integer n on the first line (the count).
2. Exactly n integers** after that.
