#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"

struct tMedico {
    char nome[100];
    char cpf[15];
    char dataNasc[11];
    char telefone[15];
    char genero[10];
    char CRM[12];
    char user[20];
    char senha[20];
};

struct tPaciente {
    char nome[100];
    char cpf[15];
    char dataNasc[11];
    char telefone[15];
    char genero[10];
};

struct tSecretario {
    char nome[100];
    char cpf[15];
    char dataNasc[11];
    char telefone[15];
    char genero[10];
    char user[20];
    char senha[20];
    char acesso[6];
};

tMedico *CadastraMedico(){
    tMedico *medico = malloc(sizeof(tMedico));
    if(medico == NULL){
        exit(1);
    }
    printf("#################### CADASTRO MEDICO #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", medico->nome);
    printf("CPF: ");
    scanf("%[^\n]%*c", medico->cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%[^\n]%*c", medico->dataNasc);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", medico->telefone);
    printf("GENERO: ");
    scanf("%[^\n]%*c", medico->genero);
    printf("CRM: ");
    scanf("%[^\n]%*c", medico->CRM);
    printf("NOME DE USUARIO: ");
    scanf("%[^\n]%*c", medico->user);
    printf("SENHA: ");
    scanf("%[^\n]%*c", medico->senha);
    return medico;
    //
    /* na main, fazer: 
    if(medico != NULL){
        printf("CADASTRO REALIZADO COM SUCESSO.");
    }*/
}

tPaciente *CadastraPaciente(){
    tPaciente *paciente = malloc(sizeof(tPaciente));
    if(paciente == NULL){
        exit(1);
    }
    printf("#################### CADASTRO PACIENTE #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", paciente->nome);
    printf("CPF: ");
    scanf("%[^\n]%*c", paciente->cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%[^\n]%*c", paciente->dataNasc);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", paciente->telefone);
    printf("GENERO: ");
    scanf("%[^\n]%*c", paciente->genero);
    return paciente;
}

tSecretario *CadastraSecretario(){
    tSecretario *secretario = malloc(sizeof(tSecretario));
    if(secretario == NULL){
        exit(1);
    }
    printf("#################### CADASTRO SECRETARIO #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", secretario->nome);
    printf("CPF: ");
    scanf("%[^\n]%*c", secretario->cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%[^\n]%*c", secretario->dataNasc);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", secretario->telefone);
    printf("GENERO: ");
    scanf("%[^\n]%*c", secretario->genero);
    printf("NOME DE USUARIO: ");
    scanf("%[^\n]%*c", secretario->user);
    printf("SENHA: ");
    scanf("%[^\n]%*c", secretario->senha);
    printf("NIVEL DE ACESSO: ");
    scanf("%[^\n]%*c", secretario->acesso);
    return secretario;
}

void DesalocaMedico(tMedico *m){
    if(!m) return;
    free(m);
}

void DesalocaSecretario(tSecretario *s){
    if(!s) return;
    free(s);
}

void DesalocaPaciente(tPaciente *p){
    if(!p) return;
    free(p);
}

void SalvarMedico(tMedico *medico, FILE *arquivo){
    fwrite(medico, sizeof(tMedico), 1, arquivo);
}

void SalvarPaciente(tPaciente *paciente, FILE *arquivo){
    fwrite(paciente, sizeof(tPaciente), 1, arquivo);
}

void SalvarSecretario(tSecretario *secretario, FILE *arquivo){
    fwrite(secretario, sizeof(tSecretario), 1, arquivo);
}

tMedico *RecuperaMedico(FILE *arquivo){
    tMedico *medico = malloc(sizeof(tMedico));
    if(medico == NULL){
        exit(1);
    }
    fread(medico, sizeof(tMedico), 1, arquivo);
    return medico;
}

tSecretario *RecuperaSecretario(FILE *arquivo){
    tSecretario *secretario = malloc(sizeof(tSecretario));
    if(secretario == NULL){
        exit(1);
    }
    fread(secretario, sizeof(tSecretario), 1, arquivo);
    return secretario;
}

tPaciente *RecuperaPaciente(FILE *arquivo){
    tPaciente *paciente = malloc(sizeof(tPaciente));
    if(paciente == NULL){
        exit(1);
    }
    fread(paciente, sizeof(tPaciente), 1, arquivo);
    return paciente;
}

int verificaEhIgualCPF(char *cpf1, char *cpf2){
    if(strcmp(cpf1, cpf2) == 0) return 1;
    else return 0;
}

char *ObtemCPFMedico(tMedico *m){
    return m->cpf;
}

char *ObtemCPFPaciente(tPaciente *p){
    return p->cpf;
}

char *ObtemCPFSecretario(tSecretario *s){
    return s->cpf;
}

char *ObtemNomeMedico(tMedico *m){
    return m->nome;
}

char *ObtemNomePaciente(tPaciente *p){
    return p->nome;
}

char *ObtemNomeSecretario(tSecretario *s){
    return s->nome;
}

char *ObtemCRMMedico(tMedico *m){
    return m->CRM;
}

char *ObtemSenhaMedico(tMedico *m){
    return m->senha;
}

char *ObtemUserMedico(tMedico *m){
    return m->user;
}

char *ObtemSenhaSecretario(tSecretario *s){
    return s->senha;
}

char *ObtemUserSecretario(tSecretario *s){
    return s->user;
}

char *ObtemAcessoSecretario(tSecretario *s){
    return s->acesso;
}

char *ObtemDataNascPaciente(tPaciente *p){
    return p->dataNasc;
}
