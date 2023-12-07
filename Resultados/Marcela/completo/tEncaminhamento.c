#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEncaminhamento.h"

struct tEncaminhamento {
    char nomePaciente[100];
    char nomeMedico[100];
    char cpfPaciente[15];
    char data[11];
    char CRMMedico[15];
    char especialidade[50];
    char motivo[300];
};

tEncaminhamento *CriaEncaminhamento(tPaciente *paciente, tMedico *medico, char *data){
    tEncaminhamento *enc = malloc(sizeof(tEncaminhamento));
    if(enc == NULL){
        exit(1);
    }
    strcpy(enc->nomePaciente, ObtemNomePaciente(paciente));
    strcpy(enc->cpfPaciente, ObtemCPFPaciente(paciente));
    strcpy(enc->nomeMedico, ObtemNomeMedico(medico));
    strcpy(enc->CRMMedico, ObtemCRMMedico(medico));
    strcpy(enc->data, data);
    printf("ENCAMINHAMENTO:\n");
    printf("ESPECIALIDADE ENCAMINHADA: ");
    scanf("%[^\n]%*c", enc->especialidade);
    printf("MOTIVO: ");
    scanf("%[^\n]%*c", enc->motivo);
    return enc;
}

void ImprimeNaTelaEncam(tEncaminhamento *enc){
    printf("PACIENTE: %s\n", enc->nomePaciente);
    printf("CPF: %s\n\n", enc->cpfPaciente);
    printf("ESPECIALIDADE ENCAMINHADA: %s", enc->especialidade);
    printf("MOTIVO: %s\n\n", enc->motivo);
    printf("%s ", enc->nomeMedico);
    printf("(%s)\n", enc->CRMMedico);
    printf("%s\n", enc->data);
}

void ImprimeEmArquivoEncam(tEncaminhamento *enc, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/encaminhamento.txt", path);
    FILE *arq = fopen(diretorio, "a");
    
    fprintf(arq, "PACIENTE: %s\n", enc->nomePaciente);
    fprintf(arq, "CPF: %s\n\n", enc->cpfPaciente);
    fprintf(arq, "ESPECIALIDADE ENCAMINHADA: %s", enc->especialidade);
    fprintf(arq, "MOTIVO: %s\n\n", enc->motivo);
    fprintf(arq, "%s ", enc->nomeMedico);
    fprintf(arq, "(%s)\n", enc->CRMMedico);
    fprintf(arq, "%s\n", enc->data);
    fclose(arq);
}

void DesalocaEncaminhamento(tEncaminhamento *enc){
    if(!enc) return;
    free(enc);
}

