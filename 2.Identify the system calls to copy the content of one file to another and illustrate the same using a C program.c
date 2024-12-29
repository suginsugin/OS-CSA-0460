#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: ./filecopy <source> <destination>\n", 40);
        return 1;
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        return 1;
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(source_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from source file");
    }

    close(source_fd);
    close(dest_fd);
    return 0;
}
