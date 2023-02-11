#include "arquivos.h"

FILE *abrir_arquivo(){
    char *nome_arq;
    FILE *arq;

    nome_arq = readline(stdin);
    arq = fopen(nome_arq, "r");
    assert(arq != NULL);
    free(nome_arq);

    return arq;
}

char *readline(FILE *stream){
    int tamanho_string = 20;

    char *string = malloc(sizeof(char) * tamanho_string);
    int caracteres_lidos = 0;

    do{
        //Se lotamos o espaço que a string tem disponível, duplicamos seu tamanho
        if(caracteres_lidos == tamanho_string){
            tamanho_string *= 2;
            string = realloc(string, sizeof(char) * tamanho_string);
        }

        //Ler o próximo caractere
        char c = fgetc(stream);

        //Verificar se a linha acabou
        if(c == '\r') continue;
        if(c == '\n' || c == EOF){
            //Finalizar a string           
            string[caracteres_lidos] = '\0';

            break;
        }

        //Adicionar o caractere lido à string
        string[caracteres_lidos] = c;
        caracteres_lidos++;
    } while(!feof(stream));

    string = realloc(string, sizeof(char) * (caracteres_lidos + 1));
    
    return string;
}

char **ler_cabecalho(FILE *arq, char **nome_caract, int *qntd_caract){
    char string_aux[TAM_STRING];

    fscanf(arq, "%s", string_aux);
    nome_caract = divisao_tokens_char(string_aux, nome_caract, qntd_caract);

    return nome_caract;
}

double **ler_valores(FILE *arq, double **vinhos, int *qntd_vinhos, int qntd_caract_aux){
    char string_aux[TAM_STRING];

    for((*qntd_vinhos) = 0; feof(arq) == 0; (*qntd_vinhos)++){
        vinhos = (double **) realloc(vinhos, ((*qntd_vinhos) + 1) * sizeof(double *));
        fscanf(arq, "%s", string_aux);
        
        vinhos[(*qntd_vinhos)] = divisao_tokens_double(string_aux, vinhos[(*qntd_vinhos)], &qntd_caract_aux);
    }

    return vinhos;
}