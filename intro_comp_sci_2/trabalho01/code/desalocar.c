#include "desalocar.h"

void desalocar_nomes(int qntd_caract, char **nomes){
    for(int i = 0; i < qntd_caract; i++){
        free(nomes[i]);
    }
    free(nomes);
}

void desalocar_matriz(int qntd_vinhos, int qntd_caract, double **matriz){
    for(int i = 0; i < qntd_vinhos; i++){
        free(matriz[i]);
    }
    free(matriz);
}