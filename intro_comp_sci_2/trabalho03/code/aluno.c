#include "aluno.h"

struct aluno_ {
    char nusp[TAM_STRING];
    unsigned int senha;
    float notas[N_NOTAS];
    /*
        O campo prox existe para que possamos tratar de forma mais fácil 
        as colisões da Hash Table por meio de Linked Lists.
    */
    aluno_t *prox;
} ;

aluno_t *criar_aluno(){
    aluno_t *a = (aluno_t *) malloc(1 * sizeof(aluno_t));
    assert(a != NULL);
    
    // Inicializando o seu campo prox como NULL.
    set_prox(a, NULL);

    return a;
}

void set_nusp(aluno_t *aluno, char *nusp){
    assert(aluno != NULL);
    assert(nusp != NULL);

    strcpy(aluno->nusp, nusp);
}

void set_senha(aluno_t *aluno, unsigned int senha){
    assert(aluno != NULL);
    
    aluno->senha = senha;
}

void set_notas(aluno_t *aluno, float *notas){
    assert(aluno != NULL);
    assert(notas != NULL);

    for(int i = 0; i < N_NOTAS; i++){
        aluno->notas[i] = notas[i];
    }
}

void set_prox(aluno_t *atual, aluno_t *prox){
    assert(atual != NULL);

    atual->prox = prox;
}

char *get_nusp(aluno_t *aluno){
    assert(aluno != NULL);

    return aluno->nusp;
}

unsigned int get_senha(aluno_t *aluno){
    assert(aluno != NULL);
    
    return aluno->senha;
}

float *get_notas(aluno_t *aluno){
    assert(aluno != NULL);

    return aluno->notas;
}

aluno_t *get_prox(aluno_t *atual){
    assert(atual != NULL);

    return atual->prox;
}

void destruir_aluno(aluno_t **a){
    free(*a);
    *a = NULL;
}