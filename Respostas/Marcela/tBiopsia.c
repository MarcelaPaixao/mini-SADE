#include "tBiopsia.h"

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
    if(medico == NULL){
        biopsia->nomeMedico[0] = '\0';
        biopsia->CRMMedico[0] = '\0';
    }
    else {
        strcpy(biopsia->nomeMedico, ObtemNomeMedico(medico));
        strcpy(biopsia->CRMMedico, ObtemCRMMedico(medico));
    }
    strcpy(biopsia->nomePaciente, ObtemNomePaciente(paciente));
    strcpy(biopsia->cpfPaciente, ObtemCPFPaciente(paciente));
    
    strcpy(biopsia->data, data);
    biopsia->qtdLesoes = 0;
    biopsia->lesoes = NULL;
    return biopsia;
}

void AdicionaLesao(tBiopsia *biopsia, tLesao *lesao){
    (biopsia->qtdLesoes)++;
    biopsia->lesoes = realloc(biopsia->lesoes, biopsia->qtdLesoes * sizeof(tLesao *));
    biopsia->lesoes[biopsia->qtdLesoes - 1] = lesao;
}

void DesalocaBiopsia(void *dado){
    tBiopsia *biopsia = (tBiopsia*) dado;
    if(!biopsia) return;
    if(biopsia->lesoes){
        free(biopsia->lesoes);
    }
    free(biopsia);
}

void ImprimeNaTelaBiopsia(void *dado){
    tBiopsia *biopsia = (tBiopsia*) dado;
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

void ImprimeEmArquivoBiopsia(void *dado, char *path){
    tBiopsia *biopsia = (tBiopsia*) dado;
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
