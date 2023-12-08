#ifndef _ENCAMINHAMENTO_H_
#define _ENCAMINHAMENTO_H_

#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
typedef struct tEncaminhamento tEncaminhamento;

tEncaminhamento *CriaEncaminhamento(tPaciente *paciente, tMedico *medico, char *data);

void DesalocaEncaminhamento(void *dado);

void ImprimeNaTelaEncam(void *dado);

void ImprimeEmArquivoEncam(void *dado, char *path);

#endif