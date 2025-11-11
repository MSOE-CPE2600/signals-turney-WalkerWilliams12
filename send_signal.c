/**
 * @file send_signal.c
 * @brief Sends a SIGUSER1 signal with a random integer value to a process
 * 
 * Course: CPE 2600
 * Section: 111
 * Assignment: Lab 10 
 * Name: Walker Williams
 * 
 * Compile: gcc -o send_signal send_signal.c
 *          ./send_signal
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <target_pid>\n", argv[0]);
        printf("Example: %s 1234\n", argv[0]);
        return 1;
    }
    
    pid_t target_pid = atoi(argv[1]);
    union sigval value;
    
    // Seed random number generator
    srand((unsigned int)time(NULL));
    
    // Generates random number between 1 and 100
    int random_num = (rand() % 100) + 1;
    value.sival_int = random_num;
    
    printf("Sending SIGUSR1 to process %d with value: %d\n", target_pid, random_num);
    
    // Sends signal with data
    if (sigqueue(target_pid, SIGUSR1, value) == -1) 
    {
        perror("sigqueue");
        return 1;
    }
    
    printf("Signal sent successfully!\n");
    
    return 0;
}