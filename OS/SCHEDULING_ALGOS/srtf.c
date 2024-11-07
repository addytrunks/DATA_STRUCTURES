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

// Function to implement the Shortest Remaining Time First (SRTF) Scheduling algorithm
void srtf_scheduling(struct Process processes[], int num_processes)
{
    int remaining_time[num_processes]; // Array to keep track of remaining burst time for each process
    int current_time = 0;              // Track the current time of the scheduler
    int completed_count = 0;           // Count of completed processes
    int shortest_job_index = -1;       // Index of the process with the shortest remaining time

    // Initialize remaining time for each process and set the response time to -1 (meaning not started yet)
    for (int i = 0; i < num_processes; i++)
    {
        remaining_time[i] = processes[i].burst_time;
        processes[i].response_time = -1;
    }

    // Continue until all processes are completed
    while (completed_count < num_processes)
    {
        shortest_job_index = -1;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < num_processes; i++)
        {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0)
            { // Process has arrived and is not completed
                if (shortest_job_index == -1 || remaining_time[i] < remaining_time[shortest_job_index])
                {
                    shortest_job_index = i;
                }
            }
        }

        if (shortest_job_index != -1)
        {
            // Set the response time when the process is first selected
            if (processes[shortest_job_index].response_time == -1)
                processes[shortest_job_index].response_time = current_time - processes[shortest_job_index].arrival_time;

            // Execute the process by decrementing its remaining time
            remaining_time[shortest_job_index]--;
            current_time++;

            // If the process is complete
            if (remaining_time[shortest_job_index] == 0)
            {
                // Set completion time
                processes[shortest_job_index].completion_time = current_time;

                // Calculate Turnaround Time (TAT = CT - AT)
                processes[shortest_job_index].turnaround_time = processes[shortest_job_index].completion_time - processes[shortest_job_index].arrival_time;

                // Calculate Waiting Time (WT = TAT - BT)
                processes[shortest_job_index].waiting_time = processes[shortest_job_index].turnaround_time - processes[shortest_job_index].burst_time;

                // Process completed, increase count
                completed_count++;
            }
        }
        else
        {
            // No process is ready, so increment the current time
            current_time++;
        }
    }

    // Display results and calculate averages
    printf("\nSRTF Scheduling Results:\n");
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

// Main function to take input and call the SRTF scheduling function
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

    // Call SRTF Scheduling function
    srtf_scheduling(processes, num_processes);

    return 0;
}
