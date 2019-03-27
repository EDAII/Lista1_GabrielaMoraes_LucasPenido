/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/
*/

#include "funcoes.h"

int main(int argc, char* argv[]){
  setlocale(LC_ALL, "Portuguese");

  // Variáveis
  int escolha, tamanhoVetor, valorDeBusca, posicao;
  int *vetor = NULL;
  double tempo;
  FILE *gp, *fp;
  clock_t inicio, fim;

  //Instruções
  srand(time(NULL));

  gp = popen(GNUPLOT, "w");
  if (gp == NULL) {
      printf("Erro ao abrir pipe para o GNU plot.\n"
          "Instale com 'sudo apt-get install gnuplot'\n");
      exit(0);
  }

  fp = fopen("dados.txt", "w+");
  if(fp == NULL){
    printf("Erro ao abrir o arquivo");
    exit(0);
  }

  do{
    escolha = menuPrincipal();
    switch(escolha){
      case BUSCA:
        tamanhoVetor = menuTamanho();
        vetor = alocaVetor(vetor, tamanhoVetor);
        inicio = clock();
        vetor = preencheVetorAleatorio(vetor, tamanhoVetor);
        fim = clock();
        printf("\n==================== Imprimindo Vetor =============================================================\n\n");
        imprimeVetorEmTabela(vetor, tamanhoVetor);
        printf("\n\n=================================================================================================");
        printf("\n\nTempo para o preenchimento do vetor sem números repetidos: %lf s\n\n", ((double)(fim-inicio)/CLOCKS_PER_SEC));

        do{
          valorDeBusca = selecionaValorDeBusca();
          // Busca Sequencial Com Sentinela (Gabriela)
          if(valorDeBusca != -1){
            inicio = clock();
            vetor = (int*) realloc(vetor, ((tamanhoVetor+1) * sizeof(int)));
            posicao = buscaSequencialSentinela(vetor, valorDeBusca, tamanhoVetor);
            fim = clock();
            tempo = ((double)(fim-inicio)/CLOCKS_PER_SEC);
            printf("\n\nTempo para buscar o valor utilizando o método de BUSCA SEQUENCIAL COM SENTINELA: %lf s\n", tempo);
            imprimeResultadoBuscaSequencialSentinela(posicao, valorDeBusca);
            fprintf(fp, "%d\t%lf\n",tamanhoVetor, tempo);
          }
        }while(valorDeBusca != -1);


        fprintf(gp, "plot 'dados.txt'\n");

        // Busca Sequencial Indexada (Penido)

        // Busca Binária (Penido)

        // Jump Search (Gabriela)s

        // Exponential Search (Penido)

        // Grafico (Gabriela)

        // printf("\nAperte ENTER para voltar para o Menu... ");
        // LIMPA_BUFFER;
        // getchar();
      break;
      case SAIR:
      LIMPA_TELA;
      printf("Liberando vetor");
      free(vetor);
      printf("\nFechando Arquivos");
      fclose(fp);
      pclose(gp);
      printf("\nPrograma finalizado!\n");
      break;
    }
  }while(escolha != SAIR);

  return 0;
}
