/*
    Módulo responsável por se comunicar com o usuário, seja lendo INPUTS seja
    interpretando os retornos das funções de outros módulos e criando OUTPUTS,
    no formato desejado/pedido pelo exercício, para informar o usuário da
    situação atual da Hash Table.
*/

#ifndef ENTRADA_SAIDA_H
#define ENTRADA_SAIDA_H

#include "aluno.h"
#include "hash_table.h"

/*
    Lê todas as informações sobre os alunos, armazena-as em variáveis do
    tipo aluno_t e depois tenta inserí-las, chamando uma função de outro
    módulo, na Hash Table.
    
    Sendo possível ou não essa insersão, informaremos
    o usuário sobre isso.
*/
void ler_alunos(aluno_t **hash_table, int n_alunos, int tam_hash);

/*
    Faz uma procura do aluno pedido na Hash Table chamando uma função de
    outro módulo.
    
    Caso ele não exista, informamos que o NUSP informado é inválido.
    Caso contrário, comparamos a senha passada com a armazenada na
    Hash Table, se baterem, informamos todas as notas do aluno, mas se
    forem distintas informamos que a senha digitada está errada.
*/
void fazer_login(aluno_t **hash_table, int n_logins, int tam_hash);

#endif