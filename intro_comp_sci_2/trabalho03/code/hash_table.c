#include "hash_table.h"

aluno_t **criar_hash_table(int tam){    
    aluno_t **h = (aluno_t **) malloc(tam  * sizeof(aluno_t *));
    assert(h != NULL);

    // Inicializando todos os espaços da Hash Table como NULL.
    for(int i = 0; i < tam; i++){
        h[i] = NULL;
    }

    return h;
}

int encontrar_tam_hash(int n_elementos){
    int pot = 0;

    // Encontrando qual o expoente da menor potência de 2 que é maior que a quantidade de elementos da Hash Table.
    while(pow(2, pot) <= n_elementos)
        pot++;

    // Retornando a potência de 2 cujo expoente foi encontrado acima.
    return pow(2, pot);
}

unsigned int hash(char *chave){
    // Implementação da Função Hash seguindo o algoritmo passado no PDF do Trabalho 03.

    unsigned short high = 0, low = 1;
    int n_chars = strlen(chave);

    for(int i = 0; i < n_chars; i++){
        low = (low + chave[i]) % 65521;
        high = (high + low) % 65521;
    }

    unsigned int result = (high << 16) | low;

    return result;
}

bool inserir_hash(aluno_t **hash_table, aluno_t *aluno, int tam_hash){
    assert(hash_table != NULL);
    assert(aluno != NULL);

    // Caso o aluno já esteja na Hash Table, retornamos que a inserção atual deu errado (false).
    if(buscar_hash(hash_table, get_nusp(aluno), tam_hash) != NULL) return false;
    
    // Descobrindo em qual posição (Linked List) da Hash Table o aluno deverá ser cadastrado.
    unsigned int index = hash(get_nusp(aluno)) % tam_hash;
    
    if(hash_table[index] == NULL){ // Caso a Linked List esteja vazia:
        // Adicionamos o aluno na primeira posição dela.
        hash_table[index] = aluno;
    }else{ // Caso a Linked List NÃO esteja vazia:
        aluno_t *ultimo_aluno = hash_table[index];

        // Percorremos toda a Linked List.
        while(get_prox(ultimo_aluno) != NULL){
            ultimo_aluno = get_prox(ultimo_aluno);
        }

        // Adicionamos o aluno na última posição dela.
        set_prox(ultimo_aluno, aluno);
    }

    // Depois de tudo, retornamos que a inserção foi um sucesso (true).
    return true;
}

aluno_t *buscar_hash(aluno_t **hash_table, char *nusp, int tam_hash){
    assert(hash_table != NULL);
    assert(nusp != NULL);

    // Descobrindo em qual posição (Linked List) da Hash Table o aluno poderá estar.
    unsigned int index = hash(nusp) % tam_hash;

    // Inicializando a variável auxiliar que nos ajudará a percorrer a Linked List escolhida.
    aluno_t *aluno_aux = hash_table[index];

    // Percorrendo toda a Linked List vendo se o aluno atual é o aluno buscado.
    while(aluno_aux != NULL && strcmp(get_nusp(aluno_aux), nusp) != 0)
        aluno_aux = get_prox(aluno_aux);

    // Caso o aluno esteja na Hash Table, retornamos-o. Caso contrário, retornamos NULL.
    return aluno_aux;
}

void destruir_hash(aluno_t ***hash_table, int tam_hash){
    // Declaração de variáveis auxiliares.
    aluno_t *anterior, *atual;

    // A cada iteração desalocamos a memória usada por uma posição (Linked List) da Hash Table.
    for(int i = 0; i < tam_hash; i++){
        atual = (*hash_table)[i];
        anterior = NULL;

        // Estrutura de repetição usada para percorrer toda a Linked List.
        while(atual != NULL){
            anterior = atual;
            atual = get_prox(atual);

            destruir_aluno(&anterior);
        }
    }

    /*
        Agora que já desalocamos a memória de todos os alunos, podemos
        desalocar a memória usada pela própria Hash Table.
    */
    free(*hash_table);
    *hash_table = NULL;
}