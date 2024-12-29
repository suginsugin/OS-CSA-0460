# Thread Related Concepts in C

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunction(void* arg) {
    printf("Thread is running...\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    // (i) Create
    if (pthread_create(&thread, NULL, threadFunction, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // (ii) Join
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    // (iii) Equal
    if (pthread_equal(thread, pthread_self())) {
        printf("The threads are equal.\n");
    } else {
        printf("The threads are not equal.\n");
    }

    // (iv) Exit
    printf("Exiting main thread.\n");
    pthread_exit(NULL);
    return 0;
}
