#include <stdio.h>

#define FRAME_SIZE 3
#define PAGE_SIZE 10

int findOptimalPage(int pages[], int frame[], int n, int index) {
    int farthest = index, pos = -1;
    for (int i = 0; i < FRAME_SIZE; i++) {
        int j;
        for (j = index + 1; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) return i; // If page not found
    }
    return (pos == -1) ? 0 : pos;
}

void optimalPageReplacement(int pages[], int n) {
    int frame[FRAME_SIZE], pageFaults = 0;
    for (int i = 0; i < FRAME_SIZE; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < FRAME_SIZE; j++)
            if (frame[j] == pages[i]) break;

        if (j == FRAME_SIZE) {
            int pos = findOptimalPage(pages, frame, n, i);
            frame[pos] = pages[i];
            pageFaults++;
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[PAGE_SIZE] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    optimalPageReplacement(pages, PAGE_SIZE);
    return 0;
}
