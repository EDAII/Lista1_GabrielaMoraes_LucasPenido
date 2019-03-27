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

  do{
    escolha = menuPrincipal();
    switch(escolha){
      case BUSCA:
        fp = abreArquivo(fp);
        gp = abreGNU(gp);
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
            fprintf(gp, "set title 'Busca Sequencial com Sentinela'\n");
            fprintf(gp, "set xlabel 'Tempo'\n");
            fprintf(gp, "set ylabel 'Posição'\n");
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
                if(posicao != -1){
                  fprintf(fp, "%lf\t%d\n", tempoBuscaSequencialSentinela, posicao);
                }
              }
            }while(valorDeBusca != -1);
            vetor = (int*) realloc(vetor, ((tamanhoVetor-1) * sizeof(int)));
            fprintf(gp, "plot 'dados.txt' with lines\n");
            fclose(fp);
            pclose(gp);
          break;
          case 2:
          // Busca Sequencial Indexada (Penido)
          fprintf(gp, "set title 'Busca Sequencial Indexada'\n");
          fprintf(gp, "set xlabel 'Tempo'\n");
          fprintf(gp, "set ylabel 'Posição'\n");
          break;
          case 3:
          // Busca Binária (Penido)
          fprintf(gp, "set title 'Busca Binária'\n");
          fprintf(gp, "set xlabel 'Tempo'\n");
          fprintf(gp, "set ylabel 'Posição'\n");
          break;
          case 4:
          // Jump search (Gabriela)
            fprintf(gp, "set title 'Jump Search'\n");
            fprintf(gp, "set xlabel 'Tempo'\n");
            fprintf(gp, "set ylabel 'Posição'\n");
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
                if(posicao != -1){
                  fprintf(fp, "%lf\t%d\n", tempoJumpSearch, posicao);
                }
              }
            }while(valorDeBusca != -1);
            fprintf(gp, "plot 'dados.txt' with lines\n");
            fclose(fp);
            pclose(gp);
          break;
          case 5:
          // Busca Exponencial (Penido)
            fprintf(gp, "set title 'Busca Exponencial'\n");
            fprintf(gp, "set xlabel 'Tempo'\n");
            fprintf(gp, "set ylabel 'Posição'\n");
          break;
        }
      break;
      case SAIR:
      LIMPA_TELA;
      printf("Liberando vetor");
      free(vetor);
      printf("\nPrograma finalizado!\n");
      break;
    }
  }while(escolha != SAIR);

  return 0;
}
