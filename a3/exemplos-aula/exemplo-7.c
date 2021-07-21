#include <stdio.h>
#include <omp.h>

/* Multi thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    int x = 0, y = 12;
    #pragma omp parallel default(none) shared(x)
    {
        printf("\n| Thread %d - x = %d |", omp_get_thread_num(), ++x);

    }

    printf("\n\n-- [END] --\n");
    return 0;
}
