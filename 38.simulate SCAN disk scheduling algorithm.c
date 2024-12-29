#include <stdio.h>

void SCAN(int arr[], int size, int head, int direction) {
    int seek_sequence[100], index = 0, i;
    int total_seek_time = 0;

    // Sort the request array
    for (i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    // Find the position of the head
    int pos;
    for (pos = 0; pos < size; pos++)
        if (arr[pos] >= head) break;

    // Service requests in the specified direction
    if (direction == 1) { // Moving towards the end
        for (i = pos; i < size; i++) {
            seek_sequence[index++] = arr[i];
            total_seek_time += abs(arr[i] - head);
            head = arr[i];
        }
        for (i = pos - 1; i >= 0; i--) {
            seek_sequence[index++] = arr[i];
            total_seek_time += abs(arr[i] - head);
            head = arr[i];
        }
    } else { // Moving towards the beginning
        for (i = pos - 1; i >= 0; i--) {
            seek_sequence[index++] = arr[i];
            total_seek_time += abs(arr[i] - head);
            head = arr[i];
        }
        for (i = pos; i < size; i++) {
            seek_sequence[index++] = arr[i];
            total_seek_time += abs(arr[i] - head);
            head = arr[i];
        }
    }

    printf("Seek Sequence: ");
    for (i = 0; i < index; i++)
        printf("%d ", seek_sequence[i]);
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(requests) / sizeof(requests[0]);
    int head = 50; // Initial head position
    int direction = 1; // 1 for right, 0 for left

    SCAN(requests, size, head, direction);
    return 0;
}
