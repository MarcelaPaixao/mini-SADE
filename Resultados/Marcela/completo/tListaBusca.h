#ifndef _TLISTA_BUSCA_H_
#define _TLISTA_BUSCA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tDocumento.h"
#include "tFila.h"

typedef struct tListaPacientes tListaPacientes;

tListaPacientes *CriaListaPacientes();

void AdicionaPacienteLista(tListaPacientes *lista, tPaciente *paciente);

void DesalocaListaPacientes(void *dado);

void ImprimeListaPacientesTela(void *dado);

void ImprimeListaPacientesArquivo(void *dado, char *path);

int ObtemTamanhoLista(tListaPacientes *lista);

void MenuBusca(void *dado, char *path, tFila *fila);

#endif