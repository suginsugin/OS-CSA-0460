#include <stdio.h>
#include <stdlib.h>

void staticAllocation() {
    int arr[5] = {1, 2, 3, 4, 5}; // Static allocation
    printf("Static Allocation: ");
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
}

void stackAllocation() {
    int arr[5]; // Stack allocation
    for(int i = 0; i < 5; i++) arr[i] = i + 1;
    printf("Stack Allocation: ");
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
}

void dynamicAllocation() {
    int *arr = (int*)malloc(5 * sizeof(int)); // Dynamic allocation
    for(int i = 0; i < 5; i++) arr[i] = i + 1;
    printf("Dynamic Allocation: ");
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
    free(arr); // Free allocated memory
    printf("\n");
}

int main() {
    staticAllocation();
    stackAllocation();
    dynamicAllocation();
    return 0;
}
