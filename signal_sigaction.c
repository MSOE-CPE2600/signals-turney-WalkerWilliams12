/**
 * @file signal_sigaction.c
 * @brief Uses sigaction tto handle SIGUSR1 and prints PID
 * 
 * Course: CPE 2600
 * Section: 111
 * Assignment: Lab 10 
 * Name: Walker Williams
 * 
 * Compile: gcc -o signal_sigaction signal_sigaction.c
 *          ./sigaction_signal
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGUSR1
 * @param sig - signal number
 * @param info - signal information
 * @param input - unused input 
 */
void handle_sigusr1(int sig, siginfo_t *info, void *input) 
{
    (void)input; // Unused input
    
    if (info != NULL) 
    {
        printf("Received SIGUSR1 from process: %d\n", info->si_pid);
    } 
    else 
    {
        printf("Received SIGUSR1 (no sender info)\n");
    }
}

int main() 
{
    struct sigaction sa;
    
    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");
    printf("Send SIGUSR1 using: kill -SIGUSR1 %d\n", getpid());
    
    // Set up signal handler with SA_SIGINFO flag to get sender PID
    sa.sa_sigaction = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
    {
        perror("sigaction");
        exit(1);
    }
    
    // Infinite loop to keep program running
    while(1) 
    {
        pause(); // Wait for signals
    }
    
    return 0;
}
