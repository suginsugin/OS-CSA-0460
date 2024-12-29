#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DIRS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
} File;

typedef struct {
    char name[NAME_LENGTH];
    File files[MAX_FILES];
    int file_count;
} Directory;

typedef struct {
    Directory directories[MAX_DIRS];
    int dir_count;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->dir_count = 0;
}

void createDirectory(FileSystem *fs, const char *name) {
    if (fs->dir_count < MAX_DIRS) {
        strcpy(fs->directories[fs->dir_count].name, name);
        fs->directories[fs->dir_count].file_count = 0;
        fs->dir_count++;
    } else {
        printf("Maximum directory limit reached.\n");
    }
}

void addFileToDirectory(FileSystem *fs, const char *dir_name, const char *file_name) {
    for (int i = 0; i < fs->dir_count; i++) {
        if (strcmp(fs->directories[i].name, dir_name) == 0) {
            if (fs->directories[i].file_count < MAX_FILES) {
                strcpy(fs->directories[i].files[fs->directories[i].file_count].name, file_name);
                fs->directories[i].file_count++;
            } else {
                printf("Maximum file limit reached in directory %s.\n", dir_name);
            }
            return;
        }
    }
    printf("Directory %s not found.\n", dir_name);
}

void displayFileSystem(FileSystem *fs) {
    for (int i = 0; i < fs->dir_count; i++) {
        printf("Directory: %s\n", fs->directories[i].name);
        for (int j = 0; j < fs->directories[i].file_count; j++) {
            printf("  File: %s\n", fs->directories[i].files[j].name);
        }
    }
}

int main() {
    FileSystem fs;
    initFileSystem(&fs);

    createDirectory(&fs, "Documents");
    createDirectory(&fs, "Pictures");

    addFileToDirectory(&fs, "Documents", "Resume.docx");
    addFileToDirectory(&fs, "Documents", "CoverLetter.docx");
    addFileToDirectory(&fs, "Pictures", "Vacation.jpg");

    displayFileSystem(&fs);

    return 0;
}
