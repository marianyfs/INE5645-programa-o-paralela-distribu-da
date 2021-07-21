#include <stdio.h>
#include <omp.h>

/* Multi thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    #pragma omp parallel for
    for(int i = 0; i < 5; i++)
        printf("| Hello %d |", omp_get_thread_num());

    printf("\n\n-- [END] --\n");
    return 0;
}
