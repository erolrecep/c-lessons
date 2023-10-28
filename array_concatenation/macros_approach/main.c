#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_CONCAT(TYPE, A, An, B, Bn) \
  (TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(TYPE));

void *array_concat(const void *a, size_t an,
                   const void *b, size_t bn, size_t s)
{
  char *p = malloc(s * (an + bn));
  memcpy(p, a, an*s);
  memcpy(p + an*s, b, bn*s);
  return p;
}


int main(void)
{
  // testing
  const int a[] = { 1, 2, 3, 4, 5 };
  const int b[] = { 6, 7, 8, 9, 0 };
  
  unsigned int i;

  int *c = ARRAY_CONCAT(int, a, 5, b, 5);

  for(i = 0; i < 10; i++)
    printf("%d ", c[i]);
  printf("\n");

  free(c);
  return 0;
}
