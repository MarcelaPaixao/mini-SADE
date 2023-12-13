#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tSecretario tSecretario;

/**
 * Função que cria um ponteiro para secretário de acordo com as informações passadas como parâmetro.
 */
tSecretario *CadastraSecretario(char *nome, char *cpf, char *telefone, char *genero, char *acesso, 
                                char *user, char *senha, int dia, int mes, int ano);

/**
 * Função que recebe o ponteiro para secretário e o desaloca da memória.
 */
void DesalocaSecretario(tSecretario *);

/**
 * Função que retorna o cpf do secretário passado como parâmetro.
 */
char *ObtemCPFSecretario(tSecretario *);

/**
 * Função que retorna o nome do secretário passado como parâmetro.
 */
char *ObtemNomeSecretario(tSecretario *);

/**
 * Função que retorna a senha do secretário passado como parâmetro.
 */
char *ObtemSenhaSecretario(tSecretario *);

/**
 * Função que retorna o nome de usuário do secretário passado como parâmetro.
 */
char *ObtemUserSecretario(tSecretario *);

/**
 * Função que retorna o nível de acesso do secretário passado como parâmetro.
 */
char ObtemAcessoSecretario(tSecretario *);

/**
 * Função que percorre um vetor de ponteiros para estruturas tSecretario para verificar se existe 
 * algum secretário cadastrado com o cpf igual ao cpf passado como parâmetro.
 * Caso encontre, retorna o índice do secretário dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaSeJaExisteSecretario(tSecretario **secretarios, int qtdSec, char *cpf);

/**
 * Função que percorre um vetor de ponteiros para estruturas tSecretario para verificar se existe 
 * algum secretário cadastrado com o login e senha iguais aos passados como parâmetro.
 * Caso encontre, retorna o índice do secretário dentro do vetor. Caso contrário, retorna -1.
 */
int VerificaCadastroSecretario(tSecretario **secretarios, int qtdSec, char *login, char *senha);

/**
 * Função que imprime o menu de opções disponíveis para quando o usuário do sistema
 * for um secretário de nível USER.
 */
void ImprimeMenuUser();

/**
 * Função que imprime o menu de opções disponíveis para quando o usuário do sistema
 * for um secretário de nível ADMIN.
 */
void ImprimeMenuAdmin();

/**
 * Função que recebe um vetor de ponteiros para estruturas tSecretario, além da quantidade 
 * de medicos, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo os secretários.
 */
void SalvarSecretariosEmBinario(tSecretario **secretarios, int qtdSec, char *path);

/**
 * Função que recebe um ponteiro para preencher com a quatidade de secretários e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tSecretario preenchido com as informações lidas.
 */
tSecretario **RecuperaSecretariosBinario(int *qtd, char *path);

#endif