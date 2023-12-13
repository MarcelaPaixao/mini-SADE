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

/**
 * Função que cria um ponteiro para lesão de acordo o rótulo passado como parâmetro.
 */
tLesao *CriaLesao(int idxRotulo){
    tLesao *lesao = calloc(1, sizeof(tLesao));
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

/**
 * Função que recebe o ponteiro para lesão e o desaloca da memória.
 */
void DesalocaLesao(tLesao *lesao){
    if(!lesao) return;
    free(lesao);
}

/**
 * Função que retorna se a lesão precisa de cirurgia.
 */
int ObtemEnviaCirugia(tLesao *lesao){
    return lesao->enviaCirurgia;
}

/**
 * Função que retorna se a lesão precisa de crioterapia.
 */
int ObtemEnviaCrioterapia(tLesao *lesao){
    return lesao->enviaCrioterapia;
}

/**
 * Função que retorna a região da lesão.
 */
char *ObtemRegiaoLesao(tLesao *lesao){
    char *regiao = lesao->regiao;
    return regiao;
}

/**
 * Função que retorna o diagnóstico clínico da lesão.
 */
char *ObtemDiagnosticoLesao(tLesao *lesao){
    char *diagnostico = lesao->diagnostico;
    return diagnostico;
}

/**
 * Função que retorna o tamanho da lesão.
 */
int ObtemTamLesao(tLesao *lesao){
    return lesao->tamLesao;
}

/**
 * Função que retorna o rótulo da lesão.
 */
char *ObtemRotuloLesao(tLesao *lesao){
    char *rotulo = lesao->rotulo;
    return rotulo;
}

/**
 * Função que recebe um ponteiro para lesão e imprime os dados na tela
 * de acordo com o especificado.
 */
void ImprimeLesaoTela(tLesao *lesao){
    printf("%s - %s - %s - %dMM\n\n", lesao->rotulo, lesao->diagnostico, lesao->regiao, lesao->tamLesao);
}

/**
 * Função que recebe um ponteiro para lesão  e o arquivo em que os dados devem ser impressos.
 */
void ImprimeLesaoArquivo(tLesao *lesao, FILE *arq){
    fprintf(arq, "%s - %s - %s - %dMM\n\n", lesao->rotulo, lesao->diagnostico, lesao->regiao, lesao->tamLesao);
}

/**
 * Função que recebe um vetor de ponteiros para estruturas tLesao, além da quantidade 
 * de lesões, e o arquivo biário em que as lesões devem ser salvas.
 */
void SalvaLesoesEmBinario(tLesao **lesoes, int qtd, FILE *arq){
    for(int i = 0; i < qtd; i++){
        //Verifica se não é NULL;
        if(lesoes[i]){
            fwrite(lesoes[i], sizeof(tLesao), 1, arq);
        }
    }
}

/**
 * Função que recebe a quatidade de consultas e um arquivo binário.
 * A função lê o que está no arquivo binário, cria e retorna um vetor de ponteiros para estruturas tLesao
 *  preenchido com as informações lidas.
 */
tLesao **RecuperaLesoesBinario(FILE *arq, int qtd){
    tLesao **lesoes = malloc(qtd * sizeof(tLesao *));
    for(int i=0; i < qtd; i++){
        //Primeiro é alocado o espaço para a lesão e depois ela é lida do arquivo binário;
        lesoes[i] = malloc(sizeof(tLesao));
        fread(lesoes[i], sizeof(tLesao), 1, arq);
    }
    return lesoes;
}