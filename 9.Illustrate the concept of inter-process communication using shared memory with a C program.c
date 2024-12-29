#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int shmid;
    key_t key = 1234;
    char *str;

    // Create shared memory
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    str = (char*) shmat(shmid, NULL, 0);

    // Write to shared memory
    sprintf(str, "Hello from process %d", getpid());
    printf("Data written: %s\n", str);

    // Detach from shared memory
    shmdt(str);
    return 0;
}
