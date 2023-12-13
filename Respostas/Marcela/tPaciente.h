#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANO_LIMITE 2023
#define MES_LIMITE 11
#define DIA_LIMITE 9

typedef struct tPaciente tPaciente;

/**
 * Função que cria um ponteiro para paciente de acordo com as informações passadas como parâmetro.
 */
tPaciente *CadastraPaciente(char *nome, char *cpf, char *telefone, char *genero, int dia, int mes, int ano);

/**
 * Função que recebe o ponteiro para paciente e o desaloca da memória.
 */
void DesalocaPaciente(tPaciente *);

/**
 * Função que retorna o cpf do paciente passado como parâmetro.
 */
char *ObtemCPFPaciente(tPaciente *);

/**
 * Função que retorna o nome do paciente passado como parâmetro.
 */
char *ObtemNomePaciente(tPaciente *);

/**
 * Função que retorna o dia do nascimento do paciente passado como parâmetro.
 */
int ObtemDiaNascPaciente(tPaciente *);

/**
 * Função que retorna o mes do nascimento do paciente passado como parâmetro.
 */
int ObtemMesNascPaciente(tPaciente *);

/**
 * Função que retorna o ano do nascimento do paciente passado como parâmetro.
 */
int ObtemAnoNascPaciente(tPaciente *);

/**
 * Função que retorna se paciente passado como parâmetro já foi atendido alguma vez.
 */
int ObtemSeFoiAtendidoPaciente(tPaciente *);

/**
 * Função que seta o paciente como já atendido alguma vez.
 */
void SetaAtendidoPaciente(tPaciente *);

/**
 * Função que calcula e retorna a idade do paciente passado como parâmetro.
 */
int ObtemIdadePaciente(tPaciente *);

/**
 * Função que retorna o genero do paciente passado como parâmetro.
 */
char *ObtemGeneroPaciente(tPaciente *);

/**
 * Função que percorre um vetor de ponteiros para estruturas tPaciente para verificar se existe 
 * algum paciente cadastrado com o cpf igual ao cpf passado como parâmetro.
 * Caso encontre, retorna o índice do paciente dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaSeJaExistePaciente(tPaciente **paciente, int qtdPac, char *cpf);

/**
 * Função que recebe um vetor de ponteiros para estruturas tPaciente, além da quantidade 
 * de medicos, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo os pacientes.
 */
void SalvarPacientesEmBinario(tPaciente **pacientes, int qtdPac, char *path);

/**
 * Função que recebe um ponteiro para preencher com a quatidade de pacientes e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tPaciente preenchido com as informações lidas.
 */
tPaciente **RecuperaPacientesBinario(int *qtd, char *path);

#endif