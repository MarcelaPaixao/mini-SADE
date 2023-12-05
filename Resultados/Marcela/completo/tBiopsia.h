#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tPessoa.h"

typedef struct tBiopsia tBiopsia;

tBiopsia *CriaBiopsia(tMedico *medico, tPaciente *paciente, char *data);

void AdicionaLesao(tBiopsia *);

void LiberaBiopsia(tBiopsia *);

void ImprimeNaTelaBiopsia(tBiopsia *);

void ImprimeEmBinarioBiopsia(tBiopsia *);

void ImprimeEmArquivoBiopsia(tBiopsia *biopsia, char *path);

#endif