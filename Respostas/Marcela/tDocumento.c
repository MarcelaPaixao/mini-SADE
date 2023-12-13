#include <stdio.h>
#include <stdlib.h>
#include "tDocumento.h"

struct tDocumento {
    void *dado;
    func_ptr_imprimeNaTela funcImprimeEmTela;
    func_ptr_imprimeEmArquivo funcImprimeEmArquivo;
    func_ptr_desaloca funcDesaloca;
};

/**
 * Função que recebe um dado genérico (representando um tipo de documento) e suas funções de callback.
 * A função cria um Documento e retorna um ponteiro para ele.
 */
tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                          func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                          func_ptr_desaloca desaloca){
    tDocumento *doc = malloc(sizeof(tDocumento));
    if(doc == NULL){
        exit(1);
    }
    doc->dado = dado;
    doc->funcImprimeEmTela = imprimeNaTela;
    doc->funcImprimeEmArquivo = ImprimeEmArquivo;
    doc->funcDesaloca = desaloca;
    return doc;
}

/**
 * Função que recebe um Documento e o desaloca. O dado genérico também deve ser desalocado
 * dentro dessa função.
 */
void desalocaDocumento(tDocumento *doc){
    if(!doc) return;
    doc->funcDesaloca(doc->dado);
    free(doc);
}

/**
 * Função que recebe um Documento genérico e o imprime na tela.
 */
void imprimeNaTelaDocumento(tDocumento *doc){
    doc->funcImprimeEmTela(doc->dado);
}

/**
 * Função que recebe um Documento genérico e o imprime em um arquivo.
 * O path representa o caminho até o diretório onde o arquivo será criado ou editado.
 */
void imprimeEmArquivoDocumento(tDocumento *doc, char *path){
    doc->funcImprimeEmArquivo(doc->dado, path);
}

