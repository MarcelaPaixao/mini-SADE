#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tConsulta.h"

struct tConsulta {
    int diabetes, fumante, alergia, histCancer;
    int qtdLesoes;
    //int qtdReceitas, qtdEncam;
    char pele[2];
    tLesao **lesoes;
    tPaciente *paciente;
    tMedico *medico;
    char data[11];
};

tConsulta *IniciaConsulta(tPaciente *paciente, tMedico *medico){
    tConsulta *consulta = malloc(sizeof(tConsulta));
    if(!consulta){
        exit(1);
    }
    printf("---\n");
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
    
    printf("\n############################################################\n");
    
    consulta->lesoes = NULL;
    consulta->medico = medico;
    consulta->paciente = paciente;
    //consulta->qtdEncam = 0;
    //consulta->qtdReceitas = 0;
    consulta->qtdLesoes = 0;

    return consulta;
}

void DesalocaConsulta(tConsulta *consulta){
    if(!consulta) return; 
    for(int i=0; i < consulta->qtdLesoes; i++){
        DesalocaLesao(consulta->lesoes[i]);
    }
    if(consulta->lesoes) free(consulta->lesoes);
    free(consulta);
}

void ImprimeMenuConsulta(){
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR LESAO\n");
    printf("\t(2) GERAR RECEITA MEDICA\n");
    printf("\t(3) SOLICITACAO DE BIOPSIA\n");
    printf("\t(4) ENCAMINHAMENTO\n");
    printf("\t(5) ENCERRAR CONSULTA\n");
    printf("############################################################\n");
}

