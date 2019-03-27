/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/
*/

#include "funcoes.h"

int main(int argc, char* argv[]){
  setlocale(LC_ALL, "Portuguese");

  // Variáveis
  int escolha, tamanhoVetor, valorDeBusca, posicao, metodoBusca;
  double tempoOrdenacao, tempoPreenchimento, tempoJumpSearch, tempoBuscaSequencialSentinela;
  int *vetor = NULL;
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
        metodoBusca = menuBusca();
        tamanhoVetor = menuTamanho();
        vetor = alocaVetor(vetor, tamanhoVetor);
        inicio = clock();
        vetor = preencheVetorAleatorio(vetor, tamanhoVetor);
        fim = clock();
        tempoPreenchimento = ((double)(fim-inicio)/CLOCKS_PER_SEC);
        printf("\n==================== Imprimindo Vetor =============================================================\n\n");
        imprimeVetorEmTabela(vetor, tamanhoVetor);
        printf("\n\n=================================================================================================");
        printf("\n\nTempo para o preenchimento do vetor sem números repetidos: %lf s\n\n", tempoPreenchimento);
        printf("\n\nAperte ENTER para continuar... ");
        LIMPA_BUFFER;
        getchar();
        switch(metodoBusca){
          case 1:
          // Busca Sequencial Com Sentinela (Gabriela)
          do{
            valorDeBusca = selecionaValorDeBusca();
            if(valorDeBusca != -1){
              inicio = clock();
              vetor = (int*) realloc(vetor, ((tamanhoVetor+1) * sizeof(int)));
              posicao = buscaSequencialSentinela(vetor, valorDeBusca, tamanhoVetor);
              fim = clock();
              tempoBuscaSequencialSentinela = ((double)(fim-inicio)/CLOCKS_PER_SEC);
              imprimeResultadoDaBusca(posicao, valorDeBusca);
              printf("\n\nTempo para buscar o valor utilizando o método de BUSCA SEQUENCIAL COM SENTINELA: %lf s\n", tempoBuscaSequencialSentinela);
              vetor = (int*) realloc(vetor, ((tamanhoVetor-1) * sizeof(int)));
              fprintf(fp, "%d\t%lf\n",tamanhoVetor, tempoBuscaSequencialSentinela);
            }
            fprintf(gp, "plot 'dados.txt'\n");
          }while(valorDeBusca != -1);
          break;
          case 2:
          // Busca Sequencial Indexada (Penido)
          break;
          case 3:
          // Busca Binária (Penido)
          break;
          case 4:
          // Jump search (Gabriela)
          inicio = clock();
          bubbleSort(vetor, tamanhoVetor);
          fim = clock();
          tempoOrdenacao = ((double)(fim-inicio)/CLOCKS_PER_SEC);
          imprimeVetorEmTabela(vetor, tamanhoVetor);
          printf("\n\nTempo para realizar a ordenação por BUBBLE SORT: %lf s\n", tempoOrdenacao);
          printf("\n\nAperte ENTER para continuar... ");
          LIMPA_BUFFER;
          getchar();
          do{
            valorDeBusca = selecionaValorDeBusca();
            if(valorDeBusca != -1){
              inicio = clock();
              posicao = jumpSearch(vetor, tamanhoVetor, valorDeBusca);
              fim = clock();
              imprimeResultadoDaBusca(posicao, valorDeBusca);
              tempoJumpSearch = ((double)(fim-inicio)/CLOCKS_PER_SEC);
              printf("\n\nTempo para realizar o JUMP SEARCH: %lf s\n", tempoJumpSearch);
              fprintf(fp, "%d\t%lf\n",tamanhoVetor, tempoJumpSearch);
            }
            fprintf(gp, "plot 'dados.txt'\n");
          }while(valorDeBusca != -1);
          break;
          case 5:
          // Busca Exponencial (Penido)
          break;
        }
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
