#include "tBiopsia.h"

struct tBiopsia {
    char nomePaciente[100];
    char nomeMedico[100];
    char cpfPaciente[15];
    char data[11];
    char CRMMedico[15];
    int qtdLesoes;
    tLesao **lesoes;
};

/**
 * Função que cria um ponteiro para biópsia de acordo com as informações passadas como parâmetro.
 */
tBiopsia *CriaBiopsia(char *nomeMed, char *CRM, char *nomePac, char *cpfPac, char *data){
    tBiopsia *biopsia = malloc(sizeof(tBiopsia));
    if(!biopsia){
        exit(1);
    }
    strcpy(biopsia->nomeMedico, nomeMed);
    strcpy(biopsia->CRMMedico, CRM);
    strcpy(biopsia->nomePaciente, nomePac);
    strcpy(biopsia->cpfPaciente, cpfPac);
    strcpy(biopsia->data, data);
    biopsia->qtdLesoes = 0;
    biopsia->lesoes = NULL;
    return biopsia;
}

/**
 * Função que acrescenta uma lesão, passada como parâmetro, à biopsia tembém passada como parâmetro.
 */
void AdicionaLesao(tBiopsia *biopsia, tLesao *lesao){
    (biopsia->qtdLesoes)++;
    biopsia->lesoes = realloc(biopsia->lesoes, biopsia->qtdLesoes * sizeof(tLesao *));
    biopsia->lesoes[biopsia->qtdLesoes - 1] = lesao;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma biópsia) e o desaloca da memória.
 */
void DesalocaBiopsia(void *dado){
    tBiopsia *biopsia = (tBiopsia*) dado;
    if(!biopsia) return;
    if(biopsia->lesoes) free(biopsia->lesoes);
    free(biopsia);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma biópsia) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void ImprimeNaTelaBiopsia(void *dado){
    tBiopsia *biopsia = (tBiopsia*) dado;
    printf("PACIENTE: %s\n", biopsia->nomePaciente);
    printf("CPF: %s\n\n", biopsia->cpfPaciente);
    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    
    for(int i=0; i < biopsia->qtdLesoes; i++){
        ImprimeLesaoTela(biopsia->lesoes[i]);
    }
    
    printf("%s ", biopsia->nomeMedico);
    printf("(%s)\n", biopsia->CRMMedico);
    printf("%s\n", biopsia->data);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma biópsia) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 */
void ImprimeEmArquivoBiopsia(void *dado, char *path){
    tBiopsia *biopsia = (tBiopsia*) dado;
    char diretorio[1000];
    sprintf(diretorio, "%s/biopsia.txt", path);
    FILE *arq = fopen(diretorio, "a");

    fprintf(arq,"PACIENTE: %s\n", biopsia->nomePaciente);
    fprintf(arq, "CPF: %s\n\n", biopsia->cpfPaciente);
    fprintf(arq, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    
    for(int i=0; i < biopsia->qtdLesoes; i++){
        ImprimeLesaoArquivo(biopsia->lesoes[i], arq);
    }
    
    fprintf(arq,"%s ", biopsia->nomeMedico);
    fprintf(arq,"(%s)\n", biopsia->CRMMedico);
    fprintf(arq,"%s\n", biopsia->data);
    
    fclose(arq);
}
