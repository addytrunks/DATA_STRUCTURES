#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{

    int fd = open("file3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open failed");
        exit(1);
    }
    const char *text = "Hello, World!\n";

    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1)
    {
        perror("write failed");
        exit(1);
    }
    else
    {
        printf("Wrote %d bytes.\n", bytes_written);
    }

    close(fd);
    return 0;
}