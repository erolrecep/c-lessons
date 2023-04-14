#include <stdio.h>
#include <stdlib.h>

/* This function calculates greatest common divisor between two numbers */
int gcd(int u, int v) {
	int t;
	while (u > 0) {
		if (u < v)
		{
			t = u;
			u = v;
			v = t;
		}
		u = u-v;
	}
	return v;
}


int main(int argc, char const *argv[])
{
	printf("Hello, World!\n");

	int x = 15;
	int y = 25;

	printf("x = %d, y = %d, gcd = %d\n", x, y, gcd(x, y));
	return 0;
}