#include "tSecretario.h"

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

tSecretario *CadastraSecretario(char *nome, char *cpf, char *telefone, char *genero, char *acesso, 
                                char *user, char *senha, int dia, int mes, int ano){
    tSecretario *secretario = malloc(sizeof(tSecretario));
    if(secretario == NULL){
        exit(1);
    }
    strcpy(secretario->nome, nome);
    strcpy(secretario->cpf, cpf); 
    strcpy(secretario->telefone, telefone); 
    strcpy(secretario->cpf, cpf); 
    strcpy(secretario->genero, genero); 
    strcpy(secretario->user, user); 
    strcpy(secretario->senha, senha); 
    secretario->nascDia = dia;
    secretario->nascMes = mes;
    secretario->nascAno = ano;
    if(acesso[0] == 'A'){
        secretario->acesso = 'A';
    }
    else if(acesso[0] == 'U'){
        secretario->acesso = 'U';
    }
    return secretario;
}

void DesalocaSecretario(tSecretario *s){
    if(!s) return;
    free(s);
}

void SalvarSecretario(tSecretario *secretario, FILE *arquivo){
    fwrite(secretario, sizeof(tSecretario), 1, arquivo);
}

tSecretario *RecuperaSecretario(FILE *arquivo){
    tSecretario *secretario = malloc(sizeof(tSecretario));
    if(secretario == NULL){
        exit(1);
    }
    fread(secretario, sizeof(tSecretario), 1, arquivo);
    return secretario;
}

char *ObtemCPFSecretario(tSecretario *s){
    char *cpf = s->cpf;
    return cpf;
}

char *ObtemNomeSecretario(tSecretario *s){
    char *nome = s->nome;
    return nome;
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

int VerificaCadastroSecretario(tSecretario **secretarios, int qtdSec, char *login, char *senha){
    if(!secretarios) return 0;
    for(int i=0; i < qtdSec; i++){
        if(strcmp(login, secretarios[i]->user) == 0){
            if(strcmp(senha, secretarios[i]->senha) == 0){
                return i;
            }
        }
    }
    return 0;
}

int VerificaSeJaExisteSecretario(tSecretario **secretarios, int qtdSec, char *cpf){
    for(int i=0; i < qtdSec && qtdSec >= 1; i++){
        if(strcmp(secretarios[i]->cpf, cpf)==0){
            return i;
        }
    }
    return -1;
}