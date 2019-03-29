/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include "funcoes.h"

int main(int argc, char* argv[]){
  setlocale(LC_ALL, "Portuguese");

  // Variáveis
  int escolha, tamanhoVetor, valorDeBusca, posicao, metodoBusca, posicaoSequencialSentinela;
  double  tempoOrdenacao, tempoPreenchimento, tempoJumpSearch, tempoBuscaSequencialSentinela, tempoBuscaSequencialIndexada,
          tempoBuscaBinaria, tempoBuscaExponencial;
  int *vetor = NULL, *vetorOrdenado = NULL;
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
        // metodoBusca = menuBusca();
        tamanhoVetor = menuTamanho();
        vetor = alocaVetor(vetor, tamanhoVetor);
        vetorOrdenado = alocaVetor(vetorOrdenado, tamanhoVetor);
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

        copiaVetor(vetor, vetorOrdenado, tamanhoVetor);

        printf("\n============================= Ordenando Vetor =============================================================\n\n");
        inicio = clock();
        quickSort(vetorOrdenado, 0, tamanhoVetor - 1);
        fim = clock();
        tempoOrdenacao = ((double)(fim-inicio)/CLOCKS_PER_SEC);
        imprimeVetorEmTabela(vetorOrdenado, tamanhoVetor);
        printf("\n\nTempo para realizar a ordenação por QUICK SORT: %lf s\n", tempoOrdenacao);
        printf("\n\nAperte ENTER para continuar... ");
        LIMPA_BUFFER;
        getchar();

        fprintf(gp, "set title 'Métodos de Busca'\n");
        fprintf(gp, "set xlabel 'Posição'\n");
        fprintf(gp, "set ylabel 'Tempo'\n");
        do{
          valorDeBusca = selecionaValorDeBusca();
          if(valorDeBusca != -1){

            //Sequencial com sentinela
            printf("\n\nRealizando busca sequencial com sentinela");
            vetor = (int*) realloc(vetor, ((tamanhoVetor+1) * sizeof(int)));
            inicio = clock();
            posicaoSequencialSentinela = buscaSequencialSentinela(vetor, valorDeBusca, tamanhoVetor);
            fim = clock();
            tempoBuscaSequencialSentinela = ((double)(fim-inicio)/CLOCKS_PER_SEC);
            vetor = (int*) realloc(vetor, ((tamanhoVetor-1) * sizeof(int)));


            // Busca Sequencial Indexada
            printf("\nRealizando busca sequencial indexada");
            inicio = clock();
            posicao = buscaSequencialIndexada(vetorOrdenado, tamanhoVetor, valorDeBusca);
            fim = clock();
            tempoBuscaSequencialIndexada = ((double)(fim-inicio)/CLOCKS_PER_SEC);


            // Busca binária
            printf("\nRealizando busca binária");
            inicio = clock();
            posicao = binarySearch(vetorOrdenado, 0, tamanhoVetor, valorDeBusca);
            fim = clock();
            tempoBuscaBinaria = ((double)(fim-inicio)/CLOCKS_PER_SEC);

            // Jump Search
            printf("\nRealizando jump search");
            inicio = clock();
            posicao = jumpSearch(vetorOrdenado, tamanhoVetor, valorDeBusca);
            fim = clock();
            tempoJumpSearch = ((double)(fim-inicio)/CLOCKS_PER_SEC);

            // Busca Exponencial
            printf("\nRealizando busca exponencial");
            inicio = clock();
            posicao = buscaExponencial(vetorOrdenado, tamanhoVetor, valorDeBusca);
            fim = clock();
            tempoBuscaExponencial = ((double)(fim-inicio)/CLOCKS_PER_SEC);


            //Resultados
            printf("\n\n=================== Resultado Busca Sequencial com Sentinela===================================");
            imprimeResultadoDaBusca(posicaoSequencialSentinela, valorDeBusca);
            printf("\n\n=================== Resultado das demais ======================================================");
            imprimeResultadoDaBusca(posicao, valorDeBusca);
            printf("\n\n=================== Tempos ======================================================");
            printf("\n\nTempo para buscar o valor utilizando o método de BUSCA SEQUENCIAL COM SENTINELA: %lf s", tempoBuscaSequencialSentinela);
            printf("\nTempo para realizar a BUSCA SEQUENCIAL INDEXADA %lf s -> Total(incluindo ordenação): %lf s", tempoBuscaSequencialIndexada,(tempoBuscaSequencialIndexada+tempoOrdenacao));
            printf("\nTempo para realizar a BUSCA BINÁRIA: %lf s -> Total(incluindo ordenação): %lf s", tempoBuscaBinaria, (tempoBuscaBinaria+tempoOrdenacao));
            printf("\nTempo para realizar o JUMP SEARCH: %lf s -> Total(incluindo ordenação): %lf s", tempoJumpSearch, (tempoJumpSearch+tempoOrdenacao));
            printf("\nTempo para realizar a BUSCA EXPONENCIAL: %lf s -> Total(incluindo ordenação): %lf s\n\n", tempoBuscaExponencial,(tempoBuscaExponencial+tempoOrdenacao));

            if(posicao != -1){
              fprintf(fp, "%d\t%d\t%lf\t%lf\t%lf\t%lf\t%lf\n", posicaoSequencialSentinela, posicao,tempoBuscaSequencialSentinela,tempoBuscaSequencialIndexada,
                                                            tempoBuscaBinaria, tempoJumpSearch, tempoBuscaExponencial);
            }

          }
        }while(valorDeBusca != -1);
        fprintf(gp, "plot 'dados.txt' using 1:3 with linespoints title 'buscaSequencialSentinela',\
                    'dados.txt' using 2:4 with linespoints title 'buscaSequencialIndexada', \
                    'dados.txt' using 2:5 with linespoints title 'buscaBinaria', \
                    'dados.txt' using 2:6 with linespoints title 'jumpSearch', \
                    'dados.txt' using 2:7 with linespoints title 'buscaExponencial'\n");
        fclose(fp);
        pclose(gp);
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
