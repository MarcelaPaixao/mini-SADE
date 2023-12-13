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

/**
 * Função que cria um ponteiro para secretário de acordo com as informações passadas como parâmetro.
 */
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

/**
 * Função que recebe o ponteiro para secretário e o desaloca da memória.
 */
void DesalocaSecretario(tSecretario *s){
    if(!s) return;
    free(s);
}

/**
 * Função que retorna o cpf do secretário passado como parâmetro.
 */
char *ObtemCPFSecretario(tSecretario *s){
    char *cpf = s->cpf;
    return cpf;
}

/**
 * Função que retorna o nome do secretário passado como parâmetro.
 */
char *ObtemNomeSecretario(tSecretario *s){
    char *nome = s->nome;
    return nome;
}

/**
 * Função que retorna a senha do secretário passado como parâmetro.
 */
char *ObtemSenhaSecretario(tSecretario *s){
    char *senha = s->senha;
    return senha;
}

/**
 * Função que retorna o nome de usuário do secretário passado como parâmetro.
 */
char *ObtemUserSecretario(tSecretario *s){
    char *user = s->user;
    return user;
}

/**
 * Função que retorna o nível de acesso do secretário passado como parâmetro.
 */
char ObtemAcessoSecretario(tSecretario *s){
    char acesso = s->acesso;
    return acesso;
}

/**
 * Função que percorre um vetor de ponteiros para estruturas tSecretario para verificar se existe 
 * algum secretário cadastrado com o cpf igual ao cpf passado como parâmetro.
 * Caso encontre, retorna o índice do secretário dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaCadastroSecretario(tSecretario **secretarios, int qtdSec, char *login, char *senha){
    if(!secretarios) return 0;
    for(int i=0; i < qtdSec; i++){
        if(strcmp(login, secretarios[i]->user) == 0){
            if(strcmp(senha, secretarios[i]->senha) == 0){
                return i;
            }
        }
    }
    return -1;
}

/**
 * Função que percorre um vetor de ponteiros para estruturas tSecretario para verificar se existe 
 * algum secretário cadastrado com o login e senha iguais aos passados como parâmetro.
 * Caso encontre, retorna o índice do secretário dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaSeJaExisteSecretario(tSecretario **secretarios, int qtdSec, char *cpf){
    for(int i=0; i < qtdSec && qtdSec >= 1; i++){
        if(strcmp(secretarios[i]->cpf, cpf)==0){
            return i;
        }
    }
    return -1;
}

/**
 * Função que imprime o menu de opções disponíveis para quando o usuário do sistema
 * for um secretário de nível USER.
 */
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

/**
 * Função que imprime o menu de opções disponíveis para quando o usuário do sistema
 * for um secretário de nível ADMIN.
 */
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

/**
 * Função que recebe um vetor de ponteiros para estruturas tSecretario, além da quantidade 
 * de medicos, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo os secretários.
 */
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

/**
 * Função que recebe um ponteiro para preencher com a quatidade de secretários e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tSecretario preenchido com as informações lidas.
 */
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