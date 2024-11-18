#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 4

void *threadFunction(void *arg) {
  int thread_id = *((int *)arg);
  printf("Thread %d: Running\n", thread_id);
  sleep(1); // Simulate work
  printf("Thread %d: Exiting\n", thread_id);
  free(arg); // Free dynamically allocated memory for thread_id
  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], NULL, threadFunction, id);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("All threads have completed.\n");
  return 0;
}

