#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITADOR ","

// Função criada para conseguir dividir a linha do cabeçalho em diferentes strings, a fim de facilitar o seu uso ao decorrer do programa
char **divisao_tokens_char(char *string, char **valores, int *qntd_valores);

// Função criada para dividir cada linha do CSV em diferentes floats, que serão armazenados numa matriz para que possa ser realizada a ordenação e busca dos vinhos
double *divisao_tokens_double(char *string, double *valores, int *qntd_valores);