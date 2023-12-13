#include "tPaciente.h"

struct tPaciente {
    char nome[100];
    char cpf[15];
    int nascDia, nascMes, nascAno, atendido;
    char telefone[15];
    char genero[10];
};

/**
 * Função que cria um ponteiro para paciente de acordo com as informações passadas como parâmetro.
 */
tPaciente *CadastraPaciente(char *nome, char *cpf, char *telefone, char *genero, int dia, int mes, int ano){
    tPaciente *paciente = calloc(1, sizeof(tPaciente));
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
    paciente->atendido = 0;
    return paciente;
}

/**
 * Função que recebe o ponteiro para paciente e o desaloca da memória.
 */
void DesalocaPaciente(tPaciente *p){
    if(!p) return;
    free(p);
}

/**
 * Função que retorna o cpf do paciente passado como parâmetro.
 */
char *ObtemCPFPaciente(tPaciente *p){
    char *cpf = p->cpf;
    return cpf;
}

/**
 * Função que retorna o nome do paciente passado como parâmetro.
 */
char *ObtemNomePaciente(tPaciente *p){
    char *nome = p->nome;
    return nome;
}

/**
 * Função que retorna o dia do nascimento do paciente passado como parâmetro.
 */
int ObtemDiaNascPaciente(tPaciente *p){
    return p->nascDia;
}

/**
 * Função que retorna o mes do nascimento do paciente passado como parâmetro.
 */
int ObtemMesNascPaciente(tPaciente *p){
    return p->nascMes;
}

/**
 * Função que retorna o ano do nascimento do paciente passado como parâmetro.
 */
int ObtemAnoNascPaciente(tPaciente *p){
    return p->nascAno;
}

/**
 * Função que retorna se paciente passado como parâmetro já foi atendido alguma vez.
 */
int ObtemSeFoiAtendidoPaciente(tPaciente *p){
    return p->atendido;
}

/**
 * Função que seta o paciente como já atendido alguma vez.
 */
void SetaAtendidoPaciente(tPaciente *p){
    (p->atendido) = 1;
}

/**
 * Função que calcula e retorna a idade do paciente passado como parâmetro.
 */
int ObtemIdadePaciente(tPaciente *p){
    int idade=0;
    idade = ANO_LIMITE - p->nascAno;

    if (MES_LIMITE < p->nascMes || (MES_LIMITE == p->nascMes && DIA_LIMITE < p->nascDia)) {
        idade--;
    }
    return idade;
}

/**
 * Função que retorna o genero do paciente passado como parâmetro.
 */
char *ObtemGeneroPaciente(tPaciente *p){
    char *genero = p->genero;
    return genero;
}

/**
 * Função que percorre um vetor de ponteiros para estruturas tPaciente para verificar se existe 
 * algum paciente cadastrado com o cpf igual ao cpf passado como parâmetro.
 * Caso encontre, retorna o índice do paciente dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaSeJaExistePaciente(tPaciente **paciente, int qtdPac, char *cpf){
    for(int i=0; i < qtdPac && qtdPac >= 1; i++){
        if(strcmp(paciente[i]->cpf, cpf)==0){
            return i;
        }
    }
    return -1;
}

/**
 * Função que recebe um vetor de ponteiros para estruturas tPaciente, além da quantidade 
 * de medicos, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo os pacientes.
 */
void SalvarPacientesEmBinario(tPaciente **pacientes, int qtd, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/pacientes.bin", path);
    FILE *arq = fopen(diretorio, "wb");

    if (arq == NULL) {
        return;
    }

    fwrite(&qtd, sizeof(int), 1, arq);
    
    for (int i = 0; i < qtd; i++){
       fwrite(pacientes[i], sizeof(tPaciente), 1, arq);
    }
    
    fclose(arq);
}

/**
 * Função que recebe um ponteiro para preencher com a quatidade de pacientes e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tPaciente preenchido com as informações lidas.
 */
tPaciente **RecuperaPacientesBinario(int *qtd, char *path){
    char diretorio[1000];
    sprintf(diretorio, "%s/pacientes.bin", path);
    FILE *arq = fopen(diretorio, "rb");
    
    if(arq == NULL){
        return NULL;
    }
    
    fread(qtd, sizeof(int), 1, arq);
    tPaciente **pacientes = malloc(*qtd * sizeof(tPaciente *));
    
    for(int i=0; i < *qtd; i++){
        tPaciente *paciente = malloc(sizeof(tPaciente));
        fread(paciente, sizeof(tPaciente), 1, arq);
        pacientes[i] = paciente;
    }
    
    fclose(arq);
    return pacientes;
}