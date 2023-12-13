#ifndef _ENCAMINHAMENTO_H_
#define _ENCAMINHAMENTO_H_

#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"

typedef struct tEncaminhamento tEncaminhamento;

/**
 * Função que cria um ponteiro para encaminhamento de acordo com as informações passadas como parâmetro.
 */
tEncaminhamento *CriaEncaminhamento(char *nomeMed, char *CRM, char *nomePac, char *cpfPac, char *data);

/**
 * Função que recebe o ponteiro genérico (que deve conter um encaminhamento) e o desaloca da memória.
 */
void DesalocaEncaminhamento(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter um encaminhamento) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void ImprimeNaTelaEncam(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter um encaminhamento) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 */
void ImprimeEmArquivoEncam(void *dado, char *path);

#endif