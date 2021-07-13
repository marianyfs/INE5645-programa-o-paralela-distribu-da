#include <stdio.h>

#define ARGUMENTS 3
#define MIN 1
#define INSTRUCTTIONS "[ERRO AO EXECUTAR PROGRAMA]\nVocê deve executar o programa com 2 argumentos inteiros positivos.\nO primeiro argumento é o valor máximo do intervalo a ser verificado.\nO segundo argumento é o número de threads a serem usadas.\n\nExemplo válido:\n $ ./primos 10000 4\n $ ./primos 10000 32\n\n"

int main(int argc, char *argv[]) {
  int max, x, y, primo;
    
  /* VERIFICAÇÃO DOS PARÃMETROS ------------------------------------------- */
  if(argc != ARGUMENTS) {
    printf("%s", INSTRUCTTIONS);
    return 1;
  }
  /* atoi converte de alfanumérico para inteiro */
  max = atoi(argv[1]);

  if(MIN > max) {
    printf("%s", INSTRUCTTIONS);
    return 1;
  }
  /* ----------------------------------------------------------------------- */

  /* ALGORITMO DE PRIMOS (versão exaustiva) -------------------------------- */
  /* para cada número no intervalo dado */
  for (x = MIN; x <= max; x++) {
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