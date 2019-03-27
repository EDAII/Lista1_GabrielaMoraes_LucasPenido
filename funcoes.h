/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define LIMPA_TELA system("clear")
#define LIMPA_BUFFER __fpurge(stdin)
#define BUSCA 1
#define SAIR  0
#define REPETIDO 0
#define NREPETIDO 1
#define TAMANHO_1 10
#define TAMANHO_2 100
#define TAMANHO_3 1000
#define TAMANHO_4 5000
#define TAMANHO_5 10000
#define TAMANHO_6 25000
#define TAMANHO_7 50000
#define TAMANHO_8 75000
#define TAMANHO_9 100000
#define TAMANHO_10 500000
#define TAMANHO_11 1000000
#define GNUPLOT "gnuplot -persist"


int menuPrincipal();
int menuTamanho();
int menuBusca();
int converteOpcaoEmTamanho(int);
int* alocaVetor(int *, int);
int* preencheVetorAleatorio(int *, int);
void imprimeVetorEmTabela(int *, int);
int selecionaValorDeBusca();
int buscaSequencialSentinela(int *, int, int);
void imprimeResultadoDaBusca(int, int);
void realizaSwap(int *, int *);
void bubbleSort(int *, int);
int jumpSearch(int *, int , int);
