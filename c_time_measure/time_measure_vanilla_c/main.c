#include <time.h>
#include <stdio.h>


void my_expensive_function_which_can_spawn_threads(){
    printf("Function is running ..\n");
}


int main()
{
    clock_t tic = clock();

    my_expensive_function_which_can_spawn_threads();

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}
