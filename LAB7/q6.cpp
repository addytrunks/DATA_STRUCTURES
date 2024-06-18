#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void processString(char* input) {
    QueueCLL queue;
    char new_s[100];

    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] != '+') {
            queue.enqueue(input[i]);
        } else {
            // Check if the previous character is not a '+'
            if (i > 0 && input[i - 1] != '+') {
                queue.dequeue(); // Remove the previous non-'+' character
            }
        }
    }

    // Constructing the final string
    int index = 0;
    while (!queue.isEmpty()) {
        new_s[index++] = queue.dequeue();
    }
    new_s[index] = '\0';
    printf("Processed string: %s\n", new_s);

}

int main() {
    char input[100];

    printf("Enter the string: ");
    scanf("%s", input);

    processString(input);

    return 0;
}
