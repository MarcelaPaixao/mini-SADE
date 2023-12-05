#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEncaminhamento.h"
#include "tAgente.h"

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
    printf("ESPECIALIDADE ENCAMINHADA: ");
    scanf("%[^\n]%*c", enc->especialidade);
    printf("MOTIVO: ");
    scanf("%[^\n]%*c", enc->motivo);

    return enc;
}

void ImprimeNaTelaEncam(tEncaminhamento *enc){
    printf("ESPECIALIDADE ENCAMINHADA: ");
    /*ESPECIALIDADE ENCAMINHADA: MOTIVO: 
ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR*/
}

void ImprimeEmArquivoEncam(tEncaminhamento *enc){

}

void DesalocaEncaminhamento(tEncaminhamento *enc){
    if(!enc) return;
    free(enc);
}

