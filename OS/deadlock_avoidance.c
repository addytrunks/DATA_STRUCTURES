#include <stdio.h>
#define NUM_PROCESSES 5
#define NUM_RESOURCES 3

int available[NUM_RESOURCES];                 // Available resources
int max[NUM_PROCESSES][NUM_RESOURCES];        // Maximum resources required by each process
int allocation[NUM_PROCESSES][NUM_RESOURCES]; // Current resource allocation

// Function to detect if there's a deadlock in the current state and return safe sequence if available
int detectDeadlock(int safeSequence[])
{
    int work[NUM_RESOURCES];
    int finish[NUM_PROCESSES];

    // Initialize work (available resources) and finish (process status) arrays
    for (int i = 0; i < NUM_RESOURCES; i++)
    {
        work[i] = available[i];
    }
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        finish[i] = 0; // 0 indicates unfinished
    }

    int foundProcess = 1; // Flag to check if at least one process could finish in an iteration
    int safeIndex = 0;    // Index to track the safe sequence

    while (foundProcess)
    {
        foundProcess = 0;
        for (int i = 0; i < NUM_PROCESSES; i++)
        {
            if (finish[i] == 0) // Process is unfinished
            {
                int j;
                for (j = 0; j < NUM_RESOURCES; j++)
                {
                    if (max[i][j] - allocation[i][j] > work[j])
                    {
                        break; // Process can't finish
                    }
                }
                if (j == NUM_RESOURCES) // Process can finish
                {
                    for (int k = 0; k < NUM_RESOURCES; k++)
                    {
                        work[k] += allocation[i][k]; // Free the resources
                    }
                    finish[i] = 1;                 // Mark process as finished
                    safeSequence[safeIndex++] = i; // Add to safe sequence
                    foundProcess = 1;              // At least one process could finish
                }
            }
        }
    }

    // Check for any unfinished process to determine deadlock
    int deadlockFound = 0;
    printf("Checking for deadlock...\n");
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        if (finish[i] == 0) // Process couldn't finish, indicating deadlock
        {
            printf("Deadlock detected. Process P%d cannot finish.\n", i);
            deadlockFound = 1;
        }
    }

    if (!deadlockFound)
    {
        printf("No deadlock detected.\n");
        printf("Safe sequence is: ");
        for (int i = 0; i < safeIndex; i++)
        {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    }

    return deadlockFound; // 1 if deadlock detected, 0 otherwise
}

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

    // Array to hold the safe sequence
    int safeSequence[NUM_PROCESSES];

    // Call the deadlock detection function
    if (detectDeadlock(safeSequence))
    {
        printf("System is in deadlock state.\n");
    }
    else
    {
        printf("System is not in deadlock state.\n");
    }

    return 0;
}
