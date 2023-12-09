#include <stdio.h>
#include <stdlib.h>
#include "tFila.h"
#include "tDocumento.h"

struct tFila {
    tDocumento **documentos;
    int qtdDoc;
};

/**
 * Função que cria uma fila de impressao vazia e retorna um ponteiro para ela.
 */
tFila *criaFila(){
    tFila *fila = malloc(sizeof(tFila));
    if(fila == NULL){
        exit(1);
    }
    fila->documentos = NULL;
    fila->qtdDoc = 0;
    return fila;
}

/**
 * Função que recebe um ponteiro para uma fila de impressao e desaloca toda a memória
 * associada a ela. Essa função também desaloca todos os documentos associados a fila.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaFila(tFila *f){
    if(!f) return;
    for(int i=0; i < f->qtdDoc; i++){
        desalocaDocumento(f->documentos[i]);
    }
    free(f->documentos);
    free(f);
}

/**
 * Função que recebe uma fila, um dado genérico e suas funções de callback para criar um Documento com esses elementos
 * e inseri-lo na fila de impressão. Perceba que a fila é agnóstica ao tipo de dado e pode conter
 * múltiplos Documentos (limitados pela memória) aguardando para serem impressos.
 *
 */
void insereDocumentoFila(tFila *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                         func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                         func_ptr_desaloca desaloca){
    tDocumento *doc = criaDocumento(dado, imprimeNaTela, ImprimeEmArquivo, desaloca);
    (f->qtdDoc)++;
    f->documentos = realloc(f->documentos, f->qtdDoc * sizeof(tDocumento *));
    f->documentos[f->qtdDoc - 1] = doc;
}

/**
 * Função que recebe uma fila e retorna quantos documentos existem dentro dela.
 */
int quantidadeDocumentosNaFila(tFila *f){
    return f->qtdDoc;
}

/**
 * Função que invoca as funções de impressão de Documento executando a impressão de todos os documentos da fila.
 * A impressão é feita em duas etapas, primeiro o Documento é impresso na tela e depois em arquivo. 
 * A função também recebe o path para o diretório onde o arquivo deve ser criado ou editado 
 */
void imprimeFila(tFila *f, char *path){
    for(int i=0; i < f->qtdDoc; i++){
        imprimeNaTelaDocumento(f->documentos[i]);
        imprimeEmArquivoDocumento(f->documentos[i], path);
        printf("\n");
    }
}

