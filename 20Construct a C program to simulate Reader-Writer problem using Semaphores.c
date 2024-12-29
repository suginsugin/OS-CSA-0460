#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_READERS 5

sem_t mutex;
sem_t wrt;
int read_count = 0;

void* reader(void* arg) {
    int f = *((int*)arg);
    while (1) {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        printf("Reader %d is reading\n", f);
        sleep(1);

        sem_wait(&mutex);
        read_count--;
        if (read_count == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);
        sleep(1);
    }
}

void* writer(void* arg) {
    int f = *((int*)arg);
    while (1) {
        sem_wait(&wrt);
        printf("Writer %d is writing\n", f);
        sleep(1);
        sem_post(&wrt);
        sleep(1);
    }
}

int main() {
    pthread_t read[MAX_READERS], write;
    int reader_ids[MAX_READERS];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < MAX_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&read[i], NULL, reader, &reader_ids[i]);
    }

    int writer_id = 1;
    pthread_create(&write, NULL, writer, &writer_id);

    for (int i = 0; i < MAX_READERS; i++) {
        pthread_join(read[i], NULL);
    }
    pthread_join(write, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
