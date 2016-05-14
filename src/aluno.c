/* Interface header */
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "simulador_de_festa.h"
#include "gerador_numeros.h"

void espera_chegar();

void* simula_aluno(void* index)
{
  long id = (long) index;
  int max_tempo_sala = get_max_tempo_sala();

  espera_chegar();
  printf("Aluno %ld na porta.\n", id);
  pthread_exit(NULL);

}

void espera_chegar()
{
  int max_tempo_chegada = get_max_tempo_chegada();
  int real_tempo_chegada = generate_number_up_to(max_tempo_chegada);
  usleep(real_tempo_chegada*1000);
}