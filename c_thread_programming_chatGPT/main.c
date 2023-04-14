#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

int n = 100;
int a[100], b[100], c[100];
pthread_t threads[NUM_THREADS];

struct thread_data {
    int start;
    int end;
};

void *add_vectors(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;

    for (int i = data->start; i < data->end; i++) {
        c[i] = a[i] + b[i];
    }

    pthread_exit(NULL);
}

int main() {
    // initialize arrays
    for (int i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i;
    }

    // compute chunk size
    int chunk_size = n / NUM_THREADS;

    // create threads
    struct thread_data data[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].start = i * chunk_size;
        data[i].end = (i == NUM_THREADS - 1) ? n : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, add_vectors, (void *) &data[i]);
    }

    // wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print result
    printf("c = [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", c[i], i == n - 1 ? "]\n" : ", ");
    }

    return 0;
}
