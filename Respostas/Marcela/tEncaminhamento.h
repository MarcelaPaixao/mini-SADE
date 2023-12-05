#ifndef _ENCAMINHAMENTO_H_
#define _ENCAMINHAMENTO_H_

#include "tAgente.h"
typedef struct tEncaminhamento tEncaminhamento;

tEncaminhamento *CriaEncaminhamento(tPaciente *paciente, tMedico *medico, char *data);

void DesalocaEncaminhamento(tEncaminhamento *);

void ImprimeNaTelaEncam(tEncaminhamento *);

void ImprimeEmArquivoEncam(tEncaminhamento *);

#endif