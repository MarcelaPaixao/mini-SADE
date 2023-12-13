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

/**
 * Função que cria um ponteiro para médico de acordo com as informações passadas como parâmetro.
 */
tMedico *CadastraMedico(char *nome, char *cpf, char *telefone, char *genero, char *CRM, 
                        char *user, char *senha, int dia, int mes, int ano){
    tMedico *medico = calloc(1, sizeof(tMedico));
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

/**
 * Função que recebe o ponteiro para médico e o desaloca da memória.
 */
void DesalocaMedico(tMedico *m){
    if(!m) return;
    free(m);
}

/**
 * Função que retorna o cpf do médico passado como parâmetro.
 */
char *ObtemCPFMedico(tMedico *m){
    char *cpf = m->cpf;
    return cpf;
}

/**
 * Função que retorna o nome do médico passado como parâmetro.
 */
char *ObtemNomeMedico(tMedico *m){
    char *nome = m->nome;
    return nome;
}

/**
 * Função que retorna o CRM do médico passado como parâmetro.
 */
char *ObtemCRMMedico(tMedico *m){
    char *CRM = m->CRM;
    return CRM;
}

/**
 * Função que retorna a senha do médico passado como parâmetro.
 */
char *ObtemSenhaMedico(tMedico *m){
    char *senha = m->senha;
    return senha;
}

/**
 * Função que retorna o nome de usuário do médico passado como parâmetro.
 */
char *ObtemUserMedico(tMedico *m){
    char *user = m->user;
    return user;
}

/**
 * Função que percorre um vetor de ponteiros para estruturas tMedico para verificar se existe 
 * algum médico cadastrado com o cpf igual ao cpf passado como parâmetro.
 * Caso encontre, retorna o índice do médico dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaSeJaExisteMedico(tMedico **medicos, int qtdMed, char *cpf){
    for(int i=0; i < qtdMed && qtdMed >= 1; i++){
        if(strcmp(medicos[i]->cpf, cpf)==0){
            return i;
        }
    }
    return -1;
}

/**
 * Função que percorre um vetor de ponteiros para estruturas tMedico para verificar se existe 
 * algum médico cadastrado com o login e senha iguais aos passados como parâmetro.
 * Caso encontre, retorna o índice do médico dentro do vetor. Caso contrário, retorna -1.
 */
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

/**
 * Função que imprime o menu de opções disponíveis para quando o usuário do sistema
 * for um médico.
 */
void ImprimeMenuMedico(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

/**
 * Função que recebe um vetor de ponteiros para estruturas tMedico, além da quantidade 
 * de medicos, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo os médicos.
 */
void SalvarMedicosEmBinario(tMedico **medicos, int qtd, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/medicos.bin", path);
    FILE *arq = fopen(diretorio, "wb");

    if (arq == NULL) {
        return;
    }

    fwrite(&qtd, sizeof(int), 1, arq);
    
    for (int i = 0; i < qtd; i++){
       fwrite(medicos[i], sizeof(tMedico), 1, arq);
    }
    
    fclose(arq);
}

/**
 * Função que recebe um ponteiro para preencher com a quatidade de médicos e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tMedico preenchido com as informações lidas.
 */
tMedico **RecuperaMedicosBinario(int *qtd, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/medicos.bin", path);
    FILE *arq = fopen(diretorio, "rb");
    
    if(arq == NULL){
        return NULL;
    }
    
    fread(qtd, sizeof(int), 1, arq);
    tMedico **medicos = malloc(*qtd * sizeof(tMedico *));
    
    for(int i=0; i < *qtd; i++){
        tMedico *medico = malloc(sizeof(tMedico));
        fread(medico, sizeof(tMedico), 1, arq);
        medicos[i] = medico;
    }
    
    fclose(arq);
    return medicos;
}