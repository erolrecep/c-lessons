#include <stdio.h>
#include <math.h>

double stirling_approximation(int n) {
  return sqrt(2 * M_PI * n) * pow(n, n) * exp(-n);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("The Stirling approximation of %d! is %lf\n", n, stirling_approximation(n));
  return 0;
}
