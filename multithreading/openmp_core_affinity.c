#include <omp.h>
#include <stdio.h>
#include<unistd.h>

int main() {
  int num_threads = 4;
  
  // Set the number of threads
  omp_set_num_threads(num_threads);

  #pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    printf("Thread %d: Running on core (place) %d\n", thread_id, thread_id);
    
    // Simulate work with each thread
    for (int i = 0; i < 5; i++) {
      printf("Thread %d: working...\n", thread_id);
      sleep(1);
    }
  }

  printf("All threads have completed.\n");
  return 0;
}
