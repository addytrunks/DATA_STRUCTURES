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
    int priority;        // Process Priority
};

// Function to implement the Priority Scheduling (Non-Preemptive) algorithm
void priority_scheduling_non_preemptive(struct Process processes[], int num_processes)
{
    int completed[num_processes];    // Array to keep track of completed processes
    int current_time = 0;            // Track the current time of the scheduler
    int completed_count = 0;         // Count of completed processes
    int highest_priority_index = -1; // Index of the process with the highest priority (lowest priority number)

    // Initialize the 'completed' array to 0, meaning no process is completed initially
    for (int i = 0; i < num_processes; i++)
    {
        completed[i] = 0;
    }

    // Main loop to process each job based on priority
    while (completed_count < num_processes)
    {
        highest_priority_index = -1;

        // Find the process with the highest priority (smallest priority value) that has arrived and is not completed
        for (int i = 0; i < num_processes; i++)
        {
            if (processes[i].arrival_time <= current_time && completed[i] == 0)
            { // Process has arrived and is not completed
                if (highest_priority_index == -1 || processes[i].priority > processes[highest_priority_index].priority)
                {
                    highest_priority_index = i;
                }
            }
        }

        if (highest_priority_index != -1)
        {
            // Set the response time when the process is first selected
            processes[highest_priority_index].response_time = current_time - processes[highest_priority_index].arrival_time;

            // Calculate the completion time by adding the burst time
            processes[highest_priority_index].completion_time = current_time + processes[highest_priority_index].burst_time;

            // Calculate Turnaround Time (TAT = CT - AT)
            processes[highest_priority_index].turnaround_time = processes[highest_priority_index].completion_time - processes[highest_priority_index].arrival_time;

            // Calculate Waiting Time (WT = TAT - BT)
            processes[highest_priority_index].waiting_time = processes[highest_priority_index].turnaround_time - processes[highest_priority_index].burst_time;

            // Update the current time by adding the burst time of the selected process
            current_time += processes[highest_priority_index].burst_time;

            // Mark this process as completed
            completed[highest_priority_index] = 1;

            // Increment the count of completed processes
            completed_count++;
        }
        else
        {
            // If no process is ready to execute, increment the current time
            current_time++;
        }
    }

    // Display results and calculate averages
    printf("\nPriority Scheduling (Non-Preemptive):\n");
    printf("Process ID\tArrival Time\tPriority\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");

    float total_completion_time = 0, total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id, processes[i].arrival_time, processes[i].priority, processes[i].burst_time,
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

// Main function to take input and call the Priority Scheduling function
int main()
{
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];

    // Take process details as input (ID, Arrival Time, Priority, Burst Time)
    for (int i = 0; i < num_processes; i++)
    {
        processes[i].process_id = i + 1; // Assign Process ID
        printf("Enter Arrival Time, Priority, and Burst Time for Process %d: ", processes[i].process_id);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].priority, &processes[i].burst_time);
    }

    // Call the Priority Scheduling function
    priority_scheduling_non_preemptive(processes, num_processes);

    return 0;
}
