#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include "tBiopsia.h"
#include "tLesao.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tEncaminhamento.h"
#include "tReceita.h"
#include "tFila.h"

typedef struct tConsulta tConsulta;

tConsulta *IniciaConsulta(tPaciente *paciente, tMedico *medico);

void DesalocaConsulta(tConsulta *consulta);

void ImprimeMenuConsulta();

void CadastraLesao(tConsulta *consulta);

void SolicitaBiopsia(tConsulta *consulta, tFila *fila);

void EncaminhaPaciente(tConsulta *consulta, tFila *fila);

void GeraReceita(tConsulta *consulta, tFila *fila);

int ObtemQtdLesoes(tConsulta *consulta);

int ObtemSomaTamanhoLesoes(tConsulta *consulta);

int ObtemTotalCirurgia(tConsulta *consulta);

int ObtemTotalCrioterapia(tConsulta *consulta);

char *ObtemCpfPaciente(tConsulta *consulta);

void SalvarConsultasEmBinario(tConsulta **consultas, int qtd, char *path);

tConsulta **RecuperaConsultasBinario(int *qtd, char *path);

tConsulta **RecuperaConsultasBinario(int *qtd, char *path);

#endif