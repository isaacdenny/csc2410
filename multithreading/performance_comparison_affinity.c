#define _GNU_SOURCE // Required for CPU_SET macros

#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 10000000 // Size of array to sum

// Global array to be summed
int array[ARRAY_SIZE];
int partial_sum[NUM_THREADS]; // Array to store partial sums

void *sumArray(void *arg) {
  int thread_id = *((int *)arg);
  int start = (ARRAY_SIZE / NUM_THREADS) * thread_id;
  int end = start + (ARRAY_SIZE / NUM_THREADS);
  partial_sum[thread_id] = 0;
  for (int i = start; i < end; i++) {
    partial_sum[thread_id] += array[i];
  }
  free(arg);
  return NULL;
}

// Function to set core affinity for a thread
void set_core_affinity(int core_id) {
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(core_id, &cpuset);
  pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
}

// Function to calculate total sum
int calculateTotalSum() {
  int total_sum = 0;
  for (int i = 0; i < NUM_THREADS; i++) {
    total_sum += partial_sum[i];
  }
  return total_sum;
}

// Function to measure execution time
double measure_execution_time(int set_affinity) {
  pthread_t threads[NUM_THREADS];
  struct timeval start, end;
  
  // Initialize array with random values
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }

  gettimeofday(&start, NULL); // Start time
  
  // Create threads
  for (int i = 0; i < NUM_THREADS; i++) {
    int *id = malloc(sizeof(int));
    *id = i;
    if (pthread_create(&threads[i], NULL, sumArray, id) != 0) {
      perror("Failed to create thread");
      exit(1);
    }
    if (set_affinity) {
      set_core_affinity(i);
    }
  }

  // Join threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  gettimeofday(&end, NULL); // End time
  double execution_time = (end.tv_sec - start.tv_sec) * 1000.0;
  execution_time += (end.tv_usec - start.tv_usec) / 1000.0;

  int total_sum = calculateTotalSum();
  printf("Total Sum: %d, Execution Time: %.2f ms\n", total_sum, execution_time);

  return execution_time;
}

int main() {
  srand(time(NULL));
  printf("Running with core affinity...\n");
  double time_with_affinity = measure_execution_time(1);
  printf("\nRunning without core affinity...\n");
  double time_without_affinity = measure_execution_time(0);
  printf("\nExecution Time with Core Affinity: %.2f ms\n", time_with_affinity);
  printf("Execution Time without Core Affinity: %.2f ms\n",
         time_without_affinity);
  return 0;
}
