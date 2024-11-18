#define _GNU_SOURCE // Required for CPU_SET macros
#include <pthread.h>
#include <sched.h> // Required for setting CPU affinity
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *threadFunction(void *arg) {
  int core_id = *((int *)arg);
  cpu_set_t cpuset;

  // Initialize CPU set and assign the thread to the specified core
  CPU_ZERO(&cpuset);
  CPU_SET(core_id, &cpuset);

  // Set the core affinity of the current thread
  if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset) != 0) {
    perror("pthread_setaffinity_np failed");
  } else {
    printf("Thread assigned to core %d\n", core_id);
  }

  // Simulate work on the assigned core
  for (int i = 0; i < 5; i++) {
    printf("Thread on core %d: working...\n", core_id);
    sleep(1);
  }

  free(arg); // Free dynamically allocated memory for core_id
  return NULL;
}

int main() {
  int num_cores =
      sysconf(_SC_NPROCESSORS_ONLN); // Get the number of available cores
  pthread_t threads[num_cores];

  for (int i = 0; i < num_cores; i++) {
    int *core_id = malloc(sizeof(int));
    *core_id = i;
    pthread_create(&threads[i], NULL, threadFunction, core_id);
  }

  for (int i = 0; i < num_cores; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("All threads have completed.\n");
  return 0;
}
