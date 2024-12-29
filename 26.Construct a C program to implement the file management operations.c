#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "This is a sample file.\n");
        fclose(file);
        printf("File created successfully.\n");
    } else {
        printf("Error creating file.\n");
    }
}

void readFile(const char *filename) {
    char buffer[255];
    FILE *file = fopen(filename, "r");
    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("Error reading file.\n");
    }
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file.\n");
    }
}

int main() {
    const char *filename = "sample.txt";

    createFile(filename);
    readFile(filename);
    deleteFile(filename);

    return 0;
}
