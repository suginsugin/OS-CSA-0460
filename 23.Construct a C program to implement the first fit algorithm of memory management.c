# First Fit Algorithm in Memory Management

#include <stdio.h>

#define MAX 100

struct Block {
    int size;
    int isFree;
};

struct Process {
    int size;
};

void firstFit(struct Block blocks[], int m, struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j].isFree && blocks[j].size >= processes[i].size) {
                blocks[j].isFree = 0;
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                break;
            }
        }
    }
}

int main() {
    struct Block blocks[MAX] = {{100, 1}, {500, 1}, {200, 1}, {300, 1}, {600, 1}};
    struct Process processes[MAX] = {{212}, {417}, {112}, {426}};
    
    int m = 5; // Number of blocks
    int n = 4; // Number of processes

    firstFit(blocks, m, processes, n);
    
    return 0;
}
