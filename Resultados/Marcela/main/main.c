#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"
#include "tLesao.h"
#include "tPessoa.h"
#include "tDocumento.h"
#include "tEncaminhamento.h"
#include "tReceita.h"
#include "tConsulta.h"
#include "tListaBusca.h"
#include "tReceita.h"
#include "tFila.h"


void ImprimeMenuAdmin(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO\n");
    printf("\t(1) CADASTRAR SECRETARIO\n");
    printf("\t(2) CADASTRAR MEDICO\n");
    printf("\t(3) CADASTRAR PACIENTE\n");
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

void ImprimeMenuUser(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO\n");
    printf("\t(2) CADASTRAR MEDICO\n");
    printf("\t(3) CADASTRAR PACIENTE\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

void ImprimeMenuMedico(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO\n");
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

void CadastrarSecretarioMain(tSecretario **secretarios, int qtdSec){
    char nome[100], cpf[15];

    for(int i=0; i < qtdSec; i++){
        if(VerificaSeJaExisteCpf(cpf, ObtemCPFSecretario(secretarios[i]))){
            printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");    
            printf("###############################################################\n");
            return;
        }
    }
    secretarios = realloc(secretarios, qtdSec * sizeof(tSecretario *));
    secretarios[qtdSec - 1] = CadastraSecretario(nome, cpf);
}

void CadastrarPacienteMain(tPaciente **pacientes, int qtdPac){
    char nome[100], cpf[15];

    for(int i=0; i < qtdPac; i++){
        if(VerificaSeJaExisteCpf(cpf, ObtemCPFPaciente(pacientes[i]))){
            printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");    
            printf("###############################################################\n");
            return;
        }
    }
    pacientes = realloc(pacientes, qtdPac * sizeof(tPaciente *));
    pacientes[qtdPac - 1] = CadastraPaciente(nome, cpf);
}

int main(){
    int opcao, ehSecret=0, ehMed=0, qtdMed=0, qtdSec=0, qtdPac=0;
    char acesso;

    char *path = NULL;

    tPaciente **pacientes = malloc(sizeof(tPaciente **));
    tMedico **medicos = malloc(sizeof(tMedico **));
    tSecretario **secretarios = malloc(sizeof(tSecretario **));
    tConsulta **consultas = malloc(sizeof(tConsulta **));
    tFila *fila = criaFila();
    

    char login[20], senha[20];
    //if(existir banco de dados)
    /*while(1){
        printf("######################## ACESSO MINI-SADE ######################\n");
        printf("DIGITE SEU LOGIN: ");
        scanf("%[^\n]%*c", login);
        printf("DIGITE SUA SENHA: ");
        scanf("%[^\n]%*c", senha);
        printf("###############################################################\n");

        ehSecret = VerificaCadastroSecretario(secretarios, login, senha);//vai retornar 1 se encontrou e 0 se nao
        ehMed = VerificaCadastroMedicos(medicos, login, senha);//vai retornar 1 se encontrou e 0 se nao

        if(!ehSecret && !ehMed){
            printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
        if(ehSecret || ehMed){
            break;
        }
    }*/

    //if(listaPacientes == NULL){
     //   ImprimeMenuAdmin();
     //   secretarios[0] = CadastraSecretario();
    //}

    while(1){
            acesso = 'A';
        if(acesso == 'A'){
            ImprimeMenuAdmin();
        }
        else if(acesso == 'U'){
            ImprimeMenuUser();
        }
        else if(acesso == 'M'){
            ImprimeMenuMedico();
        }
        scanf("%d%*c", &opcao);
                
        if(opcao == 1 && acesso == 'A'){
            CadastrarSecretarioMain(secretarios, qtdSec);
        }
        else if(opcao ==  2 && acesso != 'M'){//ou ehSec
            CadastraMedico(medicos, qtdMed);
        }
        else if(opcao == 3 && acesso != 'M'){//ou ehSec
            qtdPac++;
            CadastrarPacienteMain(pacientes, qtdPac);
        }
        else if(opcao == 4 && acesso == 'A'){
                    
        }
        else if(opcao == 5){
            tListaPacientes *lista = CriaListaPacientes();
            char nomePaciente[100];
            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: ");
            scanf("%[^\n]%*c", nomePaciente);
            for(int i=0; i < qtdPac; i++){
                if(strcmp(nomePaciente, ObtemNomePaciente(pacientes[i])) == 0){
                    AdicionaPacienteLista(lista, pacientes[i]);
                }
            }
            if(ObtemTamanhoLista(lista) > 0){
                ImprimeListaPacientesTela(lista);
                ImprimeListaPacientesArquivo(lista, path);
                MenuBusca(lista, path, fila);
            }
            else {
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
            }
            
        }
        else if(opcao == 6){
                    
        }
        else if(opcao == 7){
                    
         }
        else if(opcao == 8){
                    
        }
        char c;
        scanf("%c%*c", &c);
    }      
            

    return 0;
}



    /*tPaciente *paciente = CadastraPaciente();
    ImprimePaciente(paciente);
    tMedico *m = CadastraMedico();
    ImprimeMedico(m);
    tSecretario *s = CadastraSecretario();
    ImprimeSecretario(s);
    */