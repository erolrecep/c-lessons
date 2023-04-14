#include <stdio.h>
#include <math.h>

// Calculates the first n digits of pi using the Chudnovsky formula.
//
// n: The number of digits to calculate.
double chudnovsky_pi(int n) {
  double pi = 0.0;
  double a = 1.0;
  double b = 0.0;
  double c = 1.0;
  double d = 0.0;
  double e = 2.0;
  double f = 0.0;
  double g = 0.0;
  double h = 1.0;
  double k = 0.0;
  double l = 0.0;
  double m = 1.0;
  double nn = 1.0;
  double t = 0.0;
  double u = 0.0;
  double v = 0.0;
  double w = 0.0;
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;

  for (int i = 0; i < n; i++) {
    t = a * e - b * d;
    u = a * d + b * e;
    v = c * h - f * g;
    w = c * g + f * h;
    x = 1.0 / (t * t + u * u);
    y = (a * v - b * w) * x;
    z = (c * w + f * v) * x;
    a = t * y - u * z;
    b = t * z + u * y;
    c = v * y - w * z;
    d = v * z + w * y;
    e = (t * t - u * u) * x;
    f = (a * u + b * v) * x;
    g = (a * v - b * u) * x;
    h = (t * u + v * v) * x;
    k = (c * u + d * v) * x;
    l = (c * v - d * u) * x;
    m = (t * v - u * w) * x;
    n = (a * w + b * m) * x;
    nn = (a * m - b * w) * x;
  }

  pi = a / (nn * nn);

  return pi;
}

int main() {
  int n;
  printf("Enter the number of digits of pi to calculate: ");
  scanf("%d", &n);
  double pi = chudnovsky_pi(n);
  printf("The first %d digits of pi are: %.*f\n", n, n, pi);
  return 0;
}
