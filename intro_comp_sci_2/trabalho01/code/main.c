/*
    Nome: Gabriel da Costa Merlin
    NUSP: 12544420
    Disciplina: Introdução à Ciência de Computação II
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arquivos.h"
#include "buscar.h"
#include "desalocar.h"
#include "divisao_string.h"
#include "ordenar.h"

int main(void){
    // Abertura do arquivo CSV a ser lido
    FILE *arq = abrir_arquivo();

    // Leitura do cabecalho do CSV
    int qntd_caract;
    char **nome_caract = NULL;
    nome_caract = ler_cabecalho(arq, nome_caract, &qntd_caract);

    // Leitura dos valores das caracteristicas de cada vinho
    int qntd_vinhos;
    double **vinhos = NULL;
    vinhos = ler_valores(arq, vinhos, &qntd_vinhos, qntd_caract);

    // Fechamento do arquivo CSV, porque, após sua leitura total, ele não será mais usado
    fclose(arq);

    // Leitura do número de buscas a serem feitas
    int n_buscas;
    scanf("%d ", &n_buscas);

    // Loop para realizar a quantidade de buscas, logo também de ordenações, pedidas na entrada
    char caract_selec[TAM_STRING];
    int selecionada;
    for(int i = 0; i < n_buscas; i++){
        scanf("%s ", caract_selec);

        // Loop responsavel por transformar a string da caracteristica selecionada num index, a fim facilitar na ordenação de busca
        for(int i = 0; i < qntd_caract; i++){
            if(strcmp(caract_selec, nome_caract[i]) == 0){
                selecionada = i;
            }
        }

        // Como será usada Busca Binária, os valores devem estar previamente ordenados segundo a característica selecionada
        ordenacao_matriz(vinhos, qntd_vinhos, qntd_caract, selecionada);

        // Agora, com a matriz ordenada, pode-se fazer a busca
        double chave;
        scanf("%lf ", &chave);

        busca(vinhos, qntd_vinhos, qntd_caract, selecionada, chave);
    }

    // Desalocando memória
    desalocar_nomes(qntd_caract, nome_caract);
    desalocar_matriz(qntd_vinhos, qntd_caract, vinhos);

    return 0;
}