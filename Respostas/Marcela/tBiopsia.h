#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tBiopsia tBiopsia;

/**
 * Função que cria um ponteiro para biópsia de acordo com as informações passadas como parâmetro.
 */
tBiopsia *CriaBiopsia(char *nomeMed, char *CRM, char *nomePac, char *cpfPac, char *data);

/**
 * Função que acrescenta uma lesão, passada como parâmetro, à biopsia tembém passada como parâmetro.
 */
void AdicionaLesao(tBiopsia *, tLesao *);

/**
 * Função que recebe o ponteiro genérico (que deve conter uma biópsia) e o desaloca da memória.
 */
void DesalocaBiopsia(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma biópsia) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void ImprimeNaTelaBiopsia(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma biópsia) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 */
void ImprimeEmArquivoBiopsia(void *dado, char *path);

#endif