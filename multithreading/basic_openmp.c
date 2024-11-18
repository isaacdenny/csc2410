#include <omp.h>
#include <stdio.h>

int main() {
  int num_threads = 4;
  
  // Set the number of threads
  omp_set_num_threads(num_threads);

  #pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    printf("Thread %d: Running\n", thread_id);

    #pragma omp critical
    {
      printf("Thread %d: Executing critical section\n", thread_id);
    }

    printf("Thread %d: Exiting\n", thread_id);
  }

  printf("All threads have completed.\n");
  return 0;
}
