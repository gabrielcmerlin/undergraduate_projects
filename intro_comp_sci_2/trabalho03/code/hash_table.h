/*
    Módulo responsável por modelar uma Hash Table e implementar diversas
    funções para seu uso eficaz.
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "aluno.h"

// Aloca memória para uma Hash Table (aluno_t **), depois retorna um ponteiro para ela.
aluno_t **criar_hash_table(int tam);

// Recebe a quantidade de elementos que uma Hash Table terá e retorna qual tamanho ela deverá ter.
int encontrar_tam_hash(int n_elementos);

// Função Hash.
unsigned int hash(char *chave);

// Tenta inserir um aluno na Hash Table.
bool inserir_hash(aluno_t **hash_table, aluno_t *aluno, int tam_hash);

// Busca por um aluno na Hash Table.
aluno_t *buscar_hash(aluno_t **hash_table, char *nusp, int tam_hash);

// Desaloca toda a memória usada pela Hash Table.
void destruir_hash(aluno_t ***hash_table, int tam_hash);

#endif