#include "ordenacao.h"

/*
    Função auxiliar à 'void torneioGeralSort' que retorna o número de folhas que nossa arvore terá, ou seja,
    retorna, segundo as especificações do trabalho, "a primeira potência de 2 maior ou igual ao número de
    elementos do vetor a se ordenar"
*/
int contar_folhas(int qntd_alunos){
    // Inicializando a variavel a ser retornada com a primeira potencia de 2 (2^0 = 1)
    int potencia = 1;

    // Loop que será realizado enquanto a variavel a ser retornada for estritamente menor que o numero de alunos
    while(qntd_alunos > potencia){
        // Caso o valor ainda não seja o procurado, verificaremos para a proxima potencia de 2
        potencia *= 2;
    }

    return potencia;
}

/*
    Função auxiliar à 'void torneioGeralSort' que retorna qual dos alunos passados como parâmetro deverá ser
    escolhido como o pai dos 2. Legenda:
        0: deveremos escolher o aluno à esquerda (a1) como pai
        1: deveremos escolher o aluno à direita (a2) como pai    
*/
int compara(aluno_t *a1, aluno_t *a2, int qntd_provas){
    /*
        Condicionais para evitar Segmentation Fault ao tentar acessar memória de um ponteiro NULO. Caso ambos sejam
        nulos, o da direita será escolhido arbitrariamente, ou seja, NULO será o pai, já nos casos onde apenas um é
        NULO, o aluno não NULO será o pai. No caso em que nenhum dos dois é nulo, essas condicionais serão puladas
        e o resto da função será utilizada
    */
    if(a1 == NULL){
        return 1;
    }else if(a2 == NULL){
        return 0;
    }

    float media1 = get_media(a1);
    float media2 = get_media(a2);

    // Caso as médias sejam diferentes, será escolhido o aluno com a maior delas
    if(media1 > media2){
        return 0;
    }else if(media1 < media2){
        return 1;
    }

    int *notas1 = get_notas(a1);
    int *notas2 = get_notas(a2);

    // Caso as médias sejam iguais, será escolhido o alunos que primeiro tirou uma nota maior que o outro
    for(int i = 0; i < qntd_provas; i++){
        if(notas1[i] > notas2[i]){
            return 0;
        }else if(notas1[i] < notas2[i]){
            return 1;
        }
    }

    // Caso as notas dos 2 alunos sejam completamente iguais, escolhemos arbitrariamente um deles
    return 0; 
}

// Função auxiliar à 'void torneioGeralSort' que inicializa todas as posições da árvore, desde as folhas até a raiz
void inicializar_arvore(aluno_t **arvore, aluno_t **vetor, int qntd_folhas, int qntd_alunos, int qntd_provas){
    int i, j;

    // Loop que copia nas folhas da árvore as structs do vetor que foi pedido para ser ordenado
    for(i = qntd_folhas, j = 0; j < qntd_alunos; i++, j++){
        arvore[i] = vetor[j];
    }
    // Caso haja mais folhas do que posiçoes no vetor, inicializamos as folhas restantes como NULL
    for(; i < (2 * qntd_folhas); i++){
        arvore[i] = NULL;
    }

    // Loop que completa a árvore até a raiz
    for(int i = qntd_folhas - 1; i > 0; i--){
        if(compara(arvore[2 * i], arvore[(2 * i) + 1], qntd_provas) == 0){
            arvore[i] = arvore[2 * i];
        }else{
            arvore[i] = arvore[(2 * i) + 1];
        }
    }
}

/*
    Função auxiliar à 'void torneioGeralSort' que, recebendo 2 alunos (a1 e a2), armazena no criterio de desempate do
    melhor deles o critério utilizado para compará-los
*/
void desempatar(aluno_t *a1, aluno_t *a2, int qntd_provas){
    float media1 = get_media(a1);
    float media2 = get_media(a2);

    // Caso tenham diferentes médias, o aluno de maior média terá como criterio de desempate a média (criterio == 0)
    if(media1 > media2){
        set_criterio(a1, 0);
        return;
    }else if(media1 < media2){
        set_criterio(a2, 0);
        return;
    }

    int *notas1 = get_notas(a1);
    int *notas2 = get_notas(a2);

    /*
        Caso as médias sejam iguais, aquele aluno que primeiro tirou uma nota maior em relação ao outro terá como
        critério de desempate a prova (i + 1). O '+ 1' usado é apenas um fator de correção para facilitar a impressão,
        já que não existe prova 0
    */
    for(int i = 0; i < qntd_provas; i++){
        if(notas1[i] > notas2[i]){
            set_criterio(a1, i + 1);
            return;
        }else if(notas1[i] < notas2[i]){
            set_criterio(a2, i + 1);
            return;;
        }
    }
}

