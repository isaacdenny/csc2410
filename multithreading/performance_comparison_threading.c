#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#define NUM_THREADS 4
#define ARRAY_SIZE 10000000 // Size of array to sum
// Global array to be summed
int array[ARRAY_SIZE];
int partial_sum[NUM_THREADS]; // Array to store partial sums for multithreaded
                              // execution
// Thread function to calculate partial sum
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
//
// Function to calculate the total sum for multithreaded execution
int calculateTotalSumMultithreaded() {
  int total_sum = 0;

  for (int i = 0; i < NUM_THREADS; i++) {
    total_sum += partial_sum[i];
  }

  return total_sum;
}

// Function to calculate sum using a single thread
int calculateTotalSumSingleThreaded() {
  int total_sum = 0;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    total_sum += array[i];
  }

  return total_sum;
}
// Function to measure execution time
double measure_execution_time(int use_multithreading) {
  struct timeval start, end;
  
  // Initialize array with random values
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }

  gettimeofday(&start, NULL); // Start time

  if (use_multithreading) {
    pthread_t threads[NUM_THREADS];
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
      int *id = malloc(sizeof(int));
      *id = i;
      if (pthread_create(&threads[i], NULL, sumArray, id) != 0) {
        perror("Failed to create thread");
        exit(1);
      }
    }
    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
    }
    calculateTotalSumMultithreaded();
  } else {
    calculateTotalSumSingleThreaded();
  }

  gettimeofday(&end, NULL); // End time
  double execution_time = (end.tv_sec - start.tv_sec) * 1000.0;
  execution_time += (end.tv_usec - start.tv_usec) / 1000.0;

  printf("Execution Time: %.2f ms\n", execution_time);

  return execution_time;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int use_multithreading = 0;

  if (argc > 1) {
    use_multithreading = atoi(argv[1]); // Use command-line argument
  }

  if (use_multithreading) {
    printf("Running with multithreading...\n");
  } else {
    printf("Running without multithreading (single-threaded)...\n");
  }

  measure_execution_time(use_multithreading);

  return 0;
}
