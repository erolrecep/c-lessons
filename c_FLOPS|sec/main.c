#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Source: bard.google.com/

// Linpack benchmark
double linpack(double *a, int n) {
  double flops = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        a[i * n + j] += a[i * n + k] * a[k * n + j];
        flops += 2.0;
      }
    }
  }
  return flops;
}

int main() {
  // Set the matrix size
  int n = 1000;

  // Allocate memory for the matrix
  double *a = malloc(n * n * sizeof(double));

  // Initialize the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i * n + j] = rand() / (double)RAND_MAX;
    }
  }

  // Start the timer
  clock_t start = clock();

  // Run the Linpack benchmark
  double flops = linpack(a, n);

  // Stop the timer
  clock_t end = clock();

  // Calculate the FLOPS/sec
  double flops_sec = flops / (double)(end - start);

  // Print the results
  printf("FLOPS/sec: %f\n", flops_sec);

  // Free the allocated memory
  free(a);

  return 0;
}
