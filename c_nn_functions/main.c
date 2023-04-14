#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double sigmoid(double x) {
  return 1.0 / (1.0 + exp(-x));
}


double relu(double x) {
  return x > 0 ? x : 0;
}


double leaky_relu(double x, double alpha) {
  return x > 0 ? x : alpha * x;
}


float tanh(float x) {
  return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}


void softmax(float *x, int n) {
  float sum = 0.0;
  for (int i = 0; i < n; i++) {
    x[i] = exp(x[i]);
    sum += x[i];
  }
  for (int i = 0; i < n; i++) {
    x[i] /= sum;
  }
}


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}


