#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// O número máximo de caracteres, contando o '/0', que o nome de um aluno pode ter
#define TAM_STRING 20

typedef struct aluno_ aluno_t;

// Reserva memória para 1 struct aluno_t, que armazena as informações de apenas 1 aluno
aluno_t *criar_aluno();

// Armazena o nome 'char *nome' como nome do aluno 'aluno_t *aluno'
void set_nome(aluno_t *aluno, char *nome);

// Armazena o vetor 'int *notas' como as notas do aluno 'aluno_t *aluno'
void set_notas(aluno_t *aluno, int *notas);

// Armazena o número 'float media' como a media das notas do aluno 'aluno_t *aluno'
void set_media(aluno_t *aluno, float media);

// Armazena o número 'int criterio' como o criterio de desempate de 'aluno_t *aluno'
void set_criterio(aluno_t *aluno, int criterio);

// Retorna uma string com o nome de 'aluno_t *aluno'
char *get_nome(aluno_t *aluno);

// Retorna um vetor de inteiros contendo todas as notas de 'aluno_t *aluno'
int *get_notas(aluno_t *aluno);

// Retorna um float com a media das notas de 'aluno_t *aluno'
float get_media(aluno_t *aluno);

// Retorna um inteiro com o criterio de desempate de 'aluno_t *aluno'
int get_criterio(aluno_t *aluno);

// Desaloca a memória reservada para 'aluno_t *aluno'
void apagar_aluno(aluno_t **aluno);

// Função que percorre todo o vetor de alunos em busca da maior média a fim de retorná-la
float get_maior_media(aluno_t **vetor_alunos, int qntd_alunos);