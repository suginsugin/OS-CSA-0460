#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat fileStat;
    
    // Replace "filename" with the actual file name
    if(stat("filename", &fileStat) < 0) {
        perror("stat failed");
        return 1;
    }

    printf("File Permissions:\n");
    printf("User: %c%c%c\n", 
           (fileStat.st_mode & S_IRUSR) ? 'r' : '-',
           (fileStat.st_mode & S_IWUSR) ? 'w' : '-',
           (fileStat.st_mode & S_IXUSR) ? 'x' : '-');
    
    printf("Group: %c%c%c\n", 
           (fileStat.st_mode & S_IRGRP) ? 'r' : '-',
           (fileStat.st_mode & S_IWGRP) ? 'w' : '-',
           (fileStat.st_mode & S_IXGRP) ? 'x' : '-');
    
    printf("Others: %c%c%c\n", 
           (fileStat.st_mode & S_IROTH) ? 'r' : '-',
           (fileStat.st_mode & S_IWOTH) ? 'w' : '-',
           (fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    
    return 0;
}
