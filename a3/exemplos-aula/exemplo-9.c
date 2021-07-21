#include <stdio.h>
#include <omp.h>

/* Multi thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    int x = 234;
    #pragma omp parallel private(x)
    {
        printf("\n| Thread %d - x = %d |", omp_get_thread_num(), x);

    }
    printf("\n| Outside the parallel region - x = %d |", x);

    printf("\n\n-- [END] --\n");
    return 0;
}
