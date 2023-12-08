#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  tRelatorio tRelatorio;

tRelatorio *criaRelatorio();

void DesalocaRelatorio(void *dado);

void ImprimeNaTelaRelatorio(void *dado);

void ImprimeEmArquivorelatorio(void *dado);

#endif