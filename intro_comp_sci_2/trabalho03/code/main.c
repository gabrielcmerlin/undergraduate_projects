/*
    Disciplina: SCC0201 - Introdução à Ciência de Computação II
    Nome: Gabriel da Costa Merlin
    NUSP: 12544420
*/

#include <stdio.h>
#include "aluno.h"
#include "hash_table.h"
#include "entrada_saida.h"

int main(void){
    // Lendo a quantidade de alunos que nossa Hash Table armazenará.
    int n_alunos;
    scanf(" %d", &n_alunos);

    // Encontrando o tamanho da nossa Hash Table e criando-a.
    int tam_hash = encontrar_tam_hash(n_alunos);
    aluno_t **hash_table = criar_hash_table(tam_hash);

    // Lendo as informações de nossos alunos e armazenando-as na Hash Table.
    ler_alunos(hash_table, n_alunos, tam_hash);
    
    // Lendo quantos logins serão feitos.
    int n_logins;
    scanf(" %d", &n_logins);
    
    // Tentando fazer os logins pedidos.
    fazer_login(hash_table, n_logins, tam_hash);

    // Desalocando a memória usada pela Hash Table.
    destruir_hash(&hash_table, tam_hash);
}