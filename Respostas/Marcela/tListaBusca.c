#include "tListaBusca.h"
#include <stdio.h>
#include <stdlib.h>

struct tListaPacientes {
    tPaciente **paciente;
    int qtdPacientes;
};

tListaPacientes *CriaListaPacientes(){
    tListaPacientes *lista = malloc(sizeof(tListaPacientes));
    if(!lista){
        exit(1);
    }
    lista->qtdPacientes = 0;
    lista->paciente = NULL;
    return lista;
}

void AdicionaPacienteLista(tListaPacientes *lista, tPaciente *paciente){
    (lista->qtdPacientes)++;
    lista->paciente = realloc(lista->paciente, lista->qtdPacientes * sizeof(tPaciente *));
    lista->paciente[lista->qtdPacientes - 1] = paciente;
}

void DesalocaListaPacientes(void *dado){
    tListaPacientes *lista = (tListaPacientes*) dado;
    if(!lista) return;
    if(lista->paciente) free(lista->paciente);
    free(lista);
}

void ImprimeListaPacientesTela(void *dado){
    tListaPacientes *lista = (tListaPacientes*) dado;
    printf("PACIENTES ENCONTRADOS:\n");
    for(int i=0; i < lista->qtdPacientes; i++){
        printf("%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->paciente[i]), ObtemCPFPaciente(lista->paciente[i]));
    }
    printf("\n###############################################################\n");

}

void ImprimeListaPacientesArquivo(void *dado, char *path){
    char diretorio[1000];
    tListaPacientes *lista = (tListaPacientes*) dado;
    sprintf(diretorio, "%s/lista_busca.txt", path);
    FILE *arq = fopen(diretorio, "a");
    for(int i=0; i < lista->qtdPacientes; i++){
        fprintf(arq, "%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->paciente[i]), ObtemCPFPaciente(lista->paciente[i]));
    }
}

int ObtemTamanhoLista(tListaPacientes *lista){
    return lista->qtdPacientes;
}

void MenuBusca(void *dado, tFila *fila){
    tListaPacientes *lista = (tListaPacientes*) dado;
    int opcao;
    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) ENVIAR LISTA PARA IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
    printf("############################################################\n");
    scanf("%d%*c", &opcao);
    if(opcao == 1){
        insereDocumentoFila(fila, lista, ImprimeListaPacientesTela, ImprimeListaPacientesArquivo, DesalocaListaPacientes);
        printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");
    }
    if(opcao == 2){
        return;
    }
}