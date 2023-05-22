#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)


void fiunctionA(){
	printf("Functiona A is dacing!\n");
}


void fiunctionB(){
	printf("Functiona B is dacing!\n");
}


TICK(TIME_A);
functionA();
TOCK(TIME_A);

TICK(TIME_B);
functionB();
TOCK(TIME_B);
