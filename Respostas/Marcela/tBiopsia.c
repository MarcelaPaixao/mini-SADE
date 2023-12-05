#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"
#include "tLesao.h"
#include "tPessoa.h"

struct tBiopsia {
    char nomePaciente[100];
    char nomeMedico[100];
    char cpfPaciente[15];
    char data[11];
    char CRMMedico[15];
    tLesao **lesoes;
    int qtdLesoes;

};

tBiopsia *CriaBiopsia(tMedico *medico, tPaciente *paciente, char *data){
    tBiopsia *biopsia = malloc(sizeof(tBiopsia));
    if(!biopsia){
        exit(1);
    }
    strcpy(biopsia->nomePaciente, ObtemNomePaciente(paciente));
    strcpy(biopsia->cpfPaciente, ObtemCPFPaciente(paciente));
    strcpy(biopsia->nomeMedico, ObtemNomeMedico(medico));
    strcpy(biopsia->CRMMedico, ObtemCRMMedico(medico));
    strcpy(biopsia->data, data);
    biopsia->qtdLesoes = 0;
    biopsia->lesoes = NULL;
    return biopsia;
}

void AdicionaLesao(tBiopsia *biopsia){
    (biopsia->qtdLesoes)++;
    biopsia->lesoes = realloc(biopsia->lesoes, biopsia->qtdLesoes * sizeof(tLesao *));
    biopsia->lesoes[biopsia->qtdLesoes - 1] = CriaLesao(biopsia->qtdLesoes + 1);
}

void LiberaBiopsia(tBiopsia *biopsia){
    if(!biopsia) return;
    if(biopsia->lesoes){
        for(int i=0; i < biopsia->qtdLesoes; i++){
            DesalocaLesao(biopsia->lesoes[i]);
        }
        free(biopsia->lesoes);
    }
    free(biopsia);
}

void ImprimeNaTelaBiopsia(tBiopsia *biopsia){
    int precisaCirurgia=0;
    for(int i=0; i < biopsia->qtdLesoes; i++){
        if(ObtemEnviaCirugia(biopsia->lesoes[i])){
            precisaCirurgia = 1;
            break;
        }
    }
    if(precisaCirurgia){
        printf("PACIENTE: %s\n", biopsia->nomePaciente);
        printf("CPF: %s\n\n", biopsia->cpfPaciente);
        printf("CPF: %s\n\n", biopsia->cpfPaciente);
        printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    
        for(int i=0; i < biopsia->qtdLesoes; i++){
            if(ObtemEnviaCirugia(biopsia->lesoes[i])){
                ImprimeLesaoTela(biopsia->lesoes[i]);
            }
        }
        printf("%s ", biopsia->nomeMedico);
        printf("(%s)\n", biopsia->CRMMedico);
        printf("%s\n", biopsia->data);
    }
}

void ImprimeEmBinarioBiopsia(tBiopsia *biopsia);

void ImprimeEmArquivoBiopsia(tBiopsia *biopsia, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/biopsia.txt", path);
    FILE *arq = fopen(diretorio, "a");
    int precisaCirurgia=0;
    for(int i=0; i < biopsia->qtdLesoes; i++){
        if(ObtemEnviaCirugia(biopsia->lesoes[i])){
            precisaCirurgia = 1;
            break;
        }
    }
    if(precisaCirurgia){
        fprintf(arq,"PACIENTE: %s\n", biopsia->nomePaciente);
        fprintf(arq, "CPF: %s\n\n", biopsia->cpfPaciente);
        fprintf(arq, "CPF: %s\n\n", biopsia->cpfPaciente);
        fprintf(arq, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    
        for(int i=0; i < biopsia->qtdLesoes; i++){
            if(ObtemEnviaCirugia(biopsia->lesoes[i])){
                ImprimeLesaoArquivo(biopsia->lesoes[i], arq);
            }
        }
        fprintf(arq,"%s ", biopsia->nomeMedico);
        fprintf(arq,"(%s)\n", biopsia->CRMMedico);
        fprintf(arq,"%s\n", biopsia->data);
    }
    fclose(arq);
}