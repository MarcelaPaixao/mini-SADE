#include "tMedico.h"

struct tMedico {
    char nome[100];
    char cpf[15];
    int nascDia, nascMes, nascAno;
    char telefone[15];
    char genero[10];
    char CRM[12];
    char user[20];
    char senha[20];
};

tMedico *CadastraMedico(char *nome, char *cpf, char *telefone, char *genero, char *CRM, 
                        char *user, char *senha, int dia, int mes, int ano){
    tMedico *medico = malloc(sizeof(tMedico));
    if(medico == NULL){
        exit(1);
    }  
    strcpy(medico->nome, nome);
    strcpy(medico->cpf, cpf); 
    strcpy(medico->telefone, telefone); 
    strcpy(medico->cpf, cpf); 
    strcpy(medico->genero, genero); 
    strcpy(medico->CRM, CRM); 
    strcpy(medico->user, user); 
    strcpy(medico->senha, senha); 
    medico->nascDia = dia;
    medico->nascMes = mes;
    medico->nascAno = ano;
    return medico;
}

void DesalocaMedico(tMedico *m){
    if(!m) return;
    free(m);
}

void SalvarMedico(tMedico *medico, FILE *arquivo){
    fwrite(medico, sizeof(tMedico), 1, arquivo);
}

tMedico *RecuperaMedico(FILE *arquivo){
    tMedico *medico = malloc(sizeof(tMedico));
    if(medico == NULL){
        exit(1);
    }
    fread(medico, sizeof(tMedico), 1, arquivo);
    return medico;
}

char *ObtemCPFMedico(tMedico *m){
    char *cpf = m->cpf;
    return cpf;
}

char *ObtemNomeMedico(tMedico *m){
    char *nome = m->nome;
    return nome;
}

char *ObtemCRMMedico(tMedico *m){
    char *CRM = m->CRM;
    return CRM;
}

char *ObtemSenhaMedico(tMedico *m){
    char *senha = m->senha;
    return senha;
}

char *ObtemUserMedico(tMedico *m){
    char *user = m->user;
    return user;
}

int VerificaSeJaExisteMedico(tMedico **medicos, int qtdMed, char *cpf){
     for(int i=0; i < qtdMed && qtdMed >= 1; i++){
        if(strcmp(medicos[i]->cpf, cpf)==0){
            return i;
        }
    }
    return -1;
}

int VerificaCadastroMedicos(tMedico **medicos, int qtdMed, char *login, char *senha){
    if(!medicos) return -1;
    for(int i=0; i < qtdMed; i++){
        if(strcmp(login, medicos[i]->user) == 0){
            if(strcmp(senha, medicos[i]->senha) == 0){
                return i;
            }
        }
    }
    return -1;
}

