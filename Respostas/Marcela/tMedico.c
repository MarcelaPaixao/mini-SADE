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

void DesalocaMedico(tMedico *m){
    if(!m) return;
    free(m);
}

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

void SalvarMedicoEmBinario(tMedico *medico, FILE *arq){
    fwrite(medico, sizeof(tMedico), 1, arq);
}

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

tMedico* LerMedicoBinario(FILE *arq){
    tMedico *medico = malloc(sizeof(tMedico));
    if (!medico) {
        return NULL;
    }
    fread(medico, sizeof(tMedico), 1, arq);
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
