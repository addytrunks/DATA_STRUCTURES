#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int available[NUM_RESOURCES];                 // Available resources
int max[NUM_PROCESSES][NUM_RESOURCES];        // Maximum resources required by each process
int allocation[NUM_PROCESSES][NUM_RESOURCES]; // Current resource allocation
int need[NUM_PROCESSES][NUM_RESOURCES];       // Remaining need for each process

// Calculate the need matrix based on max and allocation
void calculateNeed()
{
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        for (int j = 0; j < NUM_RESOURCES; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to check if the system is in a safe state and return a safe sequence if available
int isSafe(int safeSequence[])
{
    int work[NUM_RESOURCES];
    bool finish[NUM_PROCESSES] = {false}; // Keeps track of completed processes

    // Initialize work with available resources
    for (int i = 0; i < NUM_RESOURCES; i++)
    {
        work[i] = available[i];
    }

    int safeIndex = 0; // Index to track the safe sequence
    int count = 0;     // Number of processes that can finish

    while (count < NUM_PROCESSES)
    {
        bool found = false;
        for (int i = 0; i < NUM_PROCESSES; i++)
        {
            if (!finish[i])
            { // Check if process i can finish
                int j;
                for (j = 0; j < NUM_RESOURCES; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break; // Process can't finish if it needs more than available
                    }
                }
                if (j == NUM_RESOURCES)
                { // Process i can finish
                    for (int k = 0; k < NUM_RESOURCES; k++)
                    {
                        work[k] += allocation[i][k]; // Free resources allocated to i
                    }
                    finish[i] = true;
                    safeSequence[safeIndex++] = i;
                    count++;
                    found = true;
                }
            }
        }
        if (!found)
        {
            printf("System is not in a safe state\n");
            return 1; // Return 1 if deadlock is detected (unsafe state)
        }
    }
    printf("System is in a safe state\n");
    printf("Safe sequence: ");
    for (int i = 0; i < safeIndex; i++)
    {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 0; // Return 0 if safe state is detected
}

// Main function to check for deadlock and request resources
int main()
{
    // Input available resources
    printf("Enter available resources: ");
    for (int i = 0; i < NUM_RESOURCES; i++)
    {
        scanf("%d", &available[i]);
    }

    // Input maximum resources required by each process
    printf("Enter maximum resources required by each process:\n");
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        for (int j = 0; j < NUM_RESOURCES; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input current resource allocation for each process
    printf("Enter current resource allocation:\n");
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        for (int j = 0; j < NUM_RESOURCES; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate the need matrix
    calculateNeed();

    // Array to hold the safe sequence
    int safeSequence[NUM_PROCESSES];

    // Check if the system is in a safe state
    isSafe(safeSequence);

    // Request resources from a specific process
    int process_id;
    int request[NUM_RESOURCES];

    printf("Enter the process id to request resources: ");
    scanf("%d", &process_id);

    printf("Enter the requested resources: ");
    for (int i = 0; i < NUM_RESOURCES; i++)
    {
        scanf("%d", &request[i]);
    }

    // Check if request can be granted without exceeding need
    bool canGrant = true;
    for (int i = 0; i < NUM_RESOURCES; i++)
    {
        if (request[i] > need[process_id][i] || request[i] > available[i])
        {
            canGrant = false;
            break;
        }
    }

    if (canGrant)
    {
        // Temporarily allocate resources to check safe state
        for (int i = 0; i < NUM_RESOURCES; i++)
        {
            available[i] -= request[i];
            allocation[process_id][i] += request[i];
            need[process_id][i] -= request[i];
        }

        // Check for safe state
        if (isSafe(safeSequence) == 0)
        {
            printf("Request granted. Resources allocated.\n");
        }
        else
        {
            // Rollback allocation if unsafe
            for (int i = 0; i < NUM_RESOURCES; i++)
            {
                available[i] += request[i];
                allocation[process_id][i] -= request[i];
                need[process_id][i] += request[i];
            }
            printf("Request cannot be granted. Rollback performed.\n");
        }
    }
    else
    {
        printf("Request exceeds need or available resources. Cannot be granted.\n");
    }

    return 0;
}
