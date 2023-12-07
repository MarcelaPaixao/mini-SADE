#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tConsulta.h"

struct tConsulta {
    int diabetes, fumante, alergia, histCancer;
    int qtdLesoes, qtdReceitas, qtdEncam;
    char pele[2];
    tLesao **lesoes;
    tPaciente *paciente;
    tMedico *medico;
    tReceita **receita;
    tEncaminhamento **encaminhamento;
    tBiopsia *biopsia;
    char data[11];

};

tConsulta *IniciaConsulta(tPaciente *paciente, tMedico *medico){
    tConsulta *consulta = malloc(sizeof(tConsulta));
    if(!consulta){
        exit(1);
    }
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: ---\n");
    printf("-NOME: %s\n", ObtemNomePaciente(paciente));
    printf("-DATA DE NASCIMENTO: %d/%d/%d\n", ObtemDiaNascPaciente(paciente), ObtemMesNascPaciente(paciente), ObtemAnoNascPaciente(paciente));
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
    printf("############################################################\n");
    
    consulta->lesoes = NULL;
    consulta->medico = medico;
    consulta->paciente = paciente;
    consulta->receita = NULL;
    consulta->encaminhamento = NULL;
    consulta->biopsia = NULL;
    consulta->qtdEncam = 0;
    consulta->qtdReceitas = 0;

    return consulta;
}

void FinalizaConsulta(tConsulta *consulta){
    if(!consulta) return; 
    for(int i=0; i < consulta->qtdLesoes; i++){
        DesalocaLesao(consulta->lesoes[i]);
    }
    free(consulta->lesoes);
    free(consulta);
    //lembrar de desalocar o resto das coisas depois
}



void ImprimeMenuConsulta(tConsulta *consulta){
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR LESAO\n");
    printf("\t(2) GERAR RECEITA MEDICA\n");
    printf("\t(3) SOLICITACAO DE BIOPSIA\n");
    printf("\t(4) ENCAMINHAMENTO\n");
    printf("\t(5) ENCERRAR CONSULTA\n");
    printf("############################################################\n");
}

void ImprimeCabecalhoConsulta(){
    printf("#################### CONSULTA MEDICA #######################\n");
}

void CadastraLesao(tConsulta *consulta){
    printf("#################### CONSULTA MEDICA #######################\n");
    (consulta->qtdLesoes)++;
    consulta->lesoes = realloc(consulta->lesoes, consulta->qtdLesoes * sizeof(tLesao *));
    consulta->lesoes[consulta->qtdLesoes - 1] = CriaLesao(consulta->qtdLesoes + 1);
    printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    char c;
    scanf("%c%*c", &c); //talvez rtirar isso daqui e colocar na main pra padronizar
}

int VerificaSePrecisaCirurgia(tConsulta *consulta){
    for(int i=0; i < consulta->qtdLesoes; i++){
        if(ObtemEnviaCirugia(consulta->lesoes[i])){
            return 1;
        }
    }
    return 0;
}

void SolicitaBiopsia(tConsulta *consulta){
    printf("#################### CONSULTA MEDICA #######################\n");
    if(!VerificaSePrecisaCirurgia(consulta)){
        printf("NAO E POSSIVEL SOLICITAR BIOPSIA SEM LESAO CIRURGICA. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");
    }
    else{
        consulta->biopsia = CriaBiopsia(consulta->medico, consulta->paciente, consulta->data);
        for(int i=0; i < consulta->qtdLesoes; i++){
            if(ObtemEnviaCirugia(consulta->lesoes[i])){
                AdicionaLesao(consulta->biopsia, consulta->lesoes[i]);
            }
        }
        printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");
    }
    char c;
    scanf("%c%*c", &c); //talvez rtirar isso daqui e colocar na main pra padronizar
}

void EncaminhaPaciente(tConsulta *consulta){
    printf("#################### CONSULTA MEDICA #######################\n");
    (consulta->qtdEncam)++;
    consulta->encaminhamento = realloc(consulta->encaminhamento, consulta->qtdEncam * sizeof(tEncaminhamento *));
    consulta->encaminhamento[consulta->qtdEncam - 1] = CriaEncaminhamento(consulta->paciente, consulta->medico, consulta->data);
    printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    char c;
    scanf("%c%*c", &c); //talvez rtirar isso daqui e colocar na main pra padronizar
}

void GeraReceita(tConsulta *consulta){
    printf("#################### CONSULTA MEDICA #######################\n");
    eTipoUso tipoUso;
    char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    char uso[7];
    int qtd;

    printf("RECEITA MEDICA:\n");

    printf("TIPO DE USO: ");
    scanf("%[^\n]%*c", uso);
    printf("NOME DO MEDICAMENTO: ");
    scanf("%[^\n]%*c", nomeMedicamento);
    printf("TIPO DE MEDICAMENTO: ");
    scanf("%[^\n]%*c", tipoMedicamento);
    printf("QUANTIDADE: ");
    scanf("%d%*c", &qtd);
    printf("INSTRUÇÕES DE USO: ");
    scanf("%[^\n]%*c", instrucoes);

    if(strcmp(uso, "ORAL") == 0){
        tipoUso = ORAL;
    }
    if(strcmp(uso, "TOPICO") == 0){
        tipoUso = TOPICO;
    }

    (consulta->qtdReceitas)++;
    consulta->receita = realloc(consulta->receita, consulta->qtdReceitas * sizeof(tReceita *));

    consulta->receita[consulta->qtdReceitas - 1] = criaReceita( ObtemNomePaciente(consulta->paciente), tipoUso, 
                                                                nomeMedicamento, tipoMedicamento, instrucoes, qtd, 
                                                                ObtemNomeMedico(consulta->medico), ObtemCRMMedico(consulta->medico), 
                                                                consulta->data);
    printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    char c;
    scanf("%c%*c", &c); //talvez rtirar isso daqui e colocar na main pra padronizar
}