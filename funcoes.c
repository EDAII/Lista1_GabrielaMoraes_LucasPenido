/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include "funcoes.h"

FILE* abreArquivo(FILE *fp){
  fp = fopen("dados.txt", "w+");
  if(fp == NULL){
    printf("Erro ao abrir o arquivo");
    exit(0);
  }
  return fp;
}

FILE* abreGNU(FILE *gp){
  gp = popen(GNUPLOT, "w");
  if (gp == NULL) {
      printf("Erro ao abrir pipe para o GNU plot.\n"
          "Instale com 'sudo apt-get install gnuplot'\n");
      exit(0);
  }

  return gp;
}

int menuPrincipal(){
  //Variaveis
  int opcao;

  //Instruções
  LIMPA_TELA;
  printf("================ Métodos de Busca ====================");
  printf("\n\n1 - Realizar Busca");
  printf("\n0 - Sair");
  printf("\n\nOBS: O gráfico será plotado com pelo menos UMA busca com elemento encontrado. Porém, para melhores resultados utilize pelo menos DUAS buscas.");
  do{
    printf("\n\nDigite a opção que deseja realizar: ");
    LIMPA_BUFFER;
    scanf("%d", &opcao);
  }while(opcao >= 2);

  return opcao;
}

int menuBusca(){

  //Variaveis
  int escolha;

  //Instruções
  LIMPA_TELA;
  printf("================ Selecione o Método de Busca ====================");
  printf("\n1 - Busca Sequencial com Sentinela");
  printf("\n2 - Busca Sequencial Indexada");
  printf("\n3 - Busca Binária");
  printf("\n4 - Jump Search");
  printf("\n5 - Busca Exponencial");
  do{
    printf("\nDigite a opção que deseja realizar: ");
    LIMPA_BUFFER;
    scanf("%d", &escolha);
  }while(escolha <= 0 || escolha >= 6);


  return escolha;
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
  int i, aux, status, inicio;
  // Instruções
  inicio = clock();
  int tempInit = 0;
  int tempAtual;
  for (i = 0; i < tamanho; i++) {
     do {
       vetor[i] = rand() % 1000000 + 1;
       status =  NREPETIDO;
       for (aux = 0; (aux < i) && (status == NREPETIDO); aux++){
           if (vetor[i] == vetor[aux])
              status = REPETIDO;
        }
     } while (status == REPETIDO);
     tempAtual = ((clock()-inicio)/CLOCKS_PER_SEC);
     if (tempAtual != tempInit) {
      printf("%.0f%%\n", ((double)i/(double)tamanho)*100);
      tempInit = ((clock()-inicio)/CLOCKS_PER_SEC);
     }
  }
  return vetor;
}

