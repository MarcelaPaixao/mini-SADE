#ifndef _TLESAO_H_
#define _TLESAO_H_

typedef struct tLesao tLesao;

tLesao *CriaLesao(int idxRotulo);

void DesalocaLesao(tLesao *lesao);

int EnviaCirugia(tLesao *lesao);

int EnviaCrioterapia(tLesao *lesao);

char *ObtemRegiaoLesao(tLesao *lesao);

char *ObtemDiagnosticoLesao(tLesao *lesao);

int ObtemTamLesao(tLesao *lesao);

char *ObtemRotuloLesao(tLesao *lesao);

#endif