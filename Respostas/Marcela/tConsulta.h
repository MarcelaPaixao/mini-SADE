#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include "tBiopsia.h"
#include "tLesao.h"
#include "tPessoa.h"
#include "tDocumento.h"
#include "tEncaminhamento.h"
#include "tReceita.h"

typedef struct tConsulta tConsulta;

tConsulta *IniciaConsulta(tPaciente *paciente);

void FinalizaConsulta(tConsulta *consulta);

void ImprimeMenuConsulta(tConsulta *consulta);

void ImprimeCabecalhoConsulta();

void CadastraLesao(tConsulta *consulta);

int VerificaSePrecisaCirurgia(tConsulta *consulta);

void SolicitaBiopsia(tConsulta *consulta, int idxLesao);

void EncaminhaPaciente(tConsulta *consulta);

void ImprimeReceita(tConsulta *consulta);

#endif