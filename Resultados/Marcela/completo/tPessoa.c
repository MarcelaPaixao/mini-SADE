#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"

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

struct tPaciente {
    char nome[100];
    char cpf[15];
    int nascDia, nascMes, nascAno;
    char telefone[15];
    char genero[10];
};

struct tSecretario {
    char nome[100];
    char cpf[15];
    int nascDia, nascMes, nascAno;
    char telefone[15];
    char genero[10];
    char user[20];
    char senha[20];
    char acesso;
};

tMedico *CadastraMedico(char *nome, char *cpf){
    tMedico *medico = malloc(sizeof(tMedico));
    if(medico == NULL){
        exit(1);
    }   
    strcpy(medico->nome, nome);
    strcpy(medico->cpf, cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%d/%d/%d%*c", &medico->nascDia, &medico->nascMes, &medico->nascAno);
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
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    printf("###############################################################\n");
    char c;
    scanf("%c%*c", &c);
    return medico;
}

tPaciente *CadastraPaciente(char *nome, char *cpf){
    tPaciente *paciente = malloc(sizeof(tPaciente));
    if(paciente == NULL){
        exit(1);
    }
    strcpy(paciente->nome, nome);
    strcpy(paciente->cpf, cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%d/%d/%d%*c", &paciente->nascDia, &paciente->nascMes, &paciente->nascAno);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", paciente->telefone);
    printf("GENERO: ");
    scanf("%[^\n]%*c", paciente->genero);
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    printf("###############################################################\n");
    char c;
    scanf("%c%*c", &c);
    return paciente;
}

tSecretario *CadastraSecretario(char *nome, char *cpf){
    tSecretario *secretario = malloc(sizeof(tSecretario));
    if(secretario == NULL){
        exit(1);
    }
    char acesso[6];
    strcpy(secretario->nome, nome);
    strcpy(secretario->cpf, cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%d/%d/%d%*c", &secretario->nascDia, &secretario->nascMes, &secretario->nascAno);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", secretario->telefone);
    printf("GENERO: ");
    scanf("%[^\n]%*c", secretario->genero);
    printf("NOME DE USUARIO: ");
    scanf("%[^\n]%*c", secretario->user);
    printf("SENHA: ");
    scanf("%[^\n]%*c", secretario->senha);
    printf("NIVEL DE ACESSO: ");
    scanf("%[^\n]%*c", acesso);
    if(acesso[0] == 'A'){
        secretario->acesso = 'A';
    }
    else if(acesso[0] == 'U'){
        secretario->acesso = 'U';
    }
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    printf("###############################################################\n");
    char c;
    scanf("%c%*c", &c);
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
    char *cpf = m->cpf;
    return cpf;
}

char *ObtemCPFPaciente(tPaciente *p){
    char *cpf = p->cpf;
    return cpf;
}

char *ObtemCPFSecretario(tSecretario *s){
    char *cpf = s->cpf;
    return cpf;
}

char *ObtemNomeMedico(tMedico *m){
    char *nome = m->nome;
    return nome;
}

char *ObtemNomePaciente(tPaciente *p){
    char *nome = p->nome;
    return nome;
}

char *ObtemNomeSecretario(tSecretario *s){
    char *nome = s->nome;
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

char *ObtemSenhaSecretario(tSecretario *s){
    char *senha = s->senha;
    return senha;
}

char *ObtemUserSecretario(tSecretario *s){
    char *user = s->user;
    return user;
}

char ObtemAcessoSecretario(tSecretario *s){
    char acesso = s->acesso;
    return acesso;
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

int VerificaCadastroSecretario(tSecretario **secretarios, char *login, char *senha){
    if(!secretarios) return 0;
    int qtd = sizeof(secretarios)/sizeof(secretarios[0]);
    for(int i=0; i < qtd; i++){
        if(strcmp(login, secretarios[0]->user) == 0){
            if(strcmp(senha, secretarios[0]->senha) == 0){
                return 1;
            }
        }
    }
    return 0;
}

int VerificaCadastroMedicos(tMedico **medicos, char *login, char *senha){
    if(!medicos) return 0;
    int qtd = sizeof(medicos)/sizeof(medicos[0]);
    for(int i=0; i < qtd; i++){
        if(strcmp(login, medicos[0]->user) == 0){
            if(strcmp(senha, medicos[0]->senha) == 0){
                return 1;
            }
        }
    }
    return 0;
}

int VerificaSeJaExisteCpf(char *cpf1, char *cpf2){
    if(strcmp(cpf1, cpf2) == 0) return 1;
    else return 0;
}

void ImprimePaciente(tPaciente *p){
    printf("PACIENTE: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("DATA DE NASCIMENTO: %d/%d/%d\n", p->nascDia, p->nascMes, p->nascAno);
    printf("TELEFONE: %s\n", p->telefone);
    printf("GENERO: %s\n", p->genero);
}

void ImprimeMedico(tMedico *p){
    printf("MEDICO: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("DATA DE NASCIMENTO: %d/%d/%d\n", p->nascDia, p->nascMes, p->nascAno);
    printf("TELEFONE: %s\n", p->telefone);
    printf("GENERO: %s\n", p->genero);
    printf("CRM: %s\n", p->CRM);
    printf("SENHA: %s\n", p->senha);
    printf("USER: %s\n", p->user);
}

void ImprimeSecretario(tSecretario *p){
    printf("SECRETARIO: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("DATA DE NASCIMENTO: %d/%d/%d\n", p->nascDia, p->nascMes, p->nascAno);
    printf("TELEFONE: %s\n", p->telefone);
    printf("GENERO: %s\n", p->genero);
    printf("ACESSO: %c\n", p->acesso);
    printf("SENHA: %s\n", p->senha);
    printf("USER: %s\n", p->user);
}
