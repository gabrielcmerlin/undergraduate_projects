/*
    Nome: Gabriel da Costa Merlin
    NUSP: 12544420
    Disciplina: Introdução à Ciência de Computação II
*/

#include <stdio.h>
#include "aluno.h"
#include "entrada_saida.h"
#include "ordenacao.h"

int main(void){
    int qntd_alunos, qntd_provas;

    scanf(" %d %d", &qntd_alunos, &qntd_provas);

    // Lendo o nome e as nota de todos os alunos e guardando essas informações num vetor de structs (aluno_t)
    aluno_t **vetor_alunos = ler_vetor_alunos(qntd_alunos, qntd_provas);

    // Realizando a ordenação de acordo com o especificado
    torneioGeralSort(vetor_alunos, qntd_alunos, qntd_provas);

    // Imprimindo o vetor de alunos logo após a ordenação
    imprimir_saida(vetor_alunos, qntd_alunos, qntd_provas);

    // Liberando a memória alocada para o vetor de alunos
    apagar_vetor_alunos(vetor_alunos, qntd_alunos);

    return 0;
}