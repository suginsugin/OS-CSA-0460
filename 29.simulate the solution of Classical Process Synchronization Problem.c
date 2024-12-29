#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5

sem_t mutex;
int counter = 0;

void* threadFunction(void* arg) {
    int thread_id = *((int*)arg);
    sem_wait(&mutex);
    
    counter++;
    printf("Thread %d: Counter = %d\n", thread_id, counter);
    
    sem_post(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunction, (void*)&thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    return 0;
}
