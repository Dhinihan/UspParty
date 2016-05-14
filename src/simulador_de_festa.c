#include "simulador_de_festa.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "aluno.h"

void cria_threads_alunos(int numero_alunos);
void cria_thread_seguranca();
void lanca_threads();

int global_max_tempo_chegada;
int global_max_tempo_sala;
int global_max_tempo_ronda;

void simula(int numero_alunos, int max_alunos, int max_tempo_chegada, int max_tempo_sala, int max_tempo_ronda)
{
  global_max_tempo_chegada = max_tempo_chegada;
  global_max_tempo_sala = max_tempo_sala;
  global_max_tempo_ronda = max_tempo_ronda;
  cria_threads_alunos(numero_alunos);
  cria_thread_seguranca();
  lanca_threads();
}

int get_max_tempo_chegada()
{
  return global_max_tempo_chegada;
}

int get_max_tempo_sala()
{
  return global_max_tempo_sala;
}

int get_max_tempo_ronda()
{
  return global_max_tempo_ronda;
}

void cria_threads_alunos(int numero_alunos)
{
  long i;
  pthread_t threads[numero_alunos];
  int codigo_retorno;

  for (i = 0; i < numero_alunos; i++) {
    codigo_retorno = pthread_create(&threads[i], NULL, simula_aluno, (void *) i);
    if (codigo_retorno) {
      printf("ERROR; return code from pthread_create() is %d\n", codigo_retorno);
      exit(-1);
    }
  }

  for (i = 0; i < numero_alunos; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("acabou\n");

  /* Last thing that main() should do */
  pthread_exit(NULL);
}

void cria_thread_seguranca() {

}
void lanca_threads() {

}