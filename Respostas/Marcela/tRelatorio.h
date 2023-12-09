#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLesao.h"
#include "tPaciente.h"
#include "tConsulta.h"

typedef struct  tRelatorio tRelatorio;

tRelatorio *GeraRelatorio(tConsulta **consultas, int qtdConsulta, tPaciente **pacientes, int qtdPac);

void DesalocaRelatorio(void *dado);

void ImprimeNaTelaRelatorio(void *dado);

void ImprimeEmArquivoRelatorio(void *dado, char *path);

#endif