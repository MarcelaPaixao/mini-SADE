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

#define ADMIN 'A'
#define USER 'U'


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

int main(int argc, char *argv[]){
    char nome[100], cpf[15], telefone[15], CRM[12], genero[10], acesso[6], user[20], senha[20], path[1000], nivel;
    int dia, mes, ano, flagJaExiste = 0, opcao, ehSecret=-1, ehMed=-1, qtdMed=0, qtdSec=0, qtdPac=0, qtdConsult=0;

    if (argc <= 1) {
		printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
		exit(1);
	}
    
    sprintf(path, "%s/saida", argv[1]);

    tPaciente **pacientes = NULL;
    tMedico **medicos = NULL;
    tSecretario **secretarios = malloc(sizeof(tSecretario **));
    tConsulta **consultas = malloc(sizeof(tConsulta **));
    tFila *fila = criaFila();
    

    char login[20], senha2[20];
    //if(existir banco de dados)
    /*while(1){
        printf("######################## ACESSO MINI-SADE ######################\n");
        printf("DIGITE SEU LOGIN: ");
        scanf("%[^\n]%*c", login);
        printf("DIGITE SUA SENHA: ");
        scanf("%[^\n]%*c", senha);
        printf("###############################################################\n");

        ehSecret = VerificaCadastroSecretario(secretarios, login, senha);//vai retornar o indice se encontrou e -1 se nao
        ehMed = VerificaCadastroMedicos(medicos, login, senha);//vai retornar o incide se encontrou e -1 se nao

        if(!ehSecret && !ehMed){
            printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
        if(ehSecret || ehMed){
            break;
        }
    }*/

    //int bancoDeDados = 0;
    while(1){
            nivel = ADMIN;
        //if(nivel == ADMIN || !bancoDeDados){
        if(nivel == ADMIN){
            ImprimeMenuAdmin();
        }
        else if(nivel == USER){
            ImprimeMenuUser();
        }
        else if(nivel == 'M'){
            ImprimeMenuMedico();
        }
        scanf("%d%*c", &opcao);
                
        if(opcao == 1 && nivel == ADMIN){
            printf("#################### CADASTRO SECRETARIO #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]%*c", nome);
            printf("CPF: ");
            scanf("%[^\n]%*c", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%d/%d/%d%*c", &dia, &mes, &ano);
            printf("TELEFONE: ");
            scanf("%[^\n]%*c", telefone);
            printf("GENERO: ");
            scanf("%[^\n]%*c", genero);
            printf("NOME DE USUARIO: ");
            scanf("%[^\n]%*c", user);
            printf("SENHA: ");
            scanf("%[^\n]%*c", senha);
            printf("NIVEL DE ACESSO: ");
            scanf("%[^\n]%*c", acesso);

            for(int i=0; i < qtdSec && qtdSec >= 1; i++){
                if(VerificaSeJaExisteCpf(cpf, ObtemCPFSecretario(secretarios[i]))){
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    printf("###############################################################\n");
                    flagJaExiste = 1;
                    break;
                }
            }
            if(!flagJaExiste){
                qtdSec++;
                secretarios = realloc(secretarios, qtdSec * sizeof(tSecretario *));
                secretarios[qtdSec - 1] = CadastraSecretario(nome, cpf, telefone, genero, acesso, user, senha, dia, mes, ano);
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                char c;
                scanf("%c%*c", &c);
            }
        }
        else if(opcao ==  2 && nivel != 'M'){//ou ehSec
            printf("#################### CADASTRO MEDICO #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]%*c", nome);
            printf("CPF: ");
            scanf("%[^\n]%*c", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%d/%d/%d%*c", &dia, &mes, &ano);
            printf("TELEFONE: ");
            scanf("%[^\n]%*c", telefone);
            printf("GENERO: ");
            scanf("%[^\n]%*c", genero);
            printf("CRM: ");
            scanf("%[^\n]%*c", CRM);
            printf("NOME DE USUARIO: ");
            scanf("%[^\n]%*c", user);
            printf("SENHA: ");
            scanf("%[^\n]%*c", senha);

            for(int i=0; i < qtdMed && qtdMed >= 1; i++){
                if(VerificaSeJaExisteCpf(cpf, ObtemCPFMedico(medicos[i]))){
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    printf("###############################################################\n");
                    flagJaExiste = 1;
                    break;
                }
            }
            if(!flagJaExiste){
                qtdMed++;
                medicos = realloc(medicos, qtdMed * sizeof(tMedico *));
                medicos[qtdMed - 1] = CadastraMedico(nome, cpf, telefone, genero, CRM, user, senha, dia, mes, ano);
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                char c;
                scanf("%c%*c", &c);
            }
        }
        else if(opcao == 3 && nivel != 'M'){//ou ehSec
            printf("#################### CADASTRO PACIENTE #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]%*c", nome);
            printf("CPF: ");
            scanf("%[^\n]%*c", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%d/%d/%d%*c", &dia, &mes, &ano);
            printf("TELEFONE: ");
            scanf("%[^\n]%*c", telefone);
            printf("GENERO: ");
            scanf("%[^\n]%*c", genero);

            if(VerificaSeJaExistePaciente(pacientes, qtdPac, cpf) >= 0){
                printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                printf("###############################################################\n");
                flagJaExiste = 1;
            }
            if(!flagJaExiste){
                qtdPac++;
                pacientes = realloc(pacientes, qtdPac * sizeof(tPaciente *));
                pacientes[qtdPac - 1] = CadastraPaciente(nome, cpf, telefone, genero, dia, mes, ano);
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                char c;
                scanf("%c%*c", &c);
            }
        }
        else if(opcao == 4 && nivel != USER){
            tMedico *medicoConsulta = NULL;
            printf("#################### CONSULTA MEDICA #######################\n");
            printf("CPF DO PACIENTE: ");
            scanf("%[^\n]%*c", cpf);
                
            int idxPaciente = VerificaSeJaExistePaciente(pacientes, qtdPac, cpf);
                
            if(idxPaciente < 0){
                printf("PACIENTE SEM CADASTRO\n");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                break;
            }
            if(ehMed >= 0){
                medicoConsulta = medicos[(VerificaCadastroMedicos(medicos, qtdMed, login, senha2))];
            }
            //medicoConsulta = medicos[0]; //só pra testar se funciona corretamente

            qtdConsult++;
            consultas = realloc(consultas, qtdConsult * sizeof(tConsulta *));
            consultas[qtdConsult - 1] = IniciaConsulta(pacientes[idxPaciente], medicoConsulta); 
            while(opcao != 5){
                ImprimeMenuConsulta();
                scanf("%d%*c", &opcao);//se tiver dando erro, cria outra variavel e coloca aqui
                switch (opcao)
                {
                case 1:
                    CadastraLesao(consultas[qtdConsult - 1]);
                    break;
                
                case 2:
                    GeraReceita(consultas[qtdConsult - 1], fila);
                    break;

                case 3:
                    SolicitaBiopsia(consultas[qtdConsult - 1], fila);
                    break;

                case 4:
                    EncaminhaPaciente(consultas[qtdConsult - 1], fila);
                    break;
                }
            }
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
                MenuBusca(lista, fila);
            }
            else {
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                char c;
                scanf("%c%*c", &c);
            }
        }
        else if(opcao == 6){
            char c;
            scanf("%c%*c", &c);    
        }
        else if(opcao == 7){
            char c;
            scanf("%c%*c", &c);            
        }
        else if(opcao == 8){
            break;     
        }
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