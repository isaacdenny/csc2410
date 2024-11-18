#include <omp.h>
#include <stdio.h>
#define NUM_ELEMENTS 100

int main() {
  int array[NUM_ELEMENTS];
  int sum = 0;

  // Initialize the array
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    array[i] = i + 1;
  }
  
  // Parallelize the sum computation
  #pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    sum += array[i];
  }

  printf("Sum of array elements: %d\n", sum);
  return 0;
}
