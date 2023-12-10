#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tSecretario tSecretario;

tSecretario *CadastraSecretario(char *nome, char *cpf, char *telefone, char *genero, char *acesso, 
                                char *user, char *senha, int dia, int mes, int ano);

void DesalocaSecretario(tSecretario *);

void SalvarSecretariosEmBinario(tSecretario **secretarios, int qtdSec, char *path);

tSecretario **RecuperaSecretariosBinario(int *qtd, char *path);

char *ObtemCPFSecretario(tSecretario *);

char *ObtemNomeSecretario(tSecretario *);

char *ObtemSenhaSecretario(tSecretario *);

char *ObtemUserSecretario(tSecretario *);

char ObtemAcessoSecretario(tSecretario *);

int VerificaCadastroSecretario(tSecretario **secretarios, int qtdSec, char *login, char *senha);

int VerificaSeJaExisteSecretario(tSecretario **secretarios, int qtdSec, char *cpf);

void ImprimeMenuUser();

void ImprimeMenuAdmin();

#endif