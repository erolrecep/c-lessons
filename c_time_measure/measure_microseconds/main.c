#include <stdio.h>
#include <time.h>    // for clock_t, clock()
#include <unistd.h>    // for sleep()
 
#define BILLION  1000000000.0
 
// main function to find the execution time of a C program
int main()
{
    struct timespec start, end;
 
    clock_gettime(CLOCK_REALTIME, &start);
 
    // do some stuff here
    sleep(3);
 
    clock_gettime(CLOCK_REALTIME, &end);
 
    // time_spent = end - start
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;
 
    printf("The elapsed time is %f seconds\n", time_spent);
 
    return 0;
}
