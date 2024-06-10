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

/* Validacao de entrada de inteiros: */
int validacao_int(){
  int i = 0, j = 0, valorInt;
  char num_lido[20];
  scanf("%s",num_lido);
  fflush(stdin);
  while (j == 0){ // Valida se eh um numero inteiro
    while (num_lido[i] != '\0'){
      if (i == 0 && num_lido[i] == '-'){
        i++;
        continue;
      }
      if (num_lido[i] >= 48 && num_lido[i] <= 57) {
        i++;
      }
      else {
        printf("Valor invalido! Digite um numero valido: ");
        scanf("%s",num_lido);
        fflush(stdin);
        i = 0;
      }
    }
    j = 1;
  }
  valorInt = atoi(num_lido);

  return valorInt;
}

char validacao_char(){
  char tipo;
  int i = 0;
  printf("\nDigite se a entrada eh (m)eia ou (i)nteira: ");
  scanf("%c",&tipo);
  fflush(stdin);
  while (i == 0){
    if (tipo == 'i' || tipo == 'm' || tipo == 'I' || tipo == 'M') i = 1;
    else{
      printf("\nOpcao invalida, selecione o tipo de entrada (m) ou (i):  ");
      scanf("%c",&tipo);
    }
  }
  return tipo;
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
  if ((fp=fopen(nomeArq,"w+"))==NULL) falha_criacao();
  else{
  for(i = 0 ; i < 10 ; i++){
    for(j = 0; j < 12; j++){
      fprintf(fp,"%c",p[i][j]);
    }
    fprintf(fp,"%c",'\n');
  }
  }
}

carregar_plateia(FILE *fp, char **p){
    int m= 10, n = 12;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
    fscanf(fp,"%c",&p[i][j]);
        }
    fgetc(fp); /* Limpa caractere de final de linha. */
    }
fclose(fp); /* Fecha o arquivo (garante a gravação da matriz inicial). */
}




/* Mostrar Plateia */
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
                numero = i * 12 + j + 1;
                printf("%d", numero);
            if (j == 11) printf("\n");
            else printf(" ");
            } else{
                  if (j == 11) printf("   \n");
                  else printf("   ");
          }
        }
    }
    printf("-----------------------------------------------------------");
}

void mostra_ocupacao(char **p){
    int m = 10, n = 12, i=0 , j=0, meia=0, inteira =0;
    printf("\nPLATEIA");
    printf("\n");
    printf("-----------------------------------------------------------");
    printf("\n");
      for (i=0 ; i < m; i++){
        for(j = 0 ; j < n ; j++){
                printf("%c", p[i][j]);
                if (p[i][j] == 'm' || p[i][j] == 'M'){
                    meia++;
                }
                if (p[i][j] == 'i'|| p[i][j] == 'I'){
                    inteira++;
                }

            if (j == 11) printf("\n");
            else printf(" ");
        }
    }
    printf("\n-----------------------------------------------------------");
    printf("\nPoltronas meias vendidas....: %d.", meia);
    printf("\nPoltronas inteiras vendidas....: %d.", inteira);
    printf("\n-----------------------------------------------------------");
    printf("\nFIM OCUPACAO\n");
}

/* Vender ingresso */
void vender_ingresso(char nomeArq[], char **p){
  int poltronaInt, fileira, coluna, t;
  char tipo;
  //p = matriz plateia

  mostra_plateia(p);
  printf("\nVENDA DE INGRESSOS\n");
  printf("-----------------------------------------------------------\n");

  printf("\nDigite o numero da poltrona <1..120> (zero encerra):  ");

  poltronaInt = validacao_int();
  // Verifica se o valor digitado esta entre 0 e 120
  while (t == 0){
  if (poltronaInt > 120 && poltronaInt < 0){
    printf("Valor invalido. Digite um numero entre 0 e 120 (0 cancela)");
    poltronaInt = validacao_int();
  } else t = 1;
  }


  if (poltronaInt == 0) {
        gravaPlateia(nomeArq, p);// Cancela e grava
    } else {
  int coluna_m, linha_m;

  // ver se ela ta ocupada
  int m = 10, n = 12, f = 0, fileira, coluna;
  while(f == 0){
    coluna_m = (poltronaInt - 1) % 12;
    linha_m = (poltronaInt - 1 - coluna_m) / 12;
          if (p[linha_m][coluna_m] == '-'){
            fileira = linha_m;
            coluna = coluna_m;
            f = 1;
          } else {
          //ocupada
            printf("\nPoltrona ocupada. Digite outro numero de poltrona <1..120>:  ");
            poltronaInt = validacao_int();
          }
      }

  tipo = validacao_char();
  p[linha_m][coluna_m] = tipo;


  if (tipo == 'm' || tipo == 'M') printf("\nPoltrona vendida: %d meia.",poltronaInt);
  if (tipo == 'i' || tipo == 'I') printf("\nPoltrona vendida: %d inteira.",poltronaInt);
  printf("\n(Fileira %d, coluna %d.)",fileira+1,coluna+1);
  }
  int saida;
  printf("\nVender outro ingresso? (0: nao; 1:sim)?   ");

  int g = 0;
    while (g == 0){
    saida = validacao_int();
    if (saida == 0){
      g = 1;
      gravaPlateia(nomeArq, p);
      printf("\n-----------------------------------------------------------\n");
      printf("FIM VENDA DE INGRESSOS");


    } else if (saida == 1){
      g = 1;
      vender_ingresso(nomeArq, p);
    }
      else printf("Valor invalido. Vender outro ingresso? (0: nao; 1:sim)?   ");
    }
}


