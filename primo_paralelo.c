#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ARGUMENTS 3
#define MIN 1
#define INSTRUCTTIONS "[ERRO AO EXECUTAR PROGRAMA]\nVocê deve executar o programa com 2 argumentos inteiros positivos.\nO primeiro argumento é o valor máximo do intervalo a ser verificado.\nO segundo argumento é o número de threads a serem usadas.\n\nExemplo válido:\n $ ./primos 10000 4\n $ ./primos 10000 32\n\n"


typedef struct IntervalStruct {
  int min;
  int max;
} interval_type;
 
void *is_prime_number(void* arg);

int main(int argc, char *argv[]) {
  int max, number_of_threads;
    
  /* VERIFICAÇÃO DOS PARÃMETROS ------------------------------------------- */
  if(argc != ARGUMENTS) {
    printf("\n%s\n", INSTRUCTTIONS);
    exit(1);
  }
  /* atoi converte de alfanumérico para inteiro */
  max = atoi(argv[1]);
  number_of_threads = atoi(argv[2]);

  if(number_of_threads < 0 || MIN > max) {
    printf("\n%s\n", INSTRUCTTIONS);
    exit(1);
  }
  /* ----------------------------------------------------------------------- */

  /* declaração do vetor de threads (number_of_threads) */
  pthread_t threads[number_of_threads];

  /* Resultado da divisão, será usado para criar os intervalos para cada thread */
  int quotient = max / number_of_threads;
  
  /* Cria as threads e passa função para cada thread encontrar os primos dado
    um sub intervalo de números */
  int thread;
  interval_type intervals[number_of_threads];
  int thread_min, thread_max;

  for (thread = 1; thread <= number_of_threads; thread++) {

    // monto o intervalo que a thread vai processar
    if (thread == 1){
      thread_min = MIN;
    } else {
      thread_min = ((thread - 1) * quotient) + 1;
    }

    if(thread == number_of_threads){
      thread_max = max;
    } else {
      thread_max = thread * quotient;
    }
  
    interval_type interval = { thread_min, thread_max };
    intervals[thread] = interval;

    int created = pthread_create(&threads[thread], NULL, is_prime_number, &intervals[thread]);

    if(created) {
      printf("\n[ERRO AO CRIAR A THREAD] %i\n", thread);
      exit(1);
    }
  }

  /* Aguardo todas as threads terminarem */
  for (thread = 1; thread <= number_of_threads; thread++) {
    pthread_join(threads[thread], NULL);
  }

  return 0;
}

void *is_prime_number(void* arg) {
  interval_type *interval = (interval_type *)arg;
  int min = interval->min;
  int max = interval->max;

  int x, y, primo;
  /* ALGORITMO DE PRIMOS (versão exaustiva) -------------------------------- */
  /* para cada número no intervalo dado */
  for (x = min; x <= max; x++) {
    if (x == 0 || x == 1) {
      /* zero e 1 não são primos */
      primo = 0;
    } else {
      /* considero inicialmente que o número é primo */
      primo = 1; 
      /* tento provar que ele não é primo */
      for(y = 2; y < x; y++) {
        /* se o resto da divisão de x por y for igual a 0 */
        if (x % y == 0) {
          /*  consigo provar que ele não é primo */
          primo = 0;
        }
      }
    }
    if (primo == 1) {
      printf("%i ", x);
    }
  }
  printf("\n");
  /* ----------------------------------------------------------------------- */
  return 0;
}