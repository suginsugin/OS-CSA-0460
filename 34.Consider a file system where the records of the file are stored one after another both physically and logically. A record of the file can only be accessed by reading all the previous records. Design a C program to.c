#include <stdio.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char data[50];
} Record;

Record file[MAX_RECORDS];
int count = 0;

void addRecord(int id, const char *data) {
    if (count < MAX_RECORDS) {
        file[count].id = id;
        snprintf(file[count].data, sizeof(file[count].data), "%s", data);
        count++;
    } else {
        printf("File is full.\n");
    }
}

void readRecords() {
    for (int i = 0; i < count; i++) {
        printf("Record %d: %s\n", file[i].id, file[i].data);
    }
}

int main() {
    addRecord(1, "First Record");
    addRecord(2, "Second Record");
    readRecords();
    return 0;
}
