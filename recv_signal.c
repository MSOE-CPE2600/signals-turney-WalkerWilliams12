/**
 * @file rev_signal.c
 * @brief Recives a signal from the user and prints the integer value that belongs to it
 * 
 * Course: CPE 2600
 * Section: 111
 * Assignment: Lab 10 
 * Name: Walker Williams
 * 
 * Compile: gcc -o recv_signal recv_signal.c
 *          ./recv_signal
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGUSR1 that receives additional data
 * @param sig - signal number
 * @param info - signal information
 * @param input - unused input 
 */
void handle_sigusr1(int sig, siginfo_t *info, void *input) 
{
    (void)input; // Unused 
    
    if (info != NULL) 
    {
        printf("Received SIGUSR1 from process %d with value: %d\n", info->si_pid, info->si_value.sival_int);
    } 
    else 
    {
        printf("Received SIGUSR1\n");
    }
}

int main() {
    struct sigaction sa;
    
    printf("Receiver PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");
    
    // Signal handler for SA_SIGINFO flag
    sa.sa_sigaction = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    
    // Infinite loop to keep program running
    while(1) {
        pause(); // Wait for signals
    }
    
    return 0;
}
