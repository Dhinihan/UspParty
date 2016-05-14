#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "simulador_de_festa.h"

void *PrintHello(void *threadid)
{
  long tid;
  tid = (long)threadid;
  printf("Hello World! It's me, thread #%ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  int nAlunos;
  int maxAlunos;
  int maxChegada;
  int maxFesta;
  int maxRonda;
  int seed = 1;
  char option;

  while ((option = getopt (argc, argv, "n:p:t:r:s:e:")) != -1)
  {
    switch (option) {
      case 'n': nAlunos = atoi(optarg); break;
      case 'p': maxAlunos = atoi(optarg); break;
      case 't': maxChegada = atoi(optarg); break;
      case 'r': maxFesta = atoi(optarg); break;
      case 's': maxRonda = atoi(optarg); break;
      case 'e': seed = atoi(optarg); break;
      default : printf("Opção %c não foi reconhecida\n", option);
    }
  }

  srand(seed);

  simula(nAlunos, maxAlunos, maxChegada, maxFesta, maxRonda);


  return 3;
}