// git add . --> checkpoint dos q eu alterei (substitui)
// git commit -m "mensagem" --> segundo checkpoint (consigo ver qual eh mlr)
// git push --> manda pro git
// git pull --> pega do git


#include <stdio.h>
#include <stdlib.h>

/* Enecrra em caso de falha */
void falha_criacao(){
  printf("Falha na criacao do arquivo de plateia!");
  exit(1);
}

/* Aloca dinamicamente a matriz, e retorna o ponteiro para ela */
char** aloca_plateia(){
  int m = 10, n = 12, i, j;
  char **Pplateia = (char**)malloc(m*sizeof(int*));

  if (Pplateia == NULL) falha_criacao();

  for(i = 0 ; i < m ; i++){
    /* Aloca memória para os elementos de uma linha. */
    Pplateia[i] = (char*)malloc(n*sizeof(int));
    if (Pplateia[i] == NULL) falha_criacao();

    /* Inicializa os elementos com - */
    for(j = 0 ; j < n ; j++) Pplateia[i][j]='-';
  }
  /* Retorna ponteiro para a matriz. */
  return Pplateia;

}
/* Save */
void gravaPlateia(char nomeArq[], char **p){
  int i, j;
  FILE *fp;
  if ((fp=fopen(nomeArq,"w"))==NULL) falha_criacao();
  else{
  for(i = 0 ; i < 10 ; i++){
    for(j = 0; j < 12; j++){
      fprintf(fp,"%c",p[i][j]);
    }
    fprintf(fp,"%c",'\n');
  }
  }
}

void inicia_plateia(FILE fp, char nomeArq[]){
  char **x;
  x = aloca_plateia(fp);
  gravaPlateia(nomeArq, x);
}

/* Função que carrega o arquivo com os dados da platéia. Se o arquivo ainda não existir, o cria e o inicializa com todas as poltronas vazias ('-'). */
void carregaPlateia(char nomeArq[], char **p){
 /* nomeArq: arquivo onde a plateia será salvo */
 /* p: ponteiro para a matriz da plateia. */
  int i,j;
  int m = 10, n = 12;
  FILE *fp; /* Ponteiro para o arquivo de plateia. */
  if ((fp=fopen(nomeArq,"r"))==NULL) { /* Tenta abrir. */
  /* Se não encontrou o arquivo, ele é criado com a opção "w+". */
    if ((fp=fopen(nomeArq,"w+"))==NULL) /* Verifica criação. */ falha_criacao();

  /* Inicializa plateia nova (gravação), fecha e reabre para leitura. */
  /* Matriz inicial é mxn só com '-' no arquivo. */
  char **Pplateia = aloca_plateia(*fp); /* Função que aloca e inicializa a matriz. */

  for(i = 0 ; i < m ; i++){
    for(j = 0 ; j < n ; j++){
      fprintf(fp,"%c",Pplateia[i][j]);
    }
    fprintf(fp,"%c",'\n');
  }

  free(Pplateia); /* Libera a memória da plateia */
  fclose(fp); /* Fecha arquivo: grava dados e disponibiliza para outro uso. */

    if ((fp=fopen(nomeArq,"r"))==NULL){ /* Reabre para leitura da matriz inicial. */
    falha_criacao();
    }

    printf("Primeiro acesso ao programa: arquivo de plateia criado");

 }
 /* Lê o arquivo e carrega os dados (atualiza) a matriz plateia. */
 for(i = 0 ; i < m ; i++){
   for(j = 0 ; j < n ; j++){
   fscanf(fp,"%c",&p[i][j]);
  }
 fgetc(fp); /* Limpa caractere de final de linha. */
 }

 fclose(fp); /* Fecha o arquivo (garante a gravação da matriz inicial). */
}

void mostra_plateia(char **p){
    int m = 10, n = 12, i=0 , j=0;
    printf("PLATEIA");
    printf("\n");
    printf("-----------------------------------------------------------");
    printf("\n");

    for (i=0 ; i < m; i++){
       for(j = 0 ; j < n ; j++){
            if (p[i][j] == '-'){
                int numero = 0;
                numero = i * 10 + j + 1;
                printf("%d", numero);
            if ( j == 11){
                    printf("\n");
            }
            else{
                printf(" ");
            }
            }else{
            printf("   ");
            }

        }
    }
    printf("-----------------------------------------------------------");
}

/* Menu de opções: */
void menu(){
  int i = 0, op;
  char input[10];

  printf("-----------------------\n");
  printf("         MENU         \n");
  printf("-----------------------\n");
  printf("0 - Sair do programa\n");
  printf("1 - Mostrar plateia\n");
  printf("2 - Mostrar ocupacao\n");
  printf("3 - Vender ingresso\n");
  printf("4 - Cancelar ingresso (devolucao)\n");
  printf("-----------------------\n");


  while (i == 0) {
    printf("Escolha uma opcao:  ");
    scanf("%s", input);
    op = atoi(input); // Transforma em int

    if (op >= 0 && op <= 4) { // Entra no if so se for entre 0 e 4
      switch (op) {
        case 0:
          i = 1;
          break;
        case 1:
          i = 1;
          break;
        case 2:
          i = 1;
          break;
        case 3:
          i = 1;
          break;
        case 4:
          i = 1;
          break;

        default: // Se nao for inteiro
          printf("Nao eh um inteiro! Digite um numero inteiro.\n");
          break;
      }
    }
    else { // Se nao for entre 0 e 4
      printf("Valor deve estar entre 0 e 4.\n");
    }
  }
}

int main(){
  FILE *fp;
  char nomeArq[] = "vasco.txt";
  char **p;
  p = aloca_plateia(nomeArq);
  gravaPlateia(nomeArq, p);
  mostra_plateia(p);
}
