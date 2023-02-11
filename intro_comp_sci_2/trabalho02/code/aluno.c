#include "aluno.h"

struct aluno_ {
    char nome[TAM_STRING];
    int *notas;
    float media;
    /*
        Armazena o critério usado para afirmar que o aluno atual é melhor que o próximo. Legenda:
            -1: ainda não julgado
            0: melhor devido à média
            i > 0: i é a prova na qual o aluno atual foi melhor que o próximo
    */
    int criterio_desempate;
};

aluno_t *criar_aluno(){
    aluno_t *aluno = (aluno_t *) malloc(1 * sizeof(aluno_t));
    assert(aluno != NULL);

    return aluno;
}

void set_nome(aluno_t *aluno, char *nome){
    assert(aluno != NULL);

    strcpy(aluno->nome, nome);   
}

void set_notas(aluno_t *aluno, int *notas){
    assert(aluno != NULL);

    aluno->notas = notas;
}

void set_media(aluno_t *aluno, float media){
    assert(aluno != NULL);

    aluno->media = media;
}

void set_criterio(aluno_t *aluno, int criterio){
    assert(aluno != NULL);

    aluno->criterio_desempate = criterio;
}

char *get_nome(aluno_t *aluno){
    assert(aluno != NULL);

    return aluno->nome;  
}

int *get_notas(aluno_t *aluno){
    assert(aluno != NULL);

    return aluno->notas;
}

float get_media(aluno_t *aluno){
    assert(aluno != NULL);

    return aluno->media;
}

int get_criterio(aluno_t *aluno){
    assert(aluno != NULL);

    return aluno->criterio_desempate;
}

void apagar_aluno(aluno_t **aluno){
    free(*aluno);
    *aluno = NULL;
}

float get_maior_media(aluno_t **vetor_alunos, int qntd_alunos){
    // Índice do aluno que possui a maior média entre os verficados até o momento
    int aluno_maior_media = 0;

    // Loop que percorre todo o vetor de alunos
    for(int i = 1; i < qntd_alunos; i++){
        // Condição que verifica se a média do aluno atual é maior que maior média registrada até o momento
        if(get_media(vetor_alunos[i]) > get_media(vetor_alunos[aluno_maior_media])){
            // Caso seja, atualizamos o índice do aluno de maior média
            aluno_maior_media = i;
        }
    }

    return get_media(vetor_alunos[aluno_maior_media]);
}