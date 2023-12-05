#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tReceita.h"

#define NOME_ARQUIVO_RECEITA "receita.txt"


struct tReceita {
    char nomePaciente[100];
    eTipoUso tipoUso;
    char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    int qtd;
    char nomeMedico[100];
    char CRM[12];
    char data[11];
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
    if(!dado) return;
    tReceita *r = dado;
    free(r);
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
void imprimeEmArquivoReceita(void *dado, char *path){
    tReceita *receita = dado;
    char diretorio[1000];
    snprintf(diretorio, sizeof(diretorio), "%s/receita.txt", path);
    FILE *arq = fopen(diretorio, "a");
    
    if (arq == NULL) {
        printf("Falha ao abrir o arquivo para escrita!\n");
        exit(1);
    }

    fprintf(arq, "RECEITUARIO\n");
    fprintf(arq, "NOME: %s\n", receita->nomePaciente);
    if(receita->tipoUso == ORAL) fprintf(arq, "\n\nUSO ORAL\n\n");
    else if(receita->tipoUso == TOPICO) fprintf(arq, "\n\nUSO TOPICO\n\n");
    fprintf(arq, "%s\n", receita->nomeMedicamento);
    fprintf(arq, "%d %s\n\n", receita->qtd, receita->tipoMedicamento);
    fprintf(arq, "%s\n\n", receita->instrucoes);
    fprintf(arq, "%s (%s)\n", receita->nomeMedico, receita->CRM);
    fprintf(arq, "%s\n", receita->data);

    fclose(arq);
}
