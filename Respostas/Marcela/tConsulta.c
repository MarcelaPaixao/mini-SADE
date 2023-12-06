#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tConsulta.h"

struct tConsulta {
    int diabetes, fumante, alergia, histCancer;
    char pele[2];
    tLesao **lesoes;
    int qtdLesoes;
    tPaciente *paciente;
    tMedico *medico;
    tReceita *receita;
    tEncaminhamento *encaminhamento;
    tBiopsia *biopsia;
    char data[11];

};

tConsulta *IniciaConsulta(tPaciente *paciente, tMedico *medico){
    tConsulta *consulta = malloc(sizeof(tConsulta));
    if(!consulta){
        exit(1);
    }
    printf("CPF DO PACIENTE: ---\n");
    printf("-NOME: %s\n", ObtemNomePaciente(paciente));
    printf("-DATA DE NASCIMENTO: %s\n", ObtemDataNascPaciente(paciente));
    printf("---\n");
    printf("DATA DA CONSULTA: ");
    scanf("%[^\n]%*c", consulta->data);
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", &consulta->diabetes);
    printf("FUMANTE: ");
    scanf("%d%*c", &consulta->fumante);
    printf("ALERGIA A MEDICAMENTO: ");
    scanf("%d%*c", &consulta->alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", &consulta->histCancer);
    printf("TIPO DE PELE: ");
    scanf("%[^\n]%*c", consulta->pele);
    consulta->lesoes = NULL;
    consulta->medico = medico;
    consulta->paciente = paciente;
    return consulta;
}

void FinalizaConsulta(tConsulta *consulta){
    if(!consulta) return; 
    for(int i=0; i < consulta->qtdLesoes; i++){
        DesalocaLesao(consulta->lesoes[i]);
    }
    //DesalocaBiopsia(consulta->biopsia);
    //DesalocaEncaminhamento(consulta->encaminhamento);
    //desalocaReceita(consulta->receita);
    free(consulta->lesoes);
    free(consulta);
}

void ImprimeMenuConsulta(tConsulta *consulta){
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR LESAO\n");
    printf("\t(2) GERAR RECEITA MEDICA\n");
    printf("\t(3) SOLICITACAO DE BIOPSIA\n");
    printf("\t(4) ENCAMINHAMENTO\n");
    printf("\t(5) ENCERRAR CONSULTA\n");
}

void ImprimeCabecalhoConsulta(){
    printf("#################### CONSULTA MEDICA #######################\n");
}

void CadastraLesao(tConsulta *consulta){
    (consulta->qtdLesoes)++;
    consulta->lesoes = realloc(consulta->lesoes, consulta->qtdLesoes * sizeof(tLesao *));
    consulta->lesoes[consulta->qtdLesoes - 1] = CriaLesao(consulta->qtdLesoes + 1);
    printf("LESAO REGISTRADA COM SUCESSO. ");
}

int VerificaSePrecisaCirurgia(tConsulta *consulta){
    for(int i=0; i < consulta->qtdLesoes; i++){
        if(ObtemEnviaCirugia(consulta->lesoes[i])){
            return i;
        }
    }
    return -1;
}

void SolicitaBiopsia(tConsulta *consulta, int idxLesao){
    tBiopsia *biopsia = CriaBiopsia(consulta->medico, consulta->paciente, consulta->data);
    AdicionaLesao(biopsia, consulta->lesoes[idxLesao]);
    printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. ");

}

void EncaminhaPaciente(tConsulta *consulta){
    tEncaminhamento *encam = CriaEncaminhamento(consulta->medico, consulta->paciente, consulta->data);
    printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. ");
}

void ImprimeReceita(tConsulta *consulta){
    /*RECEITA MEDICA:
TIPO DE USO: NOME DO MEDICAMENTO: TIPO DE MEDICAMENTO: QUANTIDADE: INSTRUCOES DE USO: */
    eTipoUso tipoUso;
    char medicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    char uso[7];
    int qtd;
    scanf("%[^\n]%*c", uso);
    scanf("%[^\n]%*c", medicamento);
    scanf("%[^\n]%*c", tipoMedicamento);
    scanf("%d", &qtd);
    scanf("%[^\n]%*c", instrucoes);

    if(strcmp(uso, 'ORAL') == 0){
        tipoUso = ORAL;
    }
    if(strcmp(uso, 'TOPICO') == 0){
        tipoUso = TOPICO;
    }

    tReceita *receita = criaReceita(ObtemNomePaciente(consulta->paciente), tipoUso, medicamento, tipoMedicamento, 
                                    instrucoes, qtd, ObtemNomeMedico(consulta->medico), ObtemCRMMedico(consulta->medico), consulta->data);
}