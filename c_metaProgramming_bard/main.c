#include <stdio.h>

#define FOR(i, n) for (int i = 0; i < n; i++)

int FIB(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return FIB(n - 1) + FIB(n - 2);
  }
}

int main() {
  // Print the Fibonacci sequence up to 10.
  FOR(i, 10) {
    printf("%d\n", FIB(i));
  }

  return 0;
}
