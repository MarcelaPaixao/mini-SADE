#ifndef _TLISTA_BUSCA_H_
#define _TLISTA_BUSCA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tFila.h"

typedef struct tListaPacientes tListaPacientes;

/**
 * Função que cria e retorna um ponteiro para lista de pacientes vazio.
 */
tListaPacientes *CriaListaPacientes();

/**
 * Função que acrescenta um paciente, passada como parâmetro, à lista de pacientes tembém passada como parâmetro.
 */
void AdicionaPacienteLista(tListaPacientes *lista, tPaciente *paciente);

/**
 * Função que recebe o ponteiro genérico (que deve conter uma lista de pacientes) e o desaloca da memória, 
 * mas sem desalocar a memória alocada para cada paciente.
 */
void DesalocaListaPacientes(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma lista de pacientes) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void ImprimeListaPacientesTela(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma lista de pacientes) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 */
void ImprimeListaPacientesArquivo(void *dado, char *path);

/**
 * Função que retorna a quantidade de pacientes da lista.
 */
int ObtemTamanhoLista(tListaPacientes *lista);

/**
 * Função que imprime o menu de opções da busca de pacientes.
 */
void ImprimeMenuBusca();

#endif