#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 30

int frames[MAX_FRAMES];
int pageFaults = 0;

void initializeFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
}

int isPageInFrames(int page) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void addPageToFrames(int page) {
    frames[pageFaults % MAX_FRAMES] = page;
    pageFaults++;
}

void simulateFIFO(int pages[], int n) {
    initializeFrames();
    for (int i = 0; i < n; i++) {
        if (!isPageInFrames(pages[i])) {
            addPageToFrames(pages[i]);
        }
    }
}

int main() {
    int pages[MAX_PAGES] = {0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    int n = sizeof(pages) / sizeof(pages[0]);

    simulateFIFO(pages, n);

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