void imprimeVetorEmTabela(int *vetor, int tamanho){
  // Variáveis
  int i;
  // Instruções
  printf("\n");
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

void imprimeResultadoDaBusca(int posicao, int valorDeBusca){
  //Variaveis

  //Instruções
  if(posicao != -1){
    printf("\n------------------------------------------");
    printf("\n|Valor %d encontrado na posicão: %d |\n", valorDeBusca, posicao);
    printf("------------------------------------------");
  }
  else{
    printf("\n---------------------------------------");
    printf("\n|O valor %d não está presente no vetor.|\n", valorDeBusca);
    printf("---------------------------------------");
  }
}

void realizaSwap(int *anterior, int *proximo){
  //Variaveis
  int aux;

  //Instruções
  aux = *anterior;
  *anterior = *proximo;
  *proximo = aux;
}

void bubbleSort(int *vetor, int tamanho){
  //Variaveis
  int i, j;

  //Instruções
   for (i = 0; i < tamanho-1; i++){
     for (j = 0; j < tamanho-i-1; j++){
       if (vetor[j] > vetor[j+1]){
         realizaSwap(&vetor[j], &vetor[j+1]);
       }
     }
   }
}

/* Função com a implementação do algorítmo de ordenação Quick Sort. */
void quickSort(int *vetor, int start, int end){
    if (start < end) {

        /* O pivo sempre será o primeiro elemento da partição não ordenada. */
        int pivo = start, flag = pivo + 1, i, aux;

        for (i = pivo + 1; i <= end; i++) {
            if (vetor[i] < vetor[pivo]) {
                if (flag != i) {
                    aux = vetor[i];
                    vetor[i] = vetor[flag];
                    vetor[flag] = aux;
                }
                flag++;
            }
        }

        aux = vetor[pivo];
        vetor[pivo] = vetor[flag - 1];
        vetor[flag - 1] = aux;

        quickSort(vetor, start, flag-2);
        quickSort(vetor, flag, end);
    }
}

int jumpSearch(int *vetor, int tamanhoVetor, int valorDeBusca){
  //Variaveis
  int tamanhoBloco, anterior = 0;

  //Instruções
  tamanhoBloco = sqrt(tamanhoVetor);

  // Encontrar o bloco onde o valor deve estar
  while(vetor[tamanhoBloco] <= valorDeBusca && tamanhoBloco < tamanhoVetor){
    anterior = tamanhoBloco;
    tamanhoBloco += sqrt(tamanhoVetor);
    if (anterior >= tamanhoVetor) {
      return -1;
    }
  }

  // Busca linear no bloco selecionado
  for(int i = anterior; i < tamanhoVetor; i++) {
    if(vetor[i] == valorDeBusca){
      return i;
    }
  }

  return -1;
}

/* Função para busca binária. */
int binarySearch(int *vetor, int comecoVetor, int fimVetor, int valorDeBusca){

  if (fimVetor >= comecoVetor)
  {
      int mid = comecoVetor + (fimVetor - comecoVetor)/2;

      // If the element is present at the middle
      // itself
      if (vetor[mid] == valorDeBusca)
          return mid;

      // If element is smaller than mid, then it
      // can only be present n left subarray
      if (vetor[mid] > valorDeBusca)
          return binarySearch(vetor, comecoVetor, mid-1, valorDeBusca);

      // Else the element can only be present
      // in right subarray
      return binarySearch(vetor, mid+1, fimVetor, valorDeBusca);
  }

  // We reach here when element is not present
  // in array
  return -1;
}

int buscaSequencialIndexada(int *vetor, int tamanho, int valorDeBusca) {

  int i, x = 0, aux, *vetorAux;
  int passo, index = 0;
  int tamanhoVetorAux, fimSetor;

  // Conta quantas casas decimais tem o tamanho do vetor de busca.
  for (i = 1, aux = 10; tamanho/aux > 0; i++, aux*=10);

  // Cosideramos que o tamanho do vetor auxiliar terá tamanho = 2^(quantidade de casas decimais do original).
  tamanhoVetorAux = pow(2,i);

  passo = (tamanho/tamanhoVetorAux);

  vetorAux = (int *) malloc ((tamanhoVetorAux) * sizeof(int));

  // Preenche o vetor auxiliar
  for (int j = 0; j < tamanhoVetorAux; j++) {
      vetorAux[j] = vetor[passo * (j + 1)];
      // printf("vetorAux[%d] = vetor[%d] => %d\n", j, passo * (j + 1),  vetor[passo * (j + 1)]);
  }

  // Percorre o vetor auxiliar até o fim ou até achar um número menor no vetor de busca para definir o valor
  // inicial do setor que ocorrerá a busca.
  while (valorDeBusca >= vetorAux[x] && x < tamanhoVetorAux) {
    x++;
    index = x * passo;
  }

  // Caso o próximo passo seja maior que o tamanho do vetor de busca o final do setor a ser procurado é o tamanho
  // do arquivo de busca, caso o contrário o finaal do setor será o próximo passo.
  if (index + passo > tamanho) {
    fimSetor = tamanho;
  } else {
    fimSetor = index + passo;
  }

  // Percorre o vetor de busca com o setor definido
  if (x <= tamanhoVetorAux) {
    for (int b = index; b < fimSetor; b++) {
      if (vetor[b] == valorDeBusca) {
        return b;
      }
    }
  }

  return -1;
}

int buscaExponencial(int *vetor, int tamanho, int valorDeBusca) {
  int i = 1;

  // Caso o número procurado esteja na primeira posição.
    if (vetor[0] == valorDeBusca)
        return 0;

    // Find range for binary search by
    // repeated doubling
    // Define o intervalo para a busca binária
    while (i < tamanho && vetor[i] <= valorDeBusca)
        i = i*2;

    // Chama a busca binária no intervalo definido.
    return binarySearch(vetor, i/2, fmin(i, tamanho), valorDeBusca);
}

void copiaVetor(int *vetor1, int *vetor2, int tamanho) {
  //Variaveis
  int i, j;

  //Instruções
   for (i = 0; i < tamanho; i++){
     // for (j = 0; j < tamanho; j++){
       *(vetor2 + i) = *(vetor1 + i);
     // }
   }
}
