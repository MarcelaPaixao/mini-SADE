#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"
#include "tPessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tBiopsia tBiopsia;

tBiopsia *CriaBiopsia(tMedico *medico, tPaciente *paciente, char *data);

void AdicionaLesao(tBiopsia *, tLesao *);

void DesalocaBiopsia(void *dado);

void ImprimeNaTelaBiopsia(void *dado);

void ImprimeEmBinarioBiopsia(tBiopsia *);

void ImprimeEmArquivoBiopsia(void *dado, char *path);


#endif