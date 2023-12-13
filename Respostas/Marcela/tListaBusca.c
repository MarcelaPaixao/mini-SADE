#include "tListaBusca.h"

struct tListaPacientes {
    tPaciente **paciente;
    int qtdPacientes;
};

/**
 * Função que cria e retorna um ponteiro para lista de pacientes vazio.
 */
tListaPacientes *CriaListaPacientes(){
    tListaPacientes *lista = calloc(1, sizeof(tListaPacientes));
    if(!lista){
        exit(1);
    }
    lista->qtdPacientes = 0;
    lista->paciente = NULL;
    return lista;
}

/**
 * Função que acrescenta um paciente, passada como parâmetro, à lista de pacientes tembém passada como parâmetro.
 */
void AdicionaPacienteLista(tListaPacientes *lista, tPaciente *paciente){
    (lista->qtdPacientes)++;
    lista->paciente = realloc(lista->paciente, lista->qtdPacientes * sizeof(tPaciente *));
    lista->paciente[lista->qtdPacientes - 1] = paciente;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma lista de pacientes) e o desaloca da memória, 
 * mas sem desalocar a memória alocada para cada paciente.
 */
void DesalocaListaPacientes(void *dado){
    tListaPacientes *lista = (tListaPacientes*) dado;
    if(!lista) return;
    if(lista->paciente) free(lista->paciente);
    free(lista);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma lista de pacientes) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void ImprimeListaPacientesTela(void *dado){
    tListaPacientes *lista = (tListaPacientes*) dado;
    for(int i=0; i < lista->qtdPacientes; i++){
        printf("%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->paciente[i]), ObtemCPFPaciente(lista->paciente[i]));
    }
    printf("\n");
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma lista de pacientes) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 */
void ImprimeListaPacientesArquivo(void *dado, char *path){
    char diretorio[1000];
    tListaPacientes *lista = (tListaPacientes*) dado;
    sprintf(diretorio, "%s/lista_busca.txt", path);
    printf("%s\n", path);
    FILE *arq = fopen(diretorio, "a");
    if(arq){
        for(int i=0; i < lista->qtdPacientes; i++){
            fprintf(arq, "%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->paciente[i]), ObtemCPFPaciente(lista->paciente[i]));
        }
        fprintf(arq, "\n");
    fclose(arq);
    }
}

/**
 * Função que retorna a quantidade de pacientes da lista.
 */
int ObtemTamanhoLista(tListaPacientes *lista){
    return lista->qtdPacientes;
}

/**
 * Função que imprime o menu de opções da busca de pacientes.
 */
void ImprimeMenuBusca(){
    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) ENVIAR LISTA PARA IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
    printf("############################################################\n");
}