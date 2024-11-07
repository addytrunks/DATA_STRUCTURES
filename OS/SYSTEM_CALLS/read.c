#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{
    int fd = open("hello.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open failed");
        exit(1);
    }
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1)
    {
        perror("read failed");
        exit(1);
    }
    else if (bytes_read == 0)
    {
        printf("End of file reached.\n");
    }
    else
    {
        printf("Read %zd bytes:\n%s\n", bytes_read, buffer);
    }
    close(fd);
    return 0;
}
