/*
    Módulo responsável pela struct aluno_t e pela realização de operações sobre as variáveis desse
    tipo, como sua criação, destruição, atribuição de valor à um campo e também sua consulta.
*/

#ifndef ALUNO_H
#define ALUNO_H

// Tamanho máximo que a string armazenada no campo nusp da struct aluno_t pode ter.
#define TAM_STRING 50

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Quantidade máxima de valores (floats) que o campo notas (vetor) da struct aluno_t pode ter.
#define N_NOTAS 4

typedef struct aluno_ aluno_t;

// Aloca memória para uma variável do tipo aluno_t, depois retorna um ponteiro para ela.
aluno_t *criar_aluno();

// Atribui uma string para o campo nusp de uma variável do tipo aluno_t.
void set_nusp(aluno_t *aluno, char *nusp);

// Atribui um unsigned int para o campo senha de uma variável do tipo aluno_t.
void set_senha(aluno_t *aluno, unsigned int senha);

// Atribui um vetor de floats para o campo notas de uma variável do tipo aluno_t.
void set_notas(aluno_t *aluno, float *notas);

// Atribui um ponteiro de aluno_t para o campo prox de uma variável do tipo aluno_t.
void set_prox(aluno_t *atual, aluno_t *prox);

// Retorna a string armazenada no campo nusp de uma variável do tipo aluno_t.
char *get_nusp(aluno_t *aluno);

// Retorna um unsigned int armazenado no campo senha de uma variável do tipo aluno_t.
unsigned int get_senha(aluno_t *aluno);

// Retorna um vetor de floats armazenado no campo notas de uma variável do tipo aluno_t.
float *get_notas(aluno_t *aluno);

// Retorna um ponteiro de aluno_t armazenado no campo prox de uma variável do tipo aluno_t.
aluno_t *get_prox(aluno_t *atual);

// Desaloca toda a memória usada por uma variável do tipo aluno_t.
void destruir_aluno(aluno_t **a);

#endif