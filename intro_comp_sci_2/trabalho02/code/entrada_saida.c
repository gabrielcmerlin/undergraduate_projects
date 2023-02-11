#include "entrada_saida.h"
#include "aluno.h"

aluno_t **ler_vetor_alunos(int qntd_alunos, int qntd_provas){
    // Alocando memória para o vetor de structs que será retornado
    aluno_t **vetor_alunos = (aluno_t **) malloc(qntd_alunos * sizeof(aluno_t *));

    // String auxiliar para ajudar na leitura do nomo dos alunos
    char nome[TAM_STRING];
    // Inteiro auxilair usado para armazenar a soma de todas as notas do aluno atual (usado para calcula a média)
    int soma_notas = 0;

    // Loop para garantir que todos os alunos terão suas informações lidas
    for(int i = 0; i < qntd_alunos; i++){
        scanf(" %s", nome);

        // Alocando memória para o vetor que conterá todas as notas do atual aluno
        int *notas = (int *) malloc(qntd_provas * sizeof(int));
        // Loop que lê a nota das provas, armazena no vetor alocado à cima e atualiza a soma das notas das provas
        for(int j = 0; j < qntd_provas; j++){
            scanf(" %d", &notas[j]);
            soma_notas += notas[j];
        }

        // Alocando memória para o aluno atual e inicializando os campos de sua struct
        aluno_t *aluno = criar_aluno();
        set_nome(aluno, nome);
        set_notas(aluno, notas);
        set_media(aluno, (soma_notas / (1.0 * qntd_provas)));
        set_criterio(aluno, -1);

        // Armazenando a aluno atual o vetor de structs alocado no inínio da função
        vetor_alunos[i] = aluno;

        // Reinicialização da variável auxliar pra não comprometar o calculo da media do proximo aluno
        soma_notas = 0;
    }

    return vetor_alunos;
}

// Função auxiliar à 'void apagar_vetor_alunos' que serve para desalocar o vetor de notas
void apagar_notas(int **notas){
    free(*notas);
    *notas = NULL;
}

void apagar_vetor_alunos(aluno_t **vetor_alunos, int qntd_alunos){
    // Declaração de variáveis auxiliares
    int *notas = NULL;
    aluno_t *aluno = NULL;

    // Loop para percorrer todo o vetor de alunos
    for(int i = 0; i < qntd_alunos; i++){
        // Pegando o vetor de notas do aluno atual e desalocando-o
        notas = get_notas(vetor_alunos[i]);
        apagar_notas(&notas);

        // Pegando a struct do aluno atual e desalocando-a
        aluno = vetor_alunos[i];
        apagar_aluno(&aluno);
    }

    // Desalocando a memória do vetor de structs
    free(vetor_alunos);
}

// Função auxiliar à 'void imprimir_saida' que faz um tipo de impressão para cada tipo de critério de desempate
void imprimir_desempate(aluno_t *aluno){
    int criterio = get_criterio(aluno);

    if(criterio == 0) printf(" - media");
    else if(criterio != -1) printf(" - desempate: nota %d", criterio);

    printf("\n");
}

void imprimir_saida(aluno_t **vetor_alunos, int qntd_alunos, int qntd_provas){
    printf("Maior media: %.3f\n", get_maior_media(vetor_alunos, qntd_alunos));

    // Loop para percorrer todo o vetor de alunos
    for(int i = 0; i < qntd_alunos; i++){
        printf("%d. %s", i + 1, get_nome(vetor_alunos[i]));

        // Imprimindo a característica de desempate
        imprimir_desempate(vetor_alunos[i]);
    }
}