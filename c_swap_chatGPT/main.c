#include <stdio.h>
#include <stdlib.h>


#define SWAP(a, b) do { \
    int *p = &(a); \
    int *q = &(b); \
    int tmp = *p; \
    *p = *q; \
    *q = tmp; \
} while (0)



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void swap_w_xor(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}


void swap_wout_third_variable(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void swap_w_bitwise(int *a, int *b) {
    *a ^= *b;
    *b ^= ~*a;
    *a ^= ~*b;
}


int main(int argc, char const *argv[])
{
	int x = 7, y = 11;
	printf("Before swap function, x is %d, y is %d\n", x, y);

	swap(&x, &y);

	printf("After swap function, x is %d, y is %d\n", x, y);

	swap_w_xor(&x, &y);

	printf("After swap_w_xor function, x is %d, y is %d\n", x, y);

	swap_wout_third_variable(&x, &y);

	printf("After swap_wout_third_variable function, x is %d, y is %d\n", x, y);

	SWAP(x, y);

	printf("After SWAP macro function, x is %d, y is %d\n", x, y);

	return 0;
}