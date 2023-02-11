#include "entrada_saida.h"

void ler_alunos(aluno_t **hash_table, int n_alunos, int tam_hash){
    // Declaração de variáveis auxiliares.
    char string_aux[TAM_STRING];
    unsigned int senha_hashificada;
    float notas[N_NOTAS];
    aluno_t *aluno;

    // Estrutura de repetição que a cada iteração lerá as informações de 1 aluno.
    for(int i = 0; i < n_alunos; i++){
        // Alocação de memória para esse aluno.
        aluno = criar_aluno();

        // Leitura das informações desse aluno.
        scanf(" %s", string_aux);
        set_nusp(aluno, string_aux);

        scanf(" %s", string_aux);
        senha_hashificada = hash(string_aux);
        set_senha(aluno, senha_hashificada);

        for(int j = 0; j < N_NOTAS; j++){
            scanf(" %f", &notas[j]);
        }
        set_notas(aluno, notas);

        // Tentando fazer a inserção desse aluno na Hash Table.
        bool result = inserir_hash(hash_table, aluno, tam_hash);

        if(result == true){ // Caso o aluno ainda não existia e inserimos ele na Hash Table:
            // Imprimimos uma mensagem de confirmação.
            printf("Cadastro efetuado com sucesso\n");
        }else{ // Caso o aluno já exista na Hash Table:
            // Imprimimos uma mensagem de erro.
            printf("NUSP ja cadastrado\n");

            // Desalocamos memória do aluno duplicado.
            free(aluno);
        }
    }
}

void fazer_login(aluno_t **hash_table, int n_logins, int tam_hash){
    // Declaração de variáveis auxiliares.
    char string_aux[TAM_STRING];
    aluno_t *aluno;

    // Estrutura de repetição que a cada iteração tentará fazer o login de 1 aluno.
    for(int i = 0; i < n_logins; i++){
        // Lendo qual aluno deveremos tentar fazer o login.
        scanf(" %s", string_aux);

        // Vendo se o aluno existe ou não na Hash Table.
        aluno = buscar_hash(hash_table, string_aux, tam_hash);

        if(aluno == NULL){ // Caso ele não exista:
            // Imprimimos uma mensagem de erro.
            printf("NUSP invalido\n");

            // Lendo mais uma vez para retirar a senha escrita para essa tentativa de login.
            scanf(" %s", string_aux);
        }else{  // Caso exista:
            // Lemos qual a senha passada para a tentativa de login.
            scanf(" %s", string_aux);

            if(hash(string_aux) != get_senha(aluno)){ // Caso a senha passada NÃO seja igual à armazenada na Hash Table:
                // Imprimimos uma mensagem de erro.
                printf("Senha incorreta para o NUSP digitado\n");
            }else{ // Caso a senha passada seja igual à armazenada na Hash Table:
                // Pegamos o vetor com as notas do aluno.
                float *notas = get_notas(aluno);

                // Imprimimos seus valores.
                printf("Notas: P1=%.1lf, P2=%.1lf, T1=%.1lf, T2=%.1lf\n", notas[0], notas[1], notas[2], notas[3]);
            }
        }
    }
}