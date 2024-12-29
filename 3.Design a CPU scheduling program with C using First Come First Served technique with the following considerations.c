#include <stdio.h>

typedef struct {
    int id, burst_time, waiting_time, turnaround_time;
} Process;

void findWaitingTime(Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++)
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
}

void findTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
}

void findavgTime(Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);
    float total_wait = 0, total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        total_wait += proc[i].waiting_time;
        total_turnaround += proc[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
}

int main() {
    Process proc[] = {{1, 5}, {2, 3}, {3, 8}};
    int n = sizeof(proc) / sizeof(proc[0]);
    findavgTime(proc, n);
    return 0;
}
