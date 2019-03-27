/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/
*/

#include "funcoes.h"

int menuPrincipal(){
  //Variaveis
  int opcao;

  //Instruções
  // LIMPA_TELA;
  printf("================ Métodos de Busca ====================");
  printf("\n1 - Realizar Busca");
  printf("\n0 - Sair");
  do{
    printf("\nDigite a opção que deseja realizar: ");
    LIMPA_BUFFER;
    scanf("%d", &opcao);
  }while(opcao >= 2);

  return opcao;
}


int menuTamanho(){

  //Variaveis
  int escolha;

  //Instruções
  LIMPA_TELA;
  printf("================ Selecione o Tamanho do Vetor ====================");
  printf("\n1 - 10 Elementos");
  printf("\n2 - 100 Elementos");
  printf("\n3 - 1.000 Elementos");
  printf("\n4 - 5.000 Elementos");
  printf("\n5 - 10.000 Elementos");
  printf("\n6 - 25.000 Elementos");
  printf("\n7 - 50.000 Elementos");
  printf("\n8 - 75.000 Elementos");
  printf("\n9 - 100.000 Elementos");
  printf("\n10 - 500.000 Elementos");
  printf("\n11 - 1.000.000 Elementos");
  do{
    printf("\nDigite a opção que deseja realizar: ");
    LIMPA_BUFFER;
    scanf("%d", &escolha);
  }while(escolha <= 0 || escolha >= 12);

  escolha = converteOpcaoEmTamanho(escolha);

  return escolha;
}

int converteOpcaoEmTamanho(int opcaoTamanho){
  switch(opcaoTamanho){
    case 1:
    opcaoTamanho = TAMANHO_1;
    break;
    case 2:
    opcaoTamanho = TAMANHO_2;
    break;
    case 3:
    opcaoTamanho = TAMANHO_3;
    break;
    case 4:
    opcaoTamanho = TAMANHO_4;
    break;
    case 5:
    opcaoTamanho = TAMANHO_5;
    break;
    case 6:
    opcaoTamanho = TAMANHO_6;
    break;
    case 7:
    opcaoTamanho = TAMANHO_7;
    break;
    case 8:
    opcaoTamanho = TAMANHO_8;
    break;
    case 9:
    opcaoTamanho = TAMANHO_9;
    break;
    case 10:
    opcaoTamanho = TAMANHO_10;
    break;
    case 11:
    opcaoTamanho = TAMANHO_11;
    break;
  }

  return opcaoTamanho;
}

int* alocaVetor(int *vetor, int tamanho){
  // Variáveis

  // Instruções
  vetor = (int *) malloc (tamanho * sizeof(int));
  if(vetor == NULL){
    printf("\n\nFalha na alocação do vetor!");
    exit(0);
  }

  return vetor;
}

int* preencheVetorAleatorio(int *vetor, int tamanho){
  // Variáveis
  int i, aux, status;
  // Instruções
  for (i = 0; i < tamanho; i++) {
     do {
       vetor[i] = rand() % 1000000 + 1;
       status =  NREPETIDO;
       for (aux = 0; (aux < i) && (status == NREPETIDO); aux++){
           if (vetor[i] == vetor[aux])
              status = REPETIDO;
        }
     } while (status == REPETIDO);
  }
  return vetor;
}

void imprimeVetorEmTabela(int *vetor, int tamanho){
  // Variáveis
  int i;
  // Instruções
  for(i = 0; i < tamanho; i++){
    if(vetor[i] < 10){
      printf("%d      |", vetor[i]);
    }
    if(vetor[i] >= 10 && vetor[i] < 100){

      printf("%d     |", vetor[i]);
    }
    if(vetor[i] >= 100 && vetor[i] < 1000){
      printf("%d    |", vetor[i]);
    }
    if(vetor[i] >= 1000 && vetor[i] < 10000){
      printf("%d   |", vetor[i]);
    }
    if(vetor[i] >= 10000 && vetor[i] < 100000){
      printf("%d  |", vetor[i]);
    }
    if(vetor[i] >= 100000 && vetor[i] < 1000000){
      printf("%d |", vetor[i]);
    }
    if(vetor[i] == 100000){
      printf("%d|", vetor[i]);
    }
  }
}

int selecionaValorDeBusca(){

  //Variaveis
  int valorDeBusca;

  //Instruções
  do{
    printf("\nDigite o valor que você quer buscar no vetor (Caso deseje encerrar a busca digite -1): ");
    LIMPA_BUFFER;
    scanf("%d", &valorDeBusca);
  }while(valorDeBusca < -1);

  return valorDeBusca;
}

int buscaSequencialSentinela(int *vetor, int valorDeBusca, int tamanho){
  //Variaveis
  int i;
  //Instruções
  vetor[tamanho] = valorDeBusca;
  for (i = 0; valorDeBusca != vetor[i]; i++);
    if (i < tamanho) return (i);
    else return (-1);
}

void imprimeResultadoBuscaSequencialSentinela(int posicao, int valorDeBusca){
  if(posicao != -1){
    printf("------------------------------------------");
    printf("\n|Valor %d encontrado na posicão: %d |\n", valorDeBusca, posicao);
    printf("------------------------------------------");
  }
  else{
    printf("---------------------------------------");
    printf("\n|O valor %d não está presente no vetor.|\n", valorDeBusca);
    printf("---------------------------------------");
  }
}
