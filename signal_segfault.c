/**
 * @file signal_segfault.c
 * @brief Signal handler for SIGSEGV and prints message for segmntation fault
 * 
 * Course: CPE 2600
 * Section: 111
 * Assignment: Lab 10 
 * Name: Walker Williams
 * 
 * Compile: gcc -o signal_segfault signal_segfault.c
 *          ./signal_segfault
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGSEGV
 * @param sig Signal number
 */
void handle_sigsegv(int sig) {
    printf("Received SIGSEGV signal - segmentation fault detected!\n");
    printf("But continuing execution... will fault again!\n");
}

int main (int argc, char* argv[]) {
    // Register signal handler for SIGSEGV
    signal(SIGSEGV, handle_sigsegv);
    
    printf("Program started - will cause segmentation fault\n");
    
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer - this will cause SIGSEGV
    printf("The value of i is: %d\n", *i);

    // This line will never be reached due to infinite faults - test line to make sure it never gets here
    printf("This line will never be printed\n");
    
    return 0;
}