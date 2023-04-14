#include <stdio.h>
#include <stdlib.h>
#include <openssl/rand.h>


int main(int argc, char const *argv[])
{
	unsigned long int buf;

	RAND_bytes((char *) &buf, sizeof(unsigned long int));

	printf("%d\n", buf % 100);

	return 0;
}
