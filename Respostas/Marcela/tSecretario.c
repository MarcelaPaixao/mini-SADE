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
    tSecretario *secretario = calloc(1, sizeof(tSecretario));
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

void SalvarSecretariosEmBinario(tSecretario **secretarios, int qtdSec, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/secretarios.bin", path);
    FILE *arq = fopen(diretorio, "wb");

    if (arq == NULL) {
        return;
    }

    fwrite(&qtdSec, sizeof(int), 1, arq);
    
    for (int i = 0; i < qtdSec; i++){
       fwrite(secretarios[i], sizeof(tSecretario), 1, arq);
    }
    
    fclose(arq);
}

tSecretario **RecuperaSecretariosBinario(int *qtd, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/secretarios.bin", path);
    FILE *arq = fopen(diretorio, "rb");
    
    if(arq == NULL){
        return NULL;
    }
    
    fread(qtd, sizeof(int), 1, arq);
    tSecretario **secretarios = malloc(*qtd * sizeof(tSecretario *));
    
    for(int i=0; i < *qtd; i++){
        tSecretario *secretario = malloc(sizeof(tSecretario));
        fread(secretario, sizeof(tSecretario), 1, arq);
        secretarios[i] = secretario;
    }
    
    fclose(arq);
    return secretarios;
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

void ImprimeMenuUser(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(2) CADASTRAR MEDICO\n");
    printf("\t(3) CADASTRAR PACIENTE\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

void ImprimeMenuAdmin(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR SECRETARIO\n");
    printf("\t(2) CADASTRAR MEDICO\n");
    printf("\t(3) CADASTRAR PACIENTE\n");
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}