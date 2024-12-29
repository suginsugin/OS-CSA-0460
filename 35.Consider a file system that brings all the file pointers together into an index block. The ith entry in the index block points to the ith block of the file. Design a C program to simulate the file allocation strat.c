#include <stdio.h>
#include <stdlib.h>

#define BLOCKS 5

typedef struct {
    int *indexBlock;
} FileSystem;

void allocateBlocks(FileSystem *fs) {
    fs->indexBlock = malloc(BLOCKS * sizeof(int));
    for (int i = 0; i < BLOCKS; i++) {
        fs->indexBlock[i] = i; // Pointing to block i
    }
}

void displayBlocks(FileSystem *fs) {
    for (int i = 0; i < BLOCKS; i++) {
        printf("Index %d -> Block %d\n", i, fs->indexBlock[i]);
    }
}

int main() {
    FileSystem fs;
    allocateBlocks(&fs);
    displayBlocks(&fs);
    free(fs.indexBlock);
    return 0;
}
