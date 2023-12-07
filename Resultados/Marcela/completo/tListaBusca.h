#ifndef _TLISTA_BUSCA_H_
#define _TLISTA_BUSCA_H_

#include "tPessoa.h"

typedef struct tListaPacientes tListaPacientes;

tListaPacientes *CriaListaPacientes();

void AdicionaPacienteLista(tListaPacientes *lista, tPaciente *paciente);

void DesalocaListaPacientes(tListaPacientes *lista);

void ImprimeListaPacientesTela(tListaPacientes *lista, char *nome);

void ImprimeListaPacientesArquivo(tListaPacientes *lista, char *nome, char *path);

int ObtemTamanhoLista(tListaPacientes *lista);

#endif