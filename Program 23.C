#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define MAX_MEMORY 1000

int memory[MAX_MEMORY];
int blocks[MAX_BLOCKS];
int n, m;

void first_fit(int block_size) {
    int i;
    for (i = 0; i < n; i++) {
        if (memory[i] >= block_size) {
            memory[i] -= block_size;
            printf("Allocated block at memory location %d with size %d\n", i, block_size);
            return;
        }
    }
    printf("No suitable block found for block of size %d\n", block_size);
}

void deallocate(int block_location) {
    int i;
    for (i = 0; i < m; i++) {
        if (blocks[i] == block_location) {
            printf("Deallocated block at memory location %d\n", block_location);
            memory[block_location] += blocks[i];
            blocks[i] = -1;
            return;
        }
    }
    printf("No block found at memory location %d\n", block_location);
}

int main() {
    int i;

    printf("Enter the number of blocks of memory: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the size of block %d: ", i);
        scanf("%d", &memory[i]);
    }

    printf("Enter the number of blocks to be allocated: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter the size of block %d: ", i);
        scanf("%d", &blocks[i]);
    }

    for (i = 0; i < m; i++) {
        first_fit(blocks[i]);
    }

    printf("Enter the location of block to be deallocated: ");
    scanf("%d", &i);
    deallocate(i);

    return 0;
}
