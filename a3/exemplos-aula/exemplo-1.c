#include <stdio.h>

/* Single thread */
int main(int argc, char *argv[]) {
    printf("\n-- [BEGIN] --\n\n");

    for(int i = 0; i < 5; i++)
        printf("| Hello %d |", i+1);

    printf("\n\n-- [END] --\n");
    return 0;
}
