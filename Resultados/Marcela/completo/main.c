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

int main(){
    int opcao, sec=0, med=0, qtdMed=0, qtdSec=0, qtdPac=0;
    //se existe banco de dados eu so recupero as infos e jogo na lista
    tListaPacientes *listaPacientes = CriaListaPacientes();
    tMedico **medicos = NULL;
    tSecretario **secretarios = NULL;
    tConsulta **consultas = NULL;
    

    char login[20], senha[20], nome[100], cpf[15];
    //if(existir banco de dados)
    /*while(1){
        printf("######################## ACESSO MINI-SADE ######################\n");
        printf("DIGITE SEU LOGIN: ");
        scanf("%[^\n]%*c", login);
        printf("DIGITE SUA SENHA: ");
        scanf("%[^\n]%*c", senha);
        printf("###############################################################\n");

        sec = VerificaCadastroSecretario(secretarios, login, senha);//vai retornar 1 se encontrou e 0 se nao
        med = VerificaCadastroMedicos(medicos, login, senha);//vai retornar 1 se encontrou e 0 se nao

        if(!sec && !med){
            printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
        if(sec || med){
            break;
        }
    }*/

    //if(listaPacientes == NULL){
     //   ImprimeMenuAdmin();
     //   secretarios[0] = CadastraSecretario();
    //}

    //while(1){
        qtdMed++;
        printf("#################### CADASTRO MEDICO #######################\n");
        printf("NOME COMPLETO: ");
        scanf("%[^\n]%*c", nome);
        printf("CPF: ");
        scanf("%[^\n]%*c", cpf);
        //medicos[qtdMed - 1] = CadastraMedico(nome, cpf);
        tMedico *m = CadastraMedico(nome, cpf);
        ImprimeMedico(m);
        
        //se pedir para casdastrar, ler nome, cpf, verificar se ja esta cadastrado e só aí, mandar para pessoa = FuncaoCadastra(char *nome, char *cpf);
    //}

    return 0;
}



    /*tPaciente *paciente = CadastraPaciente();
    ImprimePaciente(paciente);
    tMedico *m = CadastraMedico();
    ImprimeMedico(m);
    tSecretario *s = CadastraSecretario();
    ImprimeSecretario(s);
    */