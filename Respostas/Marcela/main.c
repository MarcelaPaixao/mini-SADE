#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"
#include "tLesao.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tEncaminhamento.h"
#include "tConsulta.h"
#include "tListaBusca.h"
#include "tReceita.h"
#include "tFila.h"
#include "tRelatorio.h"

#define ADMIN 'A'
#define USER 'U'

int main(int argc, char *argv[]){
    char nome[100], cpf[15], telefone[15], CRM[12], genero[10], acesso[6], user[20];
    char login[20], code[20], senha[20], nivel;
    int dia, mes, ano, flagJaExiste = 0, opcao, ehSecret=-1, ehMed=-1;
    int qtdMed=0, qtdSec=0, qtdPac=0, qtdConsult=0;

    if (argc <= 1) {
		printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
		exit(1);
	}
    
    char pathBanco[1000], path[500], banco[500];
    sprintf(path, "%s/saida", argv[1]);
    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS: ");
    scanf("%[^\n]%*c", banco);
    sprintf(pathBanco, "%s/%s", argv[1], banco);
    printf("################################################\n");
    printf("Caminho do banco de dados: %s\n", pathBanco);
    printf("Caminho da pasta de saida: %s\n", path);

    //tPaciente **pacientes = NULL;
    tPaciente **pacientes = RecuperaPacientesBinario(&qtdPac, pathBanco);
    //tMedico **medicos = NULL;
    tMedico ** medicos = RecuperaMedicosBinario(&qtdMed, pathBanco);
    //tSecretario **secretarios = NULL;
    tSecretario **secretarios = RecuperaSecretariosBinario(&qtdSec, pathBanco);
    tConsulta **consultas = NULL;
    
    tFila *fila = criaFila();
    tListaPacientes *listaPacientes = NULL;
    tRelatorio *relatorio = NULL;

    //significa q n tem banco de dados, pq obrigatoriamente existe pelo menos 1 secretario
    if(secretarios == NULL){
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
        qtdSec++;
        secretarios = realloc(secretarios, qtdSec * sizeof(tSecretario *));
        secretarios[qtdSec - 1] = CadastraSecretario(nome, cpf, telefone, genero, acesso, user, senha, dia, mes, ano);
    }
    
    while(1){
        printf("######################## ACESSO MINI-SADE ######################\n");
        printf("DIGITE SEU LOGIN: ");
        scanf("%[^\n]%*c", login);
        printf("DIGITE SUA SENHA: ");
        scanf("%[^\n]%*c", code);
        printf("###############################################################\n");

        ehSecret = VerificaCadastroSecretario(secretarios, qtdSec, login, code);//vai retornar o indice se encontrou e -1 se nao
        ehMed = VerificaCadastroMedicos(medicos, qtdMed, login, code);//vai retornar o indice se encontrou e -1 se nao

        if(ehSecret < 0 && ehMed < 0){
            printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
        else {
            break;
        }
    }

    if(ehSecret >= 0){
        nivel = ObtemAcessoSecretario(secretarios[ehSecret]);
    }

    while(1){
        if(nivel == ADMIN){
            ImprimeMenuAdmin();
        }
        else if(nivel == USER){
            ImprimeMenuUser();
        }
        else if(ehMed >= 0){
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

            if(VerificaSeJaExisteSecretario(secretarios, qtdSec, cpf) >= 0){
                printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                printf("###############################################################\n");
                flagJaExiste = 1;
            }
            
            if(!flagJaExiste){
                qtdSec++;
                secretarios = realloc(secretarios, qtdSec * sizeof(tSecretario *));
                secretarios[qtdSec - 1] = CadastraSecretario(nome, cpf, telefone, genero, acesso, user, senha, dia, mes, ano);
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                scanf("%*c");
            }
        }
        else if(opcao ==  2 && ehMed < 0){
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

            if(VerificaSeJaExisteMedico(medicos, qtdMed, cpf) >= 0){
                printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                printf("###############################################################\n");
                flagJaExiste = 1;
            }

            if(!flagJaExiste){
                qtdMed++;
                medicos = realloc(medicos, qtdMed * sizeof(tMedico *));
                medicos[qtdMed - 1] = CadastraMedico(nome, cpf, telefone, genero, CRM, user, senha, dia, mes, ano);
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                scanf("%*c");
            }
        }
        else if(opcao == 3 && ehMed < 0){
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
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################\n");
                scanf("%*c");
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
                medicoConsulta = medicos[(VerificaCadastroMedicos(medicos, qtdMed, login, code))];
            }

            qtdConsult++;
            consultas = realloc(consultas, qtdConsult * sizeof(tConsulta *));
            consultas[qtdConsult - 1] = IniciaConsulta(pacientes[idxPaciente], medicoConsulta); 
            SetaAtendidoPaciente(pacientes[idxPaciente]);
            opcao = 0;

            while(opcao != 5){
                ImprimeMenuConsulta();
                scanf("%d%*c", &opcao);
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
                case 5:
                    break;
                }
            }
        }
        else if(opcao == 5){
            listaPacientes = CriaListaPacientes();
            char nomePaciente[100];

            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: ");
            scanf("%[^\n]%*c", nomePaciente);

            for(int i=0; i < qtdPac; i++){
                if(strcmp(nomePaciente, ObtemNomePaciente(pacientes[i])) == 0){
                    AdicionaPacienteLista(listaPacientes, pacientes[i]);
                }
            }
            if(ObtemTamanhoLista(listaPacientes) > 0){
                printf("PACIENTES ENCONTRADOS:\n");
                ImprimeListaPacientesTela(listaPacientes);
                MenuBusca(listaPacientes, fila);
            }
            else {
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                scanf("%*c");
            }
        }
        else if(opcao == 6){
            relatorio = GeraRelatorio(consultas, qtdConsult, pacientes, qtdPac);
            printf("#################### RELATORIO GERAL #######################\n");
            ImprimeNaTelaRelatorio(relatorio);
            printf("\nESCOLHA UMA OPCAO:\n");
            printf("\t(1) ENVIAR PARA IMPRESSAO\n");
            printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n");
            
            scanf("%d%*c", &opcao);
            switch (opcao)
            {
            case 1:
                insereDocumentoFila(fila, relatorio, ImprimeNaTelaRelatorio, ImprimeEmArquivoRelatorio, DesalocaRelatorio);
                printf("\nRELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");
                scanf("%*c");
                break;
            
            case 2:
                break;
            }                 
        }
        else if(opcao == 7){
            while(opcao != 2){
                printf("################ FILA DE IMPRESSAO MEDICA ##################\n");
                printf("ESCOLHA UMA OPCAO:\n");
                printf("\t(1) EXECUTAR FILA DE IMPRESSAO\n");
                printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
                printf("############################################################\n");
                scanf("%d%*c", &opcao);
                switch (opcao)
                {
                case 1:
                    printf("################ FILA DE IMPRESSAO MEDICA ##################\n");
                    printf("EXECUTANDO FILA DE IMPRESSAO:\n");
                    if(fila){
                        imprimeFila(fila, path);
                    }
                    printf("\nPRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
                    printf("############################################################\n");
                    scanf("%*c");
                    break;
                
                case 2:
                    break;
                } 
            }               
        }
        else if(opcao == 8){
            break;     
        }
    }      

    SalvarMedicosEmBinario(medicos, qtdMed, pathBanco);
    SalvarSecretariosEmBinario(secretarios, qtdSec, pathBanco);
    SalvarPacientesEmBinario(pacientes, qtdPac, pathBanco);

    desalocaFila(fila);   

    for(int i=0; i < qtdMed; i++){
        DesalocaMedico(medicos[i]);
    }
    if(medicos) free(medicos);

    for(int i=0; i < qtdSec; i++){
        DesalocaSecretario(secretarios[i]);
    } 
    if(secretarios) free(secretarios); 

    for(int i=0; i < qtdPac; i++){
        DesalocaPaciente(pacientes[i]);
    } 
    if(pacientes) free(pacientes); 

    for(int i=0; i < qtdConsult; i++){
        DesalocaConsulta(consultas[i]);
    }
    if(consultas) free(consultas);
    
    return 0;
}