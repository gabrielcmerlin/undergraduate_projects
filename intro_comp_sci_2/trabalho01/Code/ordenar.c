#include "ordenar.h"

void swap(double **matriz, int index_menor, int index_maior, int qntd_caract){
    double aux;

    // Aproveitando que os valores estão numa matriz, esse loop serve para fazer o swap em todas as colunas das linhas selecionadas
    for(int i = 0; i < qntd_caract; i++){
        aux = matriz[index_menor][i];
        matriz[index_menor][i] = matriz[index_maior][i];
        matriz[index_maior][i] = aux;
    }
}

void ordenacao_matriz(double **matriz, int qntd_vinhos, int qntd_caract, int selecionada){
    int index_maior_valor;

    for(int i = (qntd_vinhos - 1); i > 0; i--){
        index_maior_valor = i;

        for(int j = (i - 1); j >= 0; j--){
            if(matriz[j][selecionada] > matriz[index_maior_valor][selecionada]){
                // Caso em que o valor do vinho j é maior que o maior valor já visto
                index_maior_valor = j;
            }else if((matriz[j][selecionada] == matriz[index_maior_valor][selecionada]) && (matriz[j][0] > matriz[index_maior_valor][0])){
                // Caso em que o valor do vinho j é igual ao valor do maior vinho já visto. Nele, precisamos ordenar pelo Id (posição [x][0]) também
                index_maior_valor = j;
            }
        }

        /*
            Só faço swap quando index_maior_valor != i, porque caso index_maior_valor == 1, o maior valor atual já está na sua posição final, logo estaria fazendo um swap entre
            posições iguais
        */
        if(index_maior_valor != i){
            swap(matriz, i, index_maior_valor, qntd_caract);
        }
    }
}