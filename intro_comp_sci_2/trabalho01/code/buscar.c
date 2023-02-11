#include "buscar.h"

int busca_binaria(double **matriz, int inicio, int fim, double chave, int selecionada){
    int centro = (inicio + fim) / 2;

    if(matriz[centro][selecionada] == chave)
        return centro;
    if(inicio > fim)
        return -1;
    if(chave > matriz[centro][selecionada])
        return busca_binaria(matriz, centro + 1, fim, chave, selecionada);

    return busca_binaria(matriz, inicio, centro - 1, chave, selecionada);
}

void busca(double **matriz, int qntd_vinhos, int qntd_caract, int selecionada, double chave){
    int index_achado, total_vinhos = 0;
    index_achado = busca_binaria(matriz, 0, qntd_vinhos - 1, chave, selecionada);

    if(index_achado == -1){
        printf("Nenhum vinho encontrado\n");
    }else{
        total_vinhos++;

        int index_saver = index_achado; // Variável usada para armazenar o valor de index_achado, para que possamos ver tanto à esquerda quanto à direita de index_achado ao contar os vinhos
        int index_aux = index_achado - 1; // Variável usada para percorrer a matriz ordenada para selecionar o vinho que possui o menor Id dentre os que têm determinada caracteristica

        // Loop para contar quantos vinhos possuem tal caracteristica e que, na matriz, estão à esquerda do vinho encontrado. Além disso, ele escolhe o com menor Id 
        while(index_achado > 0 && matriz[index_aux][selecionada] == matriz[index_saver][selecionada]){
            total_vinhos++;

            index_achado = index_aux;

            index_aux--;
        }

        index_aux = index_saver + 1;

        // Loop para contar quantos vinhos possuem tal caracteristica e que, na matriz, estão à direita do vinho encontrado
        while(index_aux <= (qntd_vinhos - 1) && matriz[index_aux][selecionada] == matriz[index_saver][selecionada]){
            total_vinhos++;

            index_aux++;
        }
    
        // Imprimindo os resultados encontrados
        printf("ID: %.0lf, Citric Acid: %.5lf, Residual Sugar %.5lf, Density %.5lf, pH %.5lf, Alcohol %.5lf\n", matriz[index_achado][0], matriz[index_achado][1], matriz[index_achado][2], 
        matriz[index_achado][3], matriz[index_achado][4], matriz[index_achado][5]);

        printf("Total de vinhos encontrados: %d\n", total_vinhos);
    }
}