#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3

void LRU(int pages[], int n) {
    int frame[FRAME_SIZE], counter[FRAME_SIZE] = {0}, pageFaults = 0, i, j, pos;
    for (i = 0; i < FRAME_SIZE; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                counter[j] = i; // Update the counter
                break;
            }
        }
        if (!found) {
            pos = 0;
            for (j = 1; j < FRAME_SIZE; j++)
                if (counter[j] < counter[pos]) pos = j; // Find LRU
            frame[pos] = pages[i];
            counter[pos] = i; // Update the counter
            pageFaults++;
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    LRU(pages, n);
    return 0;
}
