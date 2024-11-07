#include <stdio.h>
#include <limits.h>
#include "queue.h"

// Define a structure to hold information about each process
struct Process
{
    int process_id;      // Process ID
    int arrival_time;    // Arrival Time
    int burst_time;      // Burst Time
    int completion_time; // Completion Time
    int turnaround_time; // Turnaround Time
    int waiting_time;    // Waiting Time
    int response_time;   // Response Time
};

// Round Robin Scheduling algorithm
void round_robin_scheduling(struct Process processes[], int num_processes, int time_quantum)
{
    int current_time = 0;
    int remaining_time[num_processes];
    int completed = 0;

    // Initialize remaining burst times and response times
    for (int i = 0; i < num_processes; i++)
    {
        remaining_time[i] = processes[i].burst_time;
        processes[i].response_time = -1;
    }

    struct Queue q;
    initialize_queue(&q);

    // Enqueue processes that arrive at time 0
    for (int i = 0; i < num_processes; i++)
    {
        if (processes[i].arrival_time == 0)
        {
            enqueue(&q, i);
        }
    }

    // Continue until all processes are completed
    while (completed < num_processes)
    {

        int process_index = dequeue(&q);

        // Set response time when process first gets CPU
        if (processes[process_index].response_time == -1)
        {
            processes[process_index].response_time = current_time - processes[process_index].arrival_time;
        }

        // Calculate how much time this process will execute
        int execute_time = (remaining_time[process_index] < time_quantum) ? remaining_time[process_index] : time_quantum;

        current_time += execute_time;
        remaining_time[process_index] -= execute_time;

        // Check for new arrivals during this time slice
        for (int i = 0; i < num_processes; i++)
        {
            if (processes[i].arrival_time > current_time - execute_time &&
                processes[i].arrival_time <= current_time &&
                remaining_time[i] > 0 && !is_in_queue(&q, i))
            {
                enqueue(&q, i);
            }
        }

        // If process is not completed, re-enqueue it
        if (remaining_time[process_index] > 0)
        {
            enqueue(&q, process_index);
        }
        else
        {
            // Process is completed
            completed++;
            processes[process_index].completion_time = current_time;
            processes[process_index].turnaround_time =
                processes[process_index].completion_time - processes[process_index].arrival_time;
            processes[process_index].waiting_time =
                processes[process_index].turnaround_time - processes[process_index].burst_time;
        }
    }

    // Print the scheduling results
    printf("\nRound Robin Scheduling (Time Quantum = %d):\n", time_quantum);
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");

    float total_completion_time = 0, total_turnaround_time = 0,
          total_waiting_time = 0, total_response_time = 0;

    for (int i = 0; i < num_processes; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time, processes[i].response_time);

        total_completion_time += processes[i].completion_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
        total_response_time += processes[i].response_time;
    }

    // Print average values
    printf("\nAverages:");
    printf("\nCompletion Time: %.2f", total_completion_time / num_processes);
    printf("\nTurnaround Time: %.2f", total_turnaround_time / num_processes);
    printf("\nWaiting Time: %.2f", total_waiting_time / num_processes);
    printf("\nResponse Time: %.2f\n", total_response_time / num_processes);
}

int main()
{
    int num_processes;
    int time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[num_processes];

    for (int i = 0; i < num_processes; i++)
    {
        processes[i].process_id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", processes[i].process_id);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    round_robin_scheduling(processes, num_processes, time_quantum);

    return 0;
}