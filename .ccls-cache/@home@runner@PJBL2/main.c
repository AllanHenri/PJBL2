/* Ao se iniciar uma sessão de uso do programa, os dados do arquivo (a plateia) devem ser
recuperados (arquivo aberto, lido e fechado) e colocados (durante a leitura do arquivo) em
uma matriz alocada dinamicamente (12x10) que representa os lugares da plateia. Ao final do
uso do programa, a memória da matriz deve ser liberada. */

#include <stdio.h>
#include <stdlib.h>

/* Encerra o programa na falha de alocação de memória. */
void encerra(){
  printf("Memoria insuficiente!");
  exit(1);
}

/* Aloca memória para matriz de inteiros 12 x 10.*/
int** imat_alloc(){
  int i, j;
  /* Aloca memória para início de cada linha. */
  int **pm = (int**)malloc(12 * sizeof(int*));
  if (pm == NULL) encerra();
  for(i = 0 ; i < 12 ; i++){
    /* Aloca memória para os elementos de uma linha. */
    pm[i] = (int*)malloc(10 * sizeof(int));
    if (pm[i] == NULL) encerra();
    /* Inicializa os elementos com '-' */
      for(j = 0 ; j < 10 ; j ++) pm[i][j] = '-';
    }
  /* Retorna ponteiro para a matriz. */
  return pm;
}

/* Função que libera memória alocada para a matriz de 12
linhas através de ponteiro para ponteiro. */
void imat_free(int **pmat){
int i;
for(i = 0 ; i < 12 ; i++)
free(pmat[i]); /* Libera memória alocada para a linha i. */
free(pmat); /* Libera memória do vetor inicial com os ponteiros para as linhas. */
}