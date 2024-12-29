#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int id;
    int priority;
} Process;

void schedule(Process p[], int n) {
    int highest = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].priority > p[highest].priority) {
            highest = i;
        }
    }
    printf("Executing Process ID: %d with Priority: %d\n", p[highest].id, p[highest].priority);
}

int main() {
    Process p[MAX] = {{1, 2}, {2, 5}, {3, 1}, {4, 3}};
    schedule(p, 4);
    return 0;
}
