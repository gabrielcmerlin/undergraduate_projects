#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "divisao_string.h"

#define TAM_STRING 100

FILE *abrir_arquivo();

char *readline(FILE *stream);

// Leitura do cabecalho do CSV, usando uma função (divisao_tokens_char) para conseguir separar o nome de cada caracteristica
char **ler_cabecalho(FILE *arq, char **nome_caract, int *qntd_caract);

/*
    Leitura de cada linha do arquivo CSV, usando uma função (divisao_tokens_double) para colocar os valores das caracteristicas de cada vinho num vetor, formando uma matriz. Nela, cada 
    linha representa um vinho e cada colunas, uma característica
*/
double **ler_valores(FILE *arq, double **vinhos, int *qntd_vinhos, int qntd_caract_aux);