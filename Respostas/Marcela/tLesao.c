#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"

struct tLesao {
    char rotulo[6];
    char regiao[16];
    char diagnostico[25];
    int tamLesao, enviaCirurgia, enviaCrioterapia;
};

tLesao *CriaLesao(int idxRotulo){
    tLesao *lesao = malloc(sizeof(tLesao));
    if(lesao == NULL){
        exit(1);
    }
    printf("CADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%[^\n]%*c", lesao->diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%[^\n]%*c", lesao->regiao);
    printf("TAMANHO: ");
    scanf("%d%*c", &lesao->tamLesao);
    printf("ENVIAR PARA CIRURGIA: ");
    scanf("%d%*c", &lesao->enviaCirurgia);
    printf("ENVIAR PARA CRIOTERAPIA: ");
    scanf("%d%*c", &lesao->enviaCrioterapia);
    char rotulo[6];
    sprintf(rotulo, "L%d", idxRotulo);
    strcpy(lesao->rotulo, rotulo);
    return lesao;
}

void DesalocaLesao(tLesao *lesao){
    if(!lesao) return;
    free(lesao);
}

int ObtemEnviaCirugia(tLesao *lesao){
    return lesao->enviaCirurgia;
}

int ObtemEnviaCrioterapia(tLesao *lesao){
    return lesao->enviaCrioterapia;
}

char *ObtemRegiaoLesao(tLesao *lesao){
    char *regiao = lesao->regiao;
    return regiao;
}

char *ObtemDiagnosticoLesao(tLesao *lesao){
    char *diagnostico = lesao->diagnostico;
    return diagnostico;
}

int ObtemTamLesao(tLesao *lesao){
    return lesao->tamLesao;
}

char *ObtemRotuloLesao(tLesao *lesao){
    char *rotulo = lesao->rotulo;
    return rotulo;
}

void ImprimeLesaoTela(tLesao *lesao){
    printf("%s - %s - %s - %dMM\n\n", lesao->rotulo, lesao->diagnostico, lesao->regiao, lesao->tamLesao);
}

void ImprimeLesaoArquivo(tLesao *lesao, FILE *arq){
    fprintf(arq, "%s - %s - %s - %dMM\n\n", lesao->rotulo, lesao->diagnostico, lesao->regiao, lesao->tamLesao);
}
