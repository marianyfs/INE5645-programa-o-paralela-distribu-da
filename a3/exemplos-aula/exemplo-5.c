#include <stdio.h>
#include <omp.h>

/* Multi thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    #pragma omp parallel
    {
        printf("\n| Thread %d - Parallel |", omp_get_thread_num());
        
        #pragma omp single
        {
            printf("\n| Thread %d - Single |", omp_get_thread_num());
        }

        printf("\n| Thread %d - Parallel Other |", omp_get_thread_num());
    }

    printf("\n\n-- [END] --\n");
    return 0;
}
