/* Interface header */
#include "gerador_numeros.h"

#include <stdlib.h>
#include <stdio.h>

int generate_number_up_to(int max) {
  return rand()%(max+1);
}
