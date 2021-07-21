#include <stdio.h>
#include <omp.h>

/* Multi thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    int x = 0;
    #pragma omp parallel reduction(+:x)
    {
        x = 1;
    }

    printf("\n| Outside the parallel region - x = %d |", x);

    printf("\n\n-- [END] --\n");
    return 0;
}