void CadastraLesao(tConsulta *consulta){
    if(!consulta) return;
    printf("#################### CONSULTA MEDICA #######################\n");
    (consulta->qtdLesoes)++;
    consulta->lesoes = realloc(consulta->lesoes, consulta->qtdLesoes * sizeof(tLesao *));
    consulta->lesoes[consulta->qtdLesoes - 1] = CriaLesao(consulta->qtdLesoes);
    printf("\nLESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    scanf("%*c");
}

int VerificaSePrecisaCirurgia(tConsulta *consulta){
    if(!consulta) return 0;
    for(int i=0; i < consulta->qtdLesoes; i++){
        if(ObtemEnviaCirugia(consulta->lesoes[i])){
            return 1;
        }
    }
    return 0;
}

void SolicitaBiopsia(tConsulta *consulta, tFila *fila){
    if(!consulta) return;
    printf("#################### CONSULTA MEDICA #######################\n");
    if(!VerificaSePrecisaCirurgia(consulta)){
        printf("NAO E POSSIVEL SOLICITAR BIOPSIA SEM LESAO CIRURGICA. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");
    }
    else{
       tBiopsia *biopsia = CriaBiopsia(consulta->medico, consulta->paciente, consulta->data);
        for(int i=0; i < consulta->qtdLesoes; i++){
            if(ObtemEnviaCirugia(consulta->lesoes[i])){
                AdicionaLesao(biopsia, consulta->lesoes[i]);
            }
        }
        insereDocumentoFila(fila, biopsia, ImprimeNaTelaBiopsia, ImprimeEmArquivoBiopsia, DesalocaBiopsia);
        printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");
    }
    scanf("%*c");
}

void EncaminhaPaciente(tConsulta *consulta, tFila *fila){
    if(!consulta) return;
    printf("#################### CONSULTA MEDICA #######################\n");
    tEncaminhamento *encaminhamento = CriaEncaminhamento(consulta->paciente, consulta->medico, consulta->data);
    insereDocumentoFila(fila, encaminhamento, ImprimeNaTelaEncam, ImprimeEmArquivoEncam, DesalocaEncaminhamento);
    printf("\nENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    scanf("%*c");
}

void GeraReceita(tConsulta *consulta, tFila *fila){
    if(!consulta) return;
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
    printf("INSTRUCOES DE USO: ");
    scanf("%[^\n]%*c", instrucoes);

    if(strcmp(uso, "ORAL") == 0){
        tipoUso = ORAL;
    }
    if(strcmp(uso, "TOPICO") == 0){
        tipoUso = TOPICO;
    }
        
    char nomeMedico[100];
    char CRM[12];
    if(consulta->medico == NULL){
        nomeMedico[0] = '\0';
        CRM[0] = '\0';
    }
    else {
        strcpy(ObtemNomeMedico(consulta->medico), nomeMedico);
        strcpy(ObtemCRMMedico(consulta->medico), CRM);
    }
    tReceita *receita = criaReceita( ObtemNomePaciente(consulta->paciente), tipoUso, 
                                                                nomeMedicamento, tipoMedicamento, instrucoes, qtd, 
                                                                nomeMedico, CRM, consulta->data);  
                           insereDocumentoFila(fila, receita, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);                                      
    printf("\nRECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    scanf("%*c");
}

int ObtemQtdLesoes(tConsulta *consulta){
    return consulta->qtdLesoes;
}

int ObtemSomaTamanhoLesoes(tConsulta *consulta){
    int tamanho=0;
    for(int i=0; i < consulta->qtdLesoes; i++){
        tamanho += ObtemTamLesao(consulta->lesoes[i]);
    }
    return tamanho;
}

int ObtemTotalCirurgia(tConsulta *consulta){
    int total=0;
    for(int i=0; i < consulta->qtdLesoes; i++){
        total += ObtemEnviaCirugia(consulta->lesoes[i]);
    }
    return total;
}

int ObtemTotalCrioterapia(tConsulta *consulta){
    int total=0;
    for(int i=0; i < consulta->qtdLesoes; i++){
        total += ObtemEnviaCrioterapia(consulta->lesoes[i]);
    }
    return total;
}

tPaciente *ObtemPaciente(tConsulta *consulta){
    return consulta->paciente;
}

void SalvarConsultasEmBinario(tConsulta **consultas, int qtd, char *path){
    char diretorioConsulta[1000];
    sprintf(diretorioConsulta, "%s/consultas.bin", path);
    FILE *arqConsulta = fopen(diretorioConsulta, "wb");
    
    char diretorioLesao[1000];
    sprintf(diretorioLesao, "%s/lesoes.bin", path);
    FILE *arqLesao = fopen(diretorioLesao, "wb");

    if (arqConsulta == NULL || arqLesao == NULL) {
        return;
    }
    
    fwrite(&qtd, sizeof(int), 1, arqConsulta);
    
    for (int i = 0; i < qtd; i++) {
        fwrite(consultas[i], sizeof(tConsulta), 1, arqConsulta);
        
        for (int j = 0; j < consultas[i]->qtdLesoes; j++) {
            SalvaLesoesEmBinario(consultas[i]->lesoes, consultas[i]->qtdLesoes, arqLesao);
            SalvaLesoesEmBinario(consultas[i]->lesoes, consultas[i]->qtdLesoes, arqConsulta);
        }
        SalvarPacienteEmBinario(consultas[i]->paciente, arqConsulta);
        SalvarMedicoEmBinario(consultas[i]->medico, arqConsulta);
    }

    fclose(arqConsulta);
    fclose(arqLesao);
}

tConsulta* LerConsultaBinario(FILE *arq){
    tConsulta *consulta = malloc(sizeof(tConsulta));
    if (!consulta) {
        return NULL;
    }

    fread(consulta, sizeof(tConsulta), 1, arq);

    consulta->lesoes = malloc(consulta->qtdLesoes * sizeof(tLesao*));
    for(int i=0; i < consulta->qtdLesoes; i++){
        consulta->lesoes[i] = LerLesaoBinario(arq);
    }

    consulta->paciente = LerPacienteBinario(arq);
    consulta->medico = LerMedicoBinario(arq);

    return consulta;
}

tConsulta **RecuperaConsultasBinario(int *qtd, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/consultas.bin", path);
    FILE *arqConsulta = fopen(diretorio, "rb");
    
    if(arqConsulta == NULL){
        return NULL;
    }
    
    fread(qtd, sizeof(int), 1, arqConsulta);
    tConsulta **consultas = malloc(*qtd * sizeof(tConsulta *));

    for (int i = 0; i < *qtd; i++) {
        tConsulta *consulta = LerConsultaBinario(arqConsulta);
        consultas[i] = consulta;
    }
    
    return consultas;
}