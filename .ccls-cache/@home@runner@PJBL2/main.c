// git add . --> checkpoint dos q eu alterei (substitui)
// git commit -m "mensagem" --> segundo checkpoint (consigo ver qual eh mlr)
// git push --> manda pro git
// git pull --> pega do git

/* Os dados do arquivo (a plateia) devem ser recuperados (arquivo aberto, lido e fechado) 
e colocados (durante a leitura do arquivo) na matriz alocada dinamicamente */

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

/* Libera memória alocada */
void imat_free(int **pmat){
int i;
for(i = 0 ; i < 12 ; i++)
free(pmat[i]); /* Libera memória alocada para a linha i. */
free(pmat); /* Libera memória do vetor inicial com os ponteiros para as linhas. */
}

int main(){
  int i;
  FILE *fpin; /* ponteiro para arquivo de entrada e saida de dados */
  char arquivo[]="plateia.txt"; /* Arquivo de entrada de dados. */
  
  
  while (i == 0){ /* Abre o arquivo */
    if ((fpin=fopen(arquivo,"r")) == NULL){ /* Verifica sucesso. */
      printf("Falha na abertura do arquivo de entrada de dados!\n");
      printf("Programa encerrado...");
      i = 1;
    }
    
// testar se ele ta ou n vazio
    
  }
  /* Fecha os arquivos se abertos */
  if (!(fpin == NULL)) fclose(fpin);
}