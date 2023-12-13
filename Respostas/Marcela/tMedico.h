#ifndef _TMEDICO_H_
#define _TMEDICO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tMedico tMedico;

/**
 * Função que cria um ponteiro para médico de acordo com as informações passadas como parâmetro.
 */
tMedico *CadastraMedico(char *nome, char *cpf, char *telefone, char *genero, char *CRM, 
                        char *user, char *senha, int dia, int mes, int ano);

/**
 * Função que recebe o ponteiro para médico e o desaloca da memória.
 */
void DesalocaMedico(tMedico *);

/**
 * Função que retorna o cpf do médico passado como parâmetro.
 */
char *ObtemCPFMedico(tMedico *);

/**
 * Função que retorna o nome do médico passado como parâmetro.
 */
char *ObtemNomeMedico(tMedico *);

/**
 * Função que retorna o CRM do médico passado como parâmetro.
 */
char *ObtemCRMMedico(tMedico *);

/**
 * Função que retorna a senha do médico passado como parâmetro.
 */
char *ObtemSenhaMedico(tMedico *);

/**
 * Função que retorna o nome de usuário do médico passado como parâmetro.
 */
char *ObtemUserMedico(tMedico *);

/**
 * Função que percorre um vetor de ponteiros para estruturas tMedico para verificar se existe 
 * algum médico cadastrado com o cpf igual ao cpf passado como parâmetro.
 * Caso encontre, retorna o índice do médico dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaSeJaExisteMedico(tMedico **medicos, int qtdMed, char *cpf);

/**
 * Função que percorre um vetor de ponteiros para estruturas tMedico para verificar se existe 
 * algum médico cadastrado com o login e senha iguais aos passados como parâmetro.
 * Caso encontre, retorna o índice do médico dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaCadastroMedicos(tMedico **medicos, int qtdMed, char *login, char *senha);

/**
 * Função que imprime o menu de opções disponíveis para quando o usuário do sistema
 * for um médico.
 */
void ImprimeMenuMedico();

/**
 * Função que recebe um vetor de ponteiros para estruturas tMedico, além da quantidade 
 * de medicos, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo os médicos.
 */
void SalvarMedicosEmBinario(tMedico **medicos, int qtd, char *path);

/**
 * Função que recebe um ponteiro para preencher com a quatidade de médicos e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tMedico preenchido com as informações lidas.
 */
tMedico **RecuperaMedicosBinario(int *qtd, char *path);

#endif