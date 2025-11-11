/**
 * @file signal_alarm.c
 * @brief Alarms after 5 seconds and handles the signal
 * 
 * Course: CPE 2600
 * Section: 111
 * Assignment: Lab 10 
 * Name: Walker Williams
 * 
 * Compile: gcc -o signal_alarm signal_alarm.c
 *          ./signal_alarm
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGALRM
 * @param sig Signal number
 */
void handle_alarm(int sig) 
{
    printf("ALARM! Received SIGALRM signal after 5 seconds\n");
}

int main() 
{
    // Register signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);
    
    printf("Setting alarm for 5 seconds...\n");
    
    // Schedules alarm for 5 seconds
    alarm(5);
    
    printf("Waiting for alarm...\n");
    
    // Wait keeps program running until alarm
    printf("Waiting for alarm...\n");
    pause();
    
    return 0;
}
