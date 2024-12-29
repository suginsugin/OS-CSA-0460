#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 50

typedef struct {
    char name[FILENAME_LENGTH];
} File;

void displayFiles(File files[], int count) {
    printf("Files in the directory:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, files[i].name);
    }
}

int main() {
    File files[MAX_FILES];
    int fileCount = 0;
    char choice;

    do {
        if (fileCount >= MAX_FILES) {
            printf("Directory is full. Cannot add more files.\n");
            break;
        }

        printf("Enter the name of the file: ");
        scanf("%s", files[fileCount].name);
        fileCount++;

        printf("Do you want to add another file? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    displayFiles(files, fileCount);

    return 0;
}
