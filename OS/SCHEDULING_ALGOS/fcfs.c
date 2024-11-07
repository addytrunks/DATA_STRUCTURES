#include <stdio.h>

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

// Function to implement the First-Come, First-Served (FCFS) algorithm
void fcfs_scheduling(struct Process processes[], int num_processes)
{
    int current_time = 0; // Track the current time of the scheduler

    // Sorting processes based on arrival time using bubble sort
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_processes - i - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                // Swap the processes if their arrival time is not in order
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Process each job according to FCFS
    for (int i = 0; i < num_processes; i++)
    {
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time; // Wait until the process arrives
        }

        processes[i].response_time = current_time - processes[i].arrival_time;

        // Calculate Completion Time (CT = Current Time + Burst Time)
        processes[i].completion_time = current_time + processes[i].burst_time;

        // Calculate Turnaround Time (TAT = Completion Time - Arrival Time)
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;

        // Calculate Waiting Time (WT = Turnaround Time - Burst Time)
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        // Update the current time by adding the burst time of the current process
        current_time = processes[i].completion_time;
    }

    // Display results and calculate averages
    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");

    float total_completion_time = 0, total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;

    for (int i = 0; i < num_processes; i++)
    {
        // Calculate and print the results for each process
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time, processes[i].response_time);

        // Accumulate totals for averages
        total_completion_time += processes[i].completion_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
        total_response_time += processes[i].response_time;
    }

    // Print average values
    printf("Average:\t%.2f\t%.2f\t%.2f\t%.2f\n", total_completion_time / num_processes,
           total_turnaround_time / num_processes, total_waiting_time / num_processes, total_response_time / num_processes);
}

// Main function to take input and call the FCFS Scheduling function
int main()
{
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];

    // Take process details as input (Arrival Time, Burst Time)
    for (int i = 0; i < num_processes; i++)
    {
        processes[i].process_id = i + 1; // Assign Process ID
        printf("Enter Arrival Time and Burst Time for Process %d: ", processes[i].process_id);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Call the FCFS Scheduling function
    fcfs_scheduling(processes, num_processes);

    return 0;
}
