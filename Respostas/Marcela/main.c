#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tConsulta.h"
#include "tListaBusca.h"
#include "tReceita.h"
#include "tFila.h"
#include "tRelatorio.h"

#define ADMIN 'A'
#define USER 'U'

typedef enum{
    SECRETARIO,
    MEDICO,
    PACIENTE
}ePessoa;

//Lê as informações do secretário, do paciente e do médico;
void LePessoa(ePessoa tipo, char *nome, char *cpf, int *dia, int *mes, int *ano, char *telefone, 
              char *genero, char *CRM, char *user, char *senha, char *acesso){
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", nome);
    printf("CPF: ");
    scanf("%[^\n]%*c", cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%d/%d/%d%*c", dia, mes, ano);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", telefone);
    printf("GENERO: ");
    scanf("%[^\n]%*c", genero);
    if(tipo == PACIENTE) return;
    if(tipo == MEDICO){
        printf("CRM: ");
        scanf("%[^\n]%*c", CRM);
    }
    printf("NOME DE USUARIO: ");
    scanf("%[^\n]%*c", user);
    printf("SENHA: ");
    scanf("%[^\n]%*c", senha);
    if(tipo == SECRETARIO){
        printf("NIVEL DE ACESSO: ");
        scanf("%[^\n]%*c", acesso);
    }
}

