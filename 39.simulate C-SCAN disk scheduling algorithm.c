#include <stdio.h>

void cscan(int arr[], int size, int head, int total_cylinders) {
    int seek_sequence[size + 2], index = 0, distance, seek_count = 0;
    int i;

    // Sort the request array
    for (i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    // Service requests to the right of the head
    for (i = 0; i < size; i++) {
        if (arr[i] >= head) {
            seek_sequence[index++] = head;
            distance = arr[i] - head;
            seek_count += distance;
            head = arr[i];
        }
    }
    // Jump to the start of the disk
    seek_sequence[index++] = head;
    seek_sequence[index++] = 0;
    seek_count += total_cylinders - head;

    // Service requests to the left of the head
    for (i = 0; i < size; i++) {
        if (arr[i] < head) {
            seek_sequence[index++] = arr[i];
            distance = arr[i] - head;
            seek_count += -distance;
            head = arr[i];
        }
    }

    printf("Total Seek Time: %d\n", seek_count);
    printf("Seek Sequence: ");
    for (i = 0; i < index; i++)
        printf("%d ", seek_sequence[i]);
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(requests) / sizeof(requests[0]);
    int head = 50, total_cylinders = 200;

    cscan(requests, size, head, total_cylinders);
    return 0;
}
