#include "tRelatorio.h"

struct  tRelatorio {
    int qtdPacientesAtend, qtdFem, qtdMasc, qtdOutros;
    int qtdLesoes, qtdCirurgia, qtdCrioterapia;
    int mediaIdade, mediaLesoes;
};

tRelatorio *GeraRelatorio(tConsulta **consultas, int qtdConsulta, tPaciente **pacientes, int qtdPac){
    tRelatorio *relatorio = malloc(sizeof(tRelatorio));
    if(!relatorio){
        exit(1);
    }
    relatorio->qtdPacientesAtend = 0;
    relatorio->qtdFem = 0;
    relatorio->qtdMasc = 0;
    relatorio->qtdOutros = 0;
    relatorio->qtdLesoes = 0;
    relatorio->qtdCirurgia = 0;
    relatorio->qtdCrioterapia = 0;
    relatorio->mediaIdade = 0;
    relatorio->mediaLesoes = 0;

    char *cpf;
    for(int i=0; i < qtdConsulta && qtdConsulta >= 1; i++){
        (relatorio->qtdLesoes) += ObtemQtdLesoes(consultas[i]);
        (relatorio->mediaLesoes) += ObtemSomaTamanhoLesoes(consultas[i]);
        (relatorio->qtdCirurgia) += ObtemTotalCirurgia(consultas[i]);
        (relatorio->qtdCrioterapia) += ObtemTotalCrioterapia(consultas[i]);
        
    }
    if(relatorio->qtdLesoes){
        relatorio->mediaLesoes = (relatorio->mediaLesoes)/(relatorio->qtdLesoes);
    }
    
    for(int i=0; i < qtdPac && qtdPac >= 1; i++){
        if(strcmp(ObtemGeneroPaciente(pacientes[i]), "FEMININO") == 0){
            (relatorio->qtdFem)++;
        }
        else if(strcmp(ObtemGeneroPaciente(pacientes[i]), "MASCULINO") == 0){
            (relatorio->qtdMasc)++;
        }
        else if(strcmp(ObtemGeneroPaciente(pacientes[i]), "OUTROS") == 0){
            (relatorio->qtdOutros)++;
        }
        (relatorio->mediaIdade) += ObtemIdadePaciente(pacientes[i]);
        if(ObtemSeFoiAtendidoPaciente(pacientes[i])){
            (relatorio->qtdPacientesAtend)++;
        }
    }
    if(qtdPac){
        (relatorio->mediaIdade) = (relatorio->mediaIdade)/qtdPac;
    }

    return relatorio;
}

void DesalocaRelatorio(void *dado){
    if(!dado)return;
    tRelatorio *r = (tRelatorio *) dado;
    if(r) free(r);
}

void ImprimeNaTelaRelatorio(void *dado){
    tRelatorio *r = (tRelatorio *) dado;
    printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", r->qtdPacientesAtend);
    printf("IDADE MEDIA: %d\n", r->mediaIdade);
    printf("DISTRIBUICAO POR GENERO:\n");
    printf("- FEMININO: %d\n", r->qtdFem);
    printf("- MASCULINO: %d\n", r->qtdMasc);
    printf("- OUTROS: %d\n", r->qtdOutros);
    printf("TAMANHO MEDIO DAS LESOES: %d\n", r->mediaLesoes);
    printf("NUMERO TOTAL DE LESOES: %d\n", r->qtdLesoes);
    printf("NUMERO TOTAL DE CIRURGIAS: %d\n", r->qtdCirurgia);
    printf("NUMERO TOTAL DE CRIOTERAPIA: %d\n", r->qtdCrioterapia);
}

void ImprimeEmArquivoRelatorio(void *dado, char *path){
    tRelatorio *r = (tRelatorio *) dado;
    char diretorio[1000];
    sprintf(diretorio, "%s/relatorio_geral.txt", path);
    FILE *arq = fopen(diretorio, "w");

    fprintf(arq, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", r->qtdPacientesAtend);
    fprintf(arq, "IDADE MEDIA: %d\n", r->mediaIdade);
    fprintf(arq, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arq, "- FEMININO: %d\n", r->qtdFem);
    fprintf(arq, "- MASCULINO: %d\n", r->qtdMasc);
    fprintf(arq, "- OUTROS: %d\n", r->qtdOutros);
    fprintf(arq, "TAMANHO MEDIO DAS LESOES: %d\n", r->mediaLesoes);
    fprintf(arq, "NUMERO TOTAL DE LESOES: %d\n", r->qtdLesoes);
    fprintf(arq, "NUMERO TOTAL DE CIRURGIAS: %d\n", r->qtdCirurgia);
    fprintf(arq, "NUMERO TOTAL DE CRIOTERAPIA: %d\n", r->qtdCrioterapia);

    fclose(arq);
}