void devolver_ingresso(char nomeArq[], char **p){
    int poltronaInt, fileira, coluna, saida, t;
    char tipo;
    printf("\nCANCELAMENTO DE INGRESSOS\n");
    printf("-----------------------------------------------------------\n");
    printf("\nDigite a poltrona a cancelar (zero encerra):  ");

    poltronaInt = validacao_int();

    while (t == 0){
  if (poltronaInt > 120 && poltronaInt < 0){
    printf("\nValor invalido. Digite um numero entre 0 e 120 (0 cancela)   ");
    poltronaInt = validacao_int();
  } else t = 1;
  }

  if (poltronaInt == 0) {
        gravaPlateia(nomeArq, p);
        }else{


  int coluna_m, linha_m;
  coluna_m = (poltronaInt - 1) % 12;
    linha_m = (poltronaInt - 1 - coluna_m) / 12;

  tipo = p[linha_m][coluna_m];

  int m = 10, n = 12, i = 0 , j = 0, f = 0;
  while(f == 0){


        if(p[linha_m][coluna_m] != '-'){
            fileira = linha_m+1;
            coluna = coluna_m+1;
            f = 1;
          } else {
          //ocupada
            printf("\nPoltrona vazia. Digite outra poltrona:  ");
            poltronaInt = validacao_int();
          }
        }
    p[linha_m][coluna_m] = '-';
    if (tipo == 'm' || tipo == 'M') {printf("\nPoltrona com venda cancelada: %d (meia).",poltronaInt);}
  if (tipo == 'i' || tipo == 'I') {printf("\nPoltrona com venda cancelada: %d (inteira).",poltronaInt);}

  printf("\n(Fileira %d, coluna %d.)",fileira+1,coluna+1);
  printf("\nCancelar outro ingresso? (0: nao; 1:sim)?  ");
  scanf("%d",&saida);
  fflush(stdin);
        }
  if (saida == 0){
    gravaPlateia(nomeArq, p);
    printf("\n-----------------------------------------------------------\n");
    printf("FIM CANCELAMENTO INGRESSOS");
  } else devolver_ingresso(nomeArq, p);

}

/* Função que libera memória alocada para a matriz de m linhas através de ponteiro para ponteiro. */
void mat_free(char **p){
int i, j, m = 10;
for(i = 0 ; i < m ; i++){
    free(p[i]); /* Libera memória alocada para a linha i. */
  }
free(p);
}

/* Menu de opções: */
int menu(char nomeArq[],char **p){
  int i = 0, op;
  char input[10];

  printf("\nMENU\n");
  printf("\n-----------------------------------------------------------\n");
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
          printf("Fim do programa.");
          mat_free(p);
          i = 2;
          return 0;
          break;
        case 1:
          mostra_plateia(p);
          i = 1;
          break;
        case 2:
          mostra_ocupacao(p);
          i = 1;
          break;
        case 3:
          vender_ingresso(nomeArq,p);
          i = 1;
          break;
        case 4:
          i = 1;
          devolver_ingresso(nomeArq, p);
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
  return i;
}

int main(){
  FILE *fp;
  int x = 1, m=10, n=12;
  char nomeArq[] = "vasco.txt";
  char **p;

  p = aloca_plateia();
  gravaPlateia(nomeArq, p);

while (x == 1){
    x = menu(nomeArq, p);
  }


  return 0;
}