int main(int argc, char *argv[]){
    char nome[100], cpf[15], telefone[15], CRM[12], genero[10], acesso[6], user[20];
    char login[20], code[20], senha[20], nivel = '\0';
    int dia=0, mes=0, ano=0, flagJaExiste=0, opcao=0, ehSecret=-1, ehMed=-1;
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

    //Caso existam as iformações no banco de dados, os vetores são preenchidos, caso contrário, 
    //a função retorna NULL;
    tPaciente **pacientes = RecuperaPacientesBinario(&qtdPac, pathBanco);
    tMedico ** medicos = RecuperaMedicosBinario(&qtdMed, pathBanco);
    tSecretario **secretarios = RecuperaSecretariosBinario(&qtdSec, pathBanco);
    tConsulta **consultas = RecuperaConsultasBinario(&qtdConsult, pathBanco);
    tFila *fila = criaFila();
    tListaPacientes *listaPacientes = NULL;
    tRelatorio *relatorio = NULL;

    //Significa que é o primeiro acesso, pois se não fosse, obrigatoriamente haveria ao menos 1 secretario;
    if(secretarios == NULL){
        printf("#################### CADASTRO SECRETARIO #######################\n");
        LePessoa(SECRETARIO, nome, cpf, &dia, &mes, &ano, telefone, genero, CRM, user, senha, acesso);
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

        //Vai retornar o índice se encontrar e -1 caso contrário;
        ehSecret = VerificaCadastroSecretario(secretarios, qtdSec, login, code);
        ehMed = VerificaCadastroMedicos(medicos, qtdMed, login, code);

        //Se nenhum dos dois foi encontrado, o login está incorreto;
        if(ehSecret < 0 && ehMed < 0){
            printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
        //Se um dos dois foi encontrado, o login teve sucesso
        else {
            //Caso seja secretário, obtem seu nível de acesso
            if(ehSecret >= 0){
                nivel = ObtemAcessoSecretario(secretarios[ehSecret]);
            }
            break;
        }
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
            flagJaExiste = 0;
            printf("#################### CADASTRO SECRETARIO #######################\n");
            LePessoa(SECRETARIO, nome, cpf, &dia, &mes, &ano, telefone, genero, CRM, user, senha, acesso);

            //Vai retornar o índice se encontrar e -1 caso contrário;
            if(VerificaSeJaExisteSecretario(secretarios, qtdSec, cpf) >= 0){
                printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                printf("###############################################################\n");
                flagJaExiste = 1;
            }
            
            //Se ainda não existir, cadastra um novo secretário
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
            flagJaExiste = 0;
            printf("#################### CADASTRO MEDICO #######################\n");
            LePessoa(MEDICO, nome, cpf, &dia, &mes, &ano, telefone, genero, CRM, user, senha, acesso);

            //Vai retornar o índice se encontrar e -1 caso contrário;
            if(VerificaSeJaExisteMedico(medicos, qtdMed, cpf) >= 0){
                printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                printf("###############################################################\n");
                flagJaExiste = 1;
            }

            //Se ainda não existir, cadastra um novo medico
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
            flagJaExiste = 0;
            printf("#################### CADASTRO PACIENTE #######################\n");
            LePessoa(PACIENTE, nome, cpf, &dia, &mes, &ano, telefone, genero, CRM, user, senha, acesso);

            //Vai retornar o índice se encontrar e -1 caso contrário;
            if(VerificaSeJaExistePaciente(pacientes, qtdPac, cpf) >= 0){
                printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                flagJaExiste = 1;
            }

            //Se ainda não existir, cadastra um novo paciente
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
                scanf("%*c");
            }
            //Caso o paciente já esteja cadastrado, a consulta é iniciada e é fornecido um novo menu e opções;
            else {
                //Verifica se quem está realizando a consulta é médico e, caso seja, obtem seu índice 
                //dentro do vetor de médicos;
                if(ehMed >= 0){
                    medicoConsulta = medicos[(VerificaCadastroMedicos(medicos, qtdMed, login, code))];
                }

                qtdConsult++;
                consultas = realloc(consultas, qtdConsult * sizeof(tConsulta *));
                consultas[qtdConsult - 1] = IniciaConsulta(pacientes[idxPaciente], medicoConsulta); 
                
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
                    //Aponta que paciente já foi atendido ao menos uma vez em alguma consulta;
                    SetaAtendidoPaciente(pacientes[idxPaciente]);
                }
            }
        }
        else if(opcao == 5){
            char nomePaciente[100];
            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: ");
            scanf("%[^\n]%*c", nomePaciente);

            int encontrou=0;
            //Compara o nome lido com o nome de todos pacientes cadastrados e, caso encontre, cria uma lista
            //e adiciona todos pacientes com esse nome nela;
            for(int i=0; i < qtdPac; i++){
                if(strcmp(nomePaciente, ObtemNomePaciente(pacientes[i])) == 0){
                    if(!encontrou){
                        listaPacientes = CriaListaPacientes();
                        encontrou = 1;
                    }
                    AdicionaPacienteLista(listaPacientes, pacientes[i]);
                }
            }
            //Caso a lista tenha sido criada, é fornecido um novo menu de opções ao usuário;
            if(encontrou){
                printf("PACIENTES ENCONTRADOS:\n");
                ImprimeListaPacientesTela(listaPacientes);
                ImprimeMenuBusca();
                scanf("%d%*c", &opcao);
                switch (opcao)
                {
                case 1:
                    insereDocumentoFila(fila, listaPacientes, ImprimeListaPacientesTela, ImprimeListaPacientesArquivo, DesalocaListaPacientes);
                    printf("\nLISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
                    printf("############################################################\n");
                    scanf("%*c");
                    break;
                
                case 2:
                    break;
                }
            }
            else {
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                scanf("%*c");
            }
        }
        else if(opcao == 6){
            //O relatório é gerado e é fornecido um novo menu e opções;
            relatorio = GeraRelatorio(consultas, qtdConsult, pacientes, qtdPac);
            ImprimeMenuRelatorio(relatorio);
            
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
            //Fecha o sistema;
            break;     
        }
    }      

    //Salva os arquivos binários necessários para consultas futuras;
    SalvarMedicosEmBinario(medicos, qtdMed, pathBanco);
    SalvarSecretariosEmBinario(secretarios, qtdSec, pathBanco);
    SalvarPacientesEmBinario(pacientes, qtdPac, pathBanco);
    SalvarConsultasEmBinario(consultas, qtdConsult, pathBanco); 

    //Desaloca a memória alocada e finaliza o programa;
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
    desalocaFila(fila);  

    return 0;
}