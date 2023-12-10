#ifndef _TMEDICO_H_
#define _TMEDICO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tMedico tMedico;

tMedico *CadastraMedico(char *nome, char *cpf, char *telefone, char *genero, char *CRM, 
                        char *user, char *senha, int dia, int mes, int ano);

void DesalocaMedico(tMedico *);

void SalvarMedicosEmBinario(tMedico **medicos, int qtd, char *path);

tMedico **RecuperaMedicosBinario(int *qtd, char *path);

char *ObtemCPFMedico(tMedico *);

char *ObtemNomeMedico(tMedico *);

char *ObtemCRMMedico(tMedico *);

char *ObtemSenhaMedico(tMedico *);

char *ObtemUserMedico(tMedico *);

int VerificaCadastroMedicos(tMedico **medicos, int qtdMed, char *login, char *senha);

int VerificaSeJaExisteMedico(tMedico **medicos, int qtdMed, char *cpf);

int EncontraIdxMedico(tMedico **medicos, int qtdMed, char *login);

void ImprimeMenuMedico();

#endif