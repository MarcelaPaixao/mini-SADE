#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"

struct tLesao {
    char rotulo[5];
    int tamRotulo; //colocar em consulta????
    //eRegiao regiao;
    //eDiagnostico diagnostico;
    char regiao[15];
    char diagnostico[24];
    int tamLesao, enviaCirurgia, enviaCrioterapia;
};

tLesao *CriaLesao(){
    tLesao *lesao = malloc(sizeof(tLesao));
    if(lesao == NULL){
        exit(1);
    }
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%[^\n]%*c", lesao->diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%[^\n]%*c", lesao->regiao);
    printf("TAMANHO ");
    scanf("%[^\n]%*c", lesao->tamLesao);
    printf("ENVIAR PARA CIRURGIA: ");
    scanf("%d", lesao->enviaCirurgia);
    printf("ENVIAR PARA CRIOTERAPIA: ");
    scanf("%d", lesao->enviaCrioterapia);
    lesao->tamRotulo = 0;
    return lesao;
}



void DesalocaLesao(tLesao *lesao){
    if(!lesao) return;
    free(lesao);
}

int EnviaCirugia(tLesao *lesao){
    return lesao->enviaCirurgia;
}

int EnviaCrioterapia(tLesao *lesao){
    return lesao->enviaCrioterapia;
}

