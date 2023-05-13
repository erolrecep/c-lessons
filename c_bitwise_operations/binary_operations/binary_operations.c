#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int num = 0b10101;

	printf("%x\n", num);  // Output: 15 (hexadecimal representation)
	printf("%u\n", num);  // Output: 21 (decimal representation)

	return 0;
}
