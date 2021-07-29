#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

void build_and_smoke_cigarret(int thread_number);

int main(int argc, char *argv[]) {

    int paper = 0, matches = 0, tobacco = 0;

    #pragma omp parallel sections default(none) shared(paper, matches, tobacco)
    {
        // SECTION AGENT
        #pragma omp section
        {
            // -- RAND 2 ITEMS FOREVER
            // ---- WHILE ITEMS IN THE TABLE
            // ------- WAIT
            int r = -1;
            do {
                if(paper + matches + tobacco == 0) {
                    r = rand() % 3;

                    // MATCHES & TOBACCO
                    if(r == 0) {
                        printf("\n[AGENT] GIVE MATCHES & TOBACCO\n");
                        matches = 1;
                        tobacco = 1;
                    }
                    // PAPER & TOBACCO
                    if(r == 1) {
                        printf("\n[AGENT] GIVE PAPER & TOBACCO\n");
                        paper = 1;
                        tobacco = 1;
                    }
                    // MATCHES & PAPER
                    if(r == 2) {
                        printf("\n[AGENT] GIVE MATCHES & PAPER\n");
                        matches = 1;
                        paper = 1;
                    }
                }
            } while (1);
        }

        // SMOKER PAPER
        #pragma omp section
        {
            // -- TABLE HAS MATCHES & TOBACCO?
            // -- BUILD CIGARETT
            // ---- TIMER 1 SEC
            // -- SMOKE
            // ---- TIMER 1 SEC
            do {
                if(tobacco > 0 && matches > 0) {
                    build_and_smoke_cigarret(omp_get_thread_num());

                    tobacco = 0;
                    matches = 0;
                }
            } while (1);
        }

        // SMOKER MATCHES
        #pragma omp section
        {
            // -- TABLE HAS PAPER & TOBACCO?
            // -- BUILD CIGARETT
            // ---- TIMER 1 SEC
            // -- SMOKE
            // ---- TIMER 1 SEC
            do {
                if(tobacco > 0 && paper > 0) {
                    build_and_smoke_cigarret(omp_get_thread_num());

                    tobacco = 0;
                    paper = 0;
                }
            } while (1);
        }

        // SMOKER TOBACCO
        #pragma omp section
        {
            // -- TABLE HAS MATCHES & PAPER?
            // -- BUILD CIGARETT
            // ---- TIMER 1 SEC
            // -- SMOKE
            // ---- TIMER 1 SEC
            do {
                if(paper > 0 && matches > 0) {
                    build_and_smoke_cigarret(omp_get_thread_num());

                    matches = 0;
                    paper = 0;
                }
            } while (1);
        }
    }

    return 0;
}

void build_and_smoke_cigarret(int thread_number) {
    printf("\n[SMOKER] %d building a cigarret\n", thread_number);
    sleep(1);
    printf("\n[SMOKER] %d smoking\n", thread_number);
    sleep(1);
}