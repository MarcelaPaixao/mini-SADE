#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tReceita.h"

#define MAX_TAM_NOME_MEDICAMENTO 50
#define MAX_TAM_TIPO_MEDICAMENTO 50
#define MAX_TAM_INSTRUCOES 300
#define NOME_ARQUIVO_RECEITA "receita.txt"

typedef enum
{
    ORAL,
    TOPICO
} eTipoUso;

struct tReceita {
    char *nomePaciente;
    eTipoUso tipoUso;
    char nomeMedicamento[50];
    char tipoMedicamento[50];
    char instrucoes[300];
    int qtd;
    char *nomeMedico;
    char *CRM;
    char *data;
};

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 *
 */
tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
                      char *tipoMedicamento, char *instrucoes, int qntd,
                      char *nomeMedico, char *CRM, char *dataStr){
    tReceita *receita = malloc(sizeof(tReceita));
    if(receita == NULL){
        printf("Falha na alocacao de memoria para a receita!\n");
        exit(1);
    }

    receita->nomePaciente = malloc(strlen((nomePaciente)+1) * sizeof(char));
    receita->nomeMedico = malloc(strlen((nomeMedico)+1) * sizeof(char));
    receita->CRM = malloc(strlen((CRM)+1) * sizeof(char));
    receita->dataStr = malloc(strlen((dataStr)+1) * sizeof(char));
    
    strcpy(receita->nomePaciente, nomePaciente);
    strcpy(receita->nomeMedico, nomeMedico);
    strcpy(receita->CRM, CRM);
    strcpy(receita->data, dataStr);
    strcpy(receita->nomeMedicamento, nomeMedicamento);
    strcpy(receita->tipoMedicamento, tipoMedicamento);
    strcpy(receita->instrucoes, instrucoes);
    receita->tipoUso = tipoUso;
    receita->qtd = qntd;

    return receita;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaReceita(void *dado){
    if(dado != NULL){
        tReceita *r = dado;
        free(r->nomePaciente);
        free(r->nomeMedico);
        free(r->CRM);
        free(r->data);
        free(r);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaReceita(void *dado){
    tReceita *receita = dado;
    printf("RECEITUARIO\n");
    printf("NOME: %s\n", receita->nomePaciente);
    if(receita->tipoUso == ORAL) printf("\n\nUSO ORAL\n\n");
    else if(receita->tipoUso == TOPICO) printf("\n\nUSO TOPICO\n\n");
    printf("%s\n", receita->nomeMedicamento);
    printf("%d %s\n\n", receita->qtd, receita->tipoMedicamento);
    printf("%s\n\n", receita->instrucoes);
    printf("%s (%s)\n", receita->nomeMedico, receita->CRM);
    printf("%s\n", receita->data);
}


/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoReceita(void *dado, char *path);
