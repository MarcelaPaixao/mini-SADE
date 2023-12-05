#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tListaBusca.h"

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

void DesalocaListaPacientes(tListaPacientes *lista){
    if(!lista) return;
    if(lista->paciente) free(lista->paciente);
    free(lista);
}

void ImprimeListaPacientesTela(tListaPacientes *lista, tPaciente *paciente){
    for(int i=0; i < lista->qtdPacientes; i++){
        if(strcmp(ObtemNomePaciente(lista->paciente[i]), ObtemNomePaciente(paciente)) == 0){
            printf("%d - %s (%s)\n", i, ObtemNomePaciente(lista->paciente[i]), ObtemCPFPaciente(lista->paciente[i]));
        }
    }
}

void ImprimeListaPacientesArquivo(tListaPacientes *lista, tPaciente *paciente, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/lista_busca.txt", path);
    FILE *arq = fopen(diretorio, "a");
    for(int i=0; i < lista->qtdPacientes; i++){
        if(strcmp(ObtemNomePaciente(lista->paciente[i]), ObtemNomePaciente(paciente)) == 0){
            fprintf(arq, "%d - %s (%s)\n", i, ObtemNomePaciente(lista->paciente[i]), ObtemCPFPaciente(lista->paciente[i]));
        }
    }
}