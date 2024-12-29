#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char *text = "Hello, UNIX System Calls!";
    char buffer[50];

    // Create and open a file
    fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, text, 30);
    close(fd);

    // Read from the file
    fd = open("example.txt", O_RDONLY);
    read(fd, buffer, 30);
    buffer[30] = '\0'; // Null-terminate the string
    printf("Read from file: %s\n", buffer);
    close(fd);

    // Delete the file
    unlink("example.txt");
    return 0;
}
