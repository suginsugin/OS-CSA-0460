#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_mutex_t lock;
int shared_resource = 0;

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    pthread_mutex_lock(&lock);
    
    // Critical section
    shared_resource++;
    printf("Thread %d incremented shared resource to %d\n", thread_id, shared_resource);
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Final value of shared resource: %d\n", shared_resource);
    return 0;
}