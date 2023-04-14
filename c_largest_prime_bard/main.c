#include <stdio.h>
#include<stdlib.h>

void sieve(int n) {
  // Create a list of all the numbers from 2 to n.
  int *numbers = malloc(sizeof(int) * (n + 1));
  for (int i = 0; i <= n; i++) {
    numbers[i] = i;
  }

  // Mark all the multiples of 2 as non-prime.
  for (int i = 2; i * i <= n; i++) {
    if (numbers[i] != -1) {
      for (int j = i * i; j <= n; j += i) {
        numbers[j] = -1;
      }
    }
  }

  // Print all the remaining numbers, which are prime.
  for (int i = 2; i <= n; i++) {
    if (numbers[i] != -1) {
      printf("%d\n", i);
    }
  }

  // Free the memory.
  free(numbers);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  sieve(n);
  return 0;
}
