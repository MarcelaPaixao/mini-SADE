#include "tPaciente.h"

struct tPaciente {
    char nome[100];
    char cpf[15];
    int nascDia, nascMes, nascAno;
    char telefone[15];
    char genero[10];
};

tPaciente *CadastraPaciente(char *nome, char *cpf, char *telefone, char *genero, int dia, int mes, int ano){
    tPaciente *paciente = malloc(sizeof(tPaciente));
    if(paciente == NULL){
        exit(1);
    }
    strcpy(paciente->nome, nome);
    strcpy(paciente->cpf, cpf);
    strcpy(paciente->telefone, telefone); 
    strcpy(paciente->cpf, cpf); 
    strcpy(paciente->genero, genero); 
    paciente->nascDia = dia;
    paciente->nascMes = mes;
    paciente->nascAno = ano;
    return paciente;
}

void DesalocaPaciente(tPaciente *p){
    if(!p) return;
    free(p);
}

void SalvarPaciente(tPaciente *paciente, FILE *arquivo){
    fwrite(paciente, sizeof(tPaciente), 1, arquivo);
}

tPaciente *RecuperaPaciente(FILE *arquivo){
    tPaciente *paciente = malloc(sizeof(tPaciente));
    if(paciente == NULL){
        exit(1);
    }
    fread(paciente, sizeof(tPaciente), 1, arquivo);
    return paciente;
}

char *ObtemCPFPaciente(tPaciente *p){
    char *cpf = p->cpf;
    return cpf;
}

char *ObtemNomePaciente(tPaciente *p){
    char *nome = p->nome;
    return nome;
}

int ObtemDiaNascPaciente(tPaciente *p){
    return p->nascDia;
}

int ObtemMesNascPaciente(tPaciente *p){
    return p->nascMes;
}

int ObtemAnoNascPaciente(tPaciente *p){
    return p->nascAno;
}

char *ObtemGeneroPaciente(tPaciente *p){
    char *genero = p->genero;
    return genero;
}

int VerificaSeJaExistePaciente(tPaciente **paciente, int qtdPac, char *cpf){
    for(int i=0; i < qtdPac && qtdPac >= 1; i++){
        if(strcmp(paciente[i]->cpf, cpf)==0){
            return i;
        }
    }
    return -1;
}