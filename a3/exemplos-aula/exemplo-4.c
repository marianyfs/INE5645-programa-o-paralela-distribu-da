#include <stdio.h>
#include <omp.h>

/* Multi thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("\n| Thread %d - Section 1 - Text 1 |", omp_get_thread_num());
            printf("| Thread %d - Section 1 - Text 2 |\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("\n| Thread %d - Section 2 - Text 1 |", omp_get_thread_num());
            printf("| Thread %d - Section 2 - Text 2 |\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("\n| Thread %d - Section 3 - Text 1 |", omp_get_thread_num());
            printf("| Thread %d - Section 3 - Text 2 |\n", omp_get_thread_num());
        }
    }

    printf("\n\n-- [END] --\n");
    return 0;
}
