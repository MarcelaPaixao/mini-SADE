#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdio.h>

typedef struct tLesao tLesao;

/**
 * Função que cria um ponteiro para lesão de acordo o rótulo passado como parâmetro.
 */
tLesao *CriaLesao(int idxRotulo);

/**
 * Função que recebe o ponteiro para lesão e o desaloca da memória.
 */
void DesalocaLesao(tLesao *lesao);

/**
 * Função que retorna se a lesão precisa de cirurgia.
 */
int ObtemEnviaCirugia(tLesao *lesao);

/**
 * Função que retorna se a lesão precisa de crioterapia.
 */
int ObtemEnviaCrioterapia(tLesao *lesao);

/**
 * Função que retorna a região da lesão.
 */
char *ObtemRegiaoLesao(tLesao *lesao);

/**
 * Função que retorna o diagnóstico clínico da lesão.
 */
char *ObtemDiagnosticoLesao(tLesao *lesao);

/**
 * Função que retorna o tamanho da lesão.
 */
int ObtemTamLesao(tLesao *lesao);

/**
 * Função que retorna o rótulo da lesão.
 */
char *ObtemRotuloLesao(tLesao *lesao);

/**
 * Função que recebe um ponteiro para lesão e imprime os dados na tela
 * de acordo com o especificado.
 */
void ImprimeLesaoTela(tLesao *lesao);

/**
 * Função que recebe um ponteiro para lesão  e o arquivo em que os dados devem ser impressos.
 */
void ImprimeLesaoArquivo(tLesao *lesao, FILE *arq);

/**
 * Função que recebe um vetor de ponteiros para estruturas tLesao, além da quantidade 
 * de lesões, e o arquivo biário em que as lesões devem ser salvas.
 */
void SalvaLesoesEmBinario(tLesao **lesoes, int qtd, FILE *arq);

/**
 * Função que recebe a quatidade de consultas e um arquivo binário.
 * A função lê o que está no arquivo binário, cria e retorna um vetor de ponteiros para estruturas tLesao
 *  preenchido com as informações lidas.
 */
tLesao **RecuperaLesoesBinario(FILE *arq, int qtd);

#endif