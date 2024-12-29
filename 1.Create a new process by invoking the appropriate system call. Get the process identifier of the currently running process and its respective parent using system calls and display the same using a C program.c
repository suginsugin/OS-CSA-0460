#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid, ppid;

    pid = getpid(); // Get current process ID
    ppid = getppid(); // Get parent process ID

    printf("Current Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);

    pid_t child_pid = fork(); // Create a new process

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        printf("Child's Parent Process ID: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process created a Child with ID: %d\n", child_pid);
    }

    return 0;
}
