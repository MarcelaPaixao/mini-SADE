#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLesao.h"
#include "tPaciente.h"
#include "tConsulta.h"

typedef struct  tRelatorio tRelatorio;

/**
 * Função que gera um relatório de acordo com as informações passadas como parâmetro.
 */
tRelatorio *GeraRelatorio(tConsulta **consultas, int qtdConsulta, tPaciente **pacientes, int qtdPac);

/**
 * Função que recebe o ponteiro genérico (que deve conter um relatório) e o desaloca da memória.
 */
void DesalocaRelatorio(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter um relatório) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void ImprimeNaTelaRelatorio(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter um relatório) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 */
void ImprimeEmArquivoRelatorio(void *dado, char *path);

/**
 * Função que imprime do relatório e o menu de opções relacionado a ele.
 */
void ImprimeMenuRelatorio(tRelatorio *relatorio);

#endif