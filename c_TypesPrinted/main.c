#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>


int main(int argc, char const *argv[])
{
    printf("INT8_MAX: %d\n", INT8_MAX);
    printf("INT16_MAX: %d\n", INT16_MAX);
    printf("INT32_MAX: %d\n", INT32_MAX);
    printf("INT64_MAX: %lld\n", INT64_MAX);
    printf("INTMAX_MAX: %ld\n", INTMAX_MAX);
    printf("INT_FAST8_MAX: %d\n", INT_FAST8_MAX);
    printf("INT_FAST16_MAX: %d\n", INT_FAST16_MAX);
    printf("INT_FAST32_MAX: %d\n", INT_FAST32_MAX);
    printf("INT_FAST64_MAX: %lld\n", INT_FAST64_MAX);

    return 0;
}
