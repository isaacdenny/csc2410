#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5
int counter = 0;      // Shared counter
pthread_mutex_t lock; // Mutex lock

void *threadFunction(void *arg) {
  int thread_id = *((int *)arg);
  pthread_mutex_lock(&lock); // Lock the mutex

  printf("Thread %d: Incrementing counter from %d to %d\n", thread_id, counter,
         counter + 1);
  counter++;
  pthread_mutex_unlock(&lock); // Unlock the mutex
  free(arg); // Free dynamically allocated memory for thread_id

  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];
  pthread_mutex_init(&lock, NULL); // Initialize the mutex

  for (int i = 0; i < NUM_THREADS; i++) {
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], NULL, threadFunction, id);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Final counter value: %d\n", counter);
  pthread_mutex_destroy(&lock); // Destroy the mutex

  return 0;
}
