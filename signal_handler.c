/**
 * @file signal_handler.c
 * @brief Signal handler for SIGINT and prints a mesage
 * 
 * Course: CPE 2600
 * Section: 111
 * Assignment: Lab 10 
 * Name: Walker Williams
 * 
 * Compile: gcc -o signal_handler signal_handler.c
 *          ./signal_handler
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int signal_count = 0;

/**
 * @brief Signal handler for SIGINT - prints a message but does NOT exit
 */
void handle_signal() 
{
    signal_count++;
    printf("Received SIGINT signal #%d\n", signal_count);
    printf("Use 'kill -9 %d' to terminate this process\n", getpid());
}

int main() 
{
    printf("Process PID: %d\n", getpid());
    printf("SIGINT handler - process will not exit on CTRL+C\n");
    printf("Use 'kill -9 %d' to terminate this process\n", getpid());

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) 
    {
        printf("Sleeping - Received %d SIGINT signals so far\n", signal_count);
        sleep(3);
    }

    return 0;
}