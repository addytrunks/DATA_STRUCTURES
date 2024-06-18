#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    QueueCLL processQueue;
    int timeSlot;

    printf("Enter the fixed time slot for each process: ");
    scanf("%d", &timeSlot);

    int choice;
    while (1) {
        printf("\nMenu\n");
        printf("1. Insert Process\n");
        printf("2. Execute\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int processTime;
                printf("Enter processing time for the new process: ");
                scanf("%d", &processTime);
                processQueue.enqueue(processTime);
                printf("Process with time %d added to the queue.\n", processTime);
                break;
            }
            case 2: {
                if (!processQueue.isEmpty()) {
                    int remainingTime = processQueue.dequeue() - timeSlot;
                    if (remainingTime <= 0) {
                        printf("Process completed its execution.\n");
                    } else {
                        processQueue.enqueue(remainingTime);
                        printf("Process jexecuted for %d time units. Remaining time: %d\n", timeSlot, remainingTime);
                    }
                } else {
                    printf("No process in the queue to execute.\n");
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