// Função auxiliar à 'void torneioGeralSort' que procura um aluno, troca-o por NULL e retorna a posição dele na arvore
int busca_profundidade(aluno_t **arvore, aluno_t *aluno_procurado, int posicao_atual, int tam_arvore, int qntd_provas){
    // Condição de parada
    if(posicao_atual >= tam_arvore) return -1;

    // Condição para verificar se alguma das folhas é o aluno procurado
    if(posicao_atual >= (tam_arvore/2) && arvore[posicao_atual] == aluno_procurado){
        arvore[posicao_atual] = NULL;
        return posicao_atual;
    }

    // Passo recursivo
    if(compara(arvore[2 * posicao_atual], arvore[(2 * posicao_atual) + 1], qntd_provas) == 0){
        busca_profundidade(arvore, aluno_procurado, 2 * posicao_atual, tam_arvore, qntd_provas);
    }else{
        busca_profundidade(arvore, aluno_procurado, (2 * posicao_atual) + 1, tam_arvore, qntd_provas);
    }
}

/*
    Função auxiliar à 'void torneioGeralSort' que refaz o torneio apenas para aqueles ramos da árvore que são
    ligados à folha atualizada (trocada por NULL)
*/
void atualizar_arvore(aluno_t **arvore, int pos_atualizada, int qntd_provas){
    // Condição de parada
    if(pos_atualizada <= 1) return;

    // Calculando a posição do pai do registro atualizado
    int pos_pai = pos_atualizada/2;

    // Estruturas condicionais para escolher o novo pai
    if(compara(arvore[2 * pos_pai], arvore[(2 * pos_pai) + 1], qntd_provas) == 0){
        arvore[pos_pai] = arvore[2 * pos_pai];
    }else{
        arvore[pos_pai] = arvore[(2 * pos_pai) + 1];
    }

    // Passo recursivo
    atualizar_arvore(arvore, pos_atualizada/2, qntd_provas);
}

// Função auxiliar à 'void torneioGeralSort' que troca as informações de 2 alunos (a1 e a2)
void swap(aluno_t **a1, aluno_t **a2){
    aluno_t *aux = *a1;
    *a1 = *a2;
    *a2 = aux;
}

void torneioGeralSort(aluno_t **vetor, int qntd_alunos, int qntd_provas){
    assert(vetor != NULL);

    // Variável que armazena a quantidade de folhas que teremos em nossa arvore
    int qntd_folhas = contar_folhas(qntd_alunos);

    /*
        Conforme especificado no trabalho, nossa árvore terá 2k posições, sendo k o número de folhas. Logo fazemos a 
        alocação que 2k espaços para a árvore
    */
    aluno_t **arvore = (aluno_t **) malloc((2 * qntd_folhas) * sizeof(aluno_t *));

    inicializar_arvore(arvore, vetor, qntd_folhas, qntd_alunos, qntd_provas);

    // Inicializando variaveis que auxiliarão no próximo passo da ordenação
    int k = qntd_alunos;
    int j = 0;

    // Loop que garante que a cada iteração o melhor aluno do subvetor atual está na primeira posiçao dele
    while(k){
        // Colocamos o melhor aluno encontrado na posição que ele estará após o fim da ordenação
        swap(&vetor[j], &arvore[1]);

        // Preenchemos o critério de desempate desse aluno
        if(k < qntd_alunos) desempatar(vetor[j - 1], vetor[j], qntd_provas);

        // Procuramos, na arvore, o melhor aluno encontrado e então trocamos ele por NULL        
        int pos_maior = busca_profundidade(arvore, vetor[j], 1, 2 * qntd_folhas, qntd_provas);

        // Atualizando os ramos com conexão à folha trocada por NULL
        atualizar_arvore(arvore, pos_maior, qntd_provas);

        k--;
        j++;
    }

    // Desalocando a memória da árvore
    free(arvore);
}