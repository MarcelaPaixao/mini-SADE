#ifndef _TLISTA_BUSCA_H_
#define _TLISTA_BUSCA_H_

#include "tPessoa.h"

typedef struct tListaPacientes tListaPacientes;

tListaPacientes *CriaListaPacientes();

void AdicionaPacienteLista(tListaPacientes *lista, tPaciente *paciente);

void DesalocaListaPacientes(tListaPacientes *lista);

void ImprimeListaPacientesTela(tListaPacientes *lista, tPaciente *paciente);

void ImprimeListaPacientesArquivo(tListaPacientes *lista, tPaciente *paciente, char *path);

#endif