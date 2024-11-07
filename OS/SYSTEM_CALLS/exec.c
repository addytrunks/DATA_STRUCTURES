#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", NULL};
    // Execute the "ls" command with the "-l" option
    execvp("ls", args);
    perror("execvp");
    exit(1);
    return 0;
}