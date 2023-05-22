#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main()
{
    struct timespec res1,res2;

    /* read consecutive nanosecond values */
    clock_gettime(CLOCK_REALTIME,&res1);
    sleep(1);  /* Sleep 1 second */
    clock_gettime(CLOCK_REALTIME,&res2);
    printf("Difference: %lu\n",res2.tv_nsec-res1.tv_nsec);

    printf("First measured time: %lu\n",res1.tv_nsec);
    printf("Last measured time: %lu\n",res2.tv_nsec);

    return(0);
}
