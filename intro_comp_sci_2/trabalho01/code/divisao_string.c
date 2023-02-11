#include "divisao_string.h"

char **divisao_tokens_char(char *string, char **valores, int *qntd_valores){
    char *pt;
    valores = NULL;

    pt = strtok(string, DELIMITADOR);
    for(*qntd_valores = 0; pt != NULL; (*qntd_valores)++){
        valores = (char **) realloc(valores, ((*qntd_valores) + 1) * sizeof(char *));
        valores[*qntd_valores] = (char *) malloc(sizeof(char) * (strlen(pt) + 1));
        strcpy(valores[*qntd_valores], pt);

        pt = strtok(NULL, DELIMITADOR);
    }

    return valores;
}

double *divisao_tokens_double(char *string, double *valores, int *qntd_valores){
    char *pt;
    valores = NULL;

    pt = strtok(string, DELIMITADOR);
    for(*qntd_valores = 0; pt != NULL; (*qntd_valores)++){
        valores = (double *) realloc(valores, ((*qntd_valores) + 1) * sizeof(double));
        valores[*qntd_valores] = atof(pt);

        pt = strtok(NULL, DELIMITADOR);
    }

    return valores;
}