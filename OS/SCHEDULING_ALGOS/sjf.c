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

// Function to implement the Shortest Job First (SJF) Scheduling algorithm
void sjf_scheduling(struct Process processes[], int num_processes)
{
    int is_completed[num_processes]; // Array to track if a process is completed
    int current_time = 0;            // Track the current time of the scheduler
    int completed_count = 0;         // Count of completed processes
    int shortest_job_index = -1;     // Index of the process with the shortest burst time

    // Initialize the `is_completed` array to 0 (meaning no process is completed initially)
    for (int i = 0; i < num_processes; i++)
        is_completed[i] = 0;

    // Continue until all processes are completed
    while (completed_count < num_processes)
    {
        shortest_job_index = -1;

        // Iterate over all processes to find the shortest job that has arrived
        for (int i = 0; i < num_processes; i++)
        {
            if (processes[i].arrival_time <= current_time && is_completed[i] == 0) // Process has arrived and is not completed
            {
                if (shortest_job_index == -1 || processes[i].burst_time < processes[shortest_job_index].burst_time)
                {
                    shortest_job_index = i; // Update to the current shortest job
                }
            }
        }

        if (shortest_job_index != -1)
        {
            // Set response time when the process is first selected (only for the first time it starts)
            processes[shortest_job_index].response_time = current_time - processes[shortest_job_index].arrival_time;

            // Calculate Completion Time
            processes[shortest_job_index].completion_time = current_time + processes[shortest_job_index].burst_time;

            // Calculate Turnaround Time (TAT = CT - AT)
            processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;

            // Calculate Waiting Time (WT = TAT - BT)
            processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;

            // Advance the current time by the burst time of the completed process
            current_time = processes[shortest_job_index].completion_time;

            // Mark process as completed
            is_completed[shortest_job_index] = 1;
            completed_count++;
        }
        else
        {
            // No process has arrived by the current time, so we increment the time
            current_time++;
        }
    }

    // Display results and calculate averages
    printf("\nSJF Scheduling Results:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");

    float total_completion_time = 0, total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time,
               processes[i].turnaround_time, processes[i].waiting_time, processes[i].response_time);

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

// Main function to take input and call the SJF scheduling function
int main()
{
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];

    // Take burst time and arrival time as input for each process
    for (int i = 0; i < num_processes; i++)
    {
        processes[i].process_id = i + 1; // Assign Process ID
        printf("Enter Arrival Time and Burst Time for Process %d: ", processes[i].process_id);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Call SJF Scheduling function
    sjf_scheduling(processes, num_processes);

    return 0;
}
