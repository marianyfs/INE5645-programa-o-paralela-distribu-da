# INE5645-programacao-paralela-distribuida
Esse repositório contém trabalhos feitos para a disciplina de Programação Paralela e Distribuída

## SOBRE O TRABALHO

Com base na aula “04 - Extração de Paralelismo em SW”, você deve extrair paralelismo de um algoritmo sequencial e implementar um código paralelo em linguagem C capaz de realizar instruções do algoritmo em paralelo. Você deve usar a biblioteca pthread.h para implementar threads para a execução paralela.

1) Execute um programa sequencial que verifique quais números em um intervalo (ex. 1 a 10.000) são primos. Para determinar se um número x é primo, ele só pode ser divisível por 1 e por x. Ao final da execução, o programa deve imprimir apenas os números primos no intervalo.

2) Implemente uma versão paralela para o seu programa. Você deve explorar execuções com diferentes granularidades entre as tarefas do seu programa. Para isso, o seu programa deve receber como parâmetro pela linha de comando: (a) o número máximo do intervalo a ser processado, (b) o número de threads trabalhadoras, que processarão tarefas independentes (números diferentes do intervalo informado).

Ex.: As invocações do programa abaixo representam o cálculo de quais números são primos no intervalo de 1 à 10000, sendo computados por 32 e 4 threads, respectivamente.

```
./primo_paralelo 10000 32

./primo_paralelo 10000 4
```

Finalmente, você deve avaliar e comparar a versão do algoritmo paralelo com a versão sequencial. Para isso, você deverá medir speedup e eficiência do algoritmo paralelo para diferentes números de threads (ex. 2, 4, 8, 16, 32).

Instrumente o seu código para medir o tempo de execução ou utilize o comando time do Linux;
Gere os gráficos de speedup e eficiência para diferentes números de threads;
Elabore um breve relatório que inclua os gráficos e adicione a sua interpretação sobre os resultados.  
Como entrega para esta atividade são esperados (i) o relatório, (ii) o código fonte do programa sequencial e do programa paralelo.

## Versão sequencial

### Como compilar?
```gcc -Wall -o primo primo.c```

### Como executar?
```./primo 10000```

## Versão paralela

### Como compilar?
```gcc -Wall -o primo_paralelo primo_paralelo.c -lcurses -lpthread```

#### Como executar?
```./primo 10000 34```

## RESULTADOS
![resultado](https://github.com/marianyfs/INE5645-programacao-paralela-distribuida/blob/main/a2/resultado.png)