#ifndef _TPESSOA_H_
#define _TPESSOA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tMedico tMedico;

tMedico *CadastraMedico(char *nome, char *cpf, char *telefone, char *genero, char *CRM, char *user, char *senha, int dia, int mes, int ano);

typedef struct tPaciente tPaciente;

tPaciente *CadastraPaciente(char *nome, char *cpf, char *telefone, char *genero, int dia, int mes, int ano);

typedef struct tSecretario tSecretario;

tSecretario *CadastraSecretario(char *nome, char *cpf, char *telefone, char *genero, char *acesso, char *user, char *senha, int dia, int mes, int ano);

void DesalocaMedico(tMedico *);

void DesalocaSecretario(tSecretario *);

void DesalocaPaciente(tPaciente *);

void SalvarMedico(tMedico *medico, FILE *arquivo);

void SalvarPaciente(tPaciente *paciente, FILE *arquivo);

void SalvarSecretario(tSecretario *secretario, FILE *arquivo);

tMedico *RecuperaMedico(FILE *arquivo);

tSecretario *RecuperaSecretario(FILE *arquivo);

tPaciente *RecuperaPaciente(FILE *arquivo);

int verificaEhIgualCPF(char *cpf1, char *cpf2);

char *ObtemCPFMedico(tMedico *);

char *ObtemCPFPaciente(tPaciente *);

char *ObtemCPFSecretario(tSecretario *);

char *ObtemNomeMedico(tMedico *);

char *ObtemNomePaciente(tPaciente *);

char *ObtemNomeSecretario(tSecretario *);

char *ObtemCRMMedico(tMedico *);

char *ObtemSenhaMedico(tMedico *);

char *ObtemUserMedico(tMedico *);

char *ObtemSenhaSecretario(tSecretario *);

char *ObtemUserSecretario(tSecretario *);

char ObtemAcessoSecretario(tSecretario *);

int ObtemDiaNascPaciente(tPaciente *);

int ObtemMesNascPaciente(tPaciente *);

int ObtemAnoNascPaciente(tPaciente *);

char *ObtemGeneroPaciente(tPaciente *);

int VerificaCadastroSecretario(tSecretario **secretarios, int qtdSec, char *login, char *senha);

int VerificaCadastroMedicos(tMedico **medicos, int qtdMed, char *login, char *senha);

int VerificaSeJaExisteCpf(char *cpf1, char *cpf2);

int VerificaSeJaExistePaciente(tPaciente **paciente, int qtdPac, char *cpf);

int EncontraIdxMedico(tMedico **medicos, int qtdMed, char *login);

#endif