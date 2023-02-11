#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

/*
    Para cada aluno existente, essa função faz a leitura de seu nome e de suas notas, armazena essas informações
    numa struct especifica para esse aluno e adiciona essa struct no vetor de structs que será retornado após a
    leitura de todas as informações de todos os alunos. 
*/
aluno_t **ler_vetor_alunos(int qntd_alunos, int qntd_provas);

// Desaloca a memória do vetor de alunos retornado na função 'aluno_t **ler_vetor_alunos'
void apagar_vetor_alunos(aluno_t **vetor_alunos, int qntd_alunos);

// Imprime o nome de todos os alunos junto com a informação de desempate de cada um
void imprimir_saida(aluno_t **vetor_alunos, int qntd_alunos, int qntd_provas);