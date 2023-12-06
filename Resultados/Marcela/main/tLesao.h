#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdio.h>

typedef struct tLesao tLesao;

tLesao *CriaLesao(int idxRotulo);

void DesalocaLesao(tLesao *lesao);

int ObtemEnviaCirugia(tLesao *lesao);

int ObtemEnviaCrioterapia(tLesao *lesao);

char *ObtemRegiaoLesao(tLesao *lesao);

char *ObtemDiagnosticoLesao(tLesao *lesao);

int ObtemTamLesao(tLesao *lesao);

char *ObtemRotuloLesao(tLesao *lesao);

void ImprimeLesaoTela(tLesao *lesao);

void ImprimeLesaoArquivo(tLesao *lesao, FILE *arq);

#endif