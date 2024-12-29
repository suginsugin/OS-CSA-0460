#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    // Using fcntl
    int fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Using lseek
    off_t offset = lseek(fd, 0, SEEK_END);
    if (offset == (off_t)-1) {
        perror("Error seeking");
        close(fd);
        return 1;
    }

    // Using fstat
    struct stat fileStat;
    if (fstat(fd, &fileStat) == -1) {
        perror("Error getting file status");
        close(fd);
        return 1;
    }

    // Using opendir and readdir
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        close(fd);
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("Found file: %s\n", entry->d_name);
    }

    closedir(dir);
    close(fd);
    return 0;
}
