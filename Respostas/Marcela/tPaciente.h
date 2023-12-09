#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANO_LIMITE 2023
#define MES_LIMITE 11
#define DIA_LIMITE 9

typedef struct tPaciente tPaciente;

tPaciente *CadastraPaciente(char *nome, char *cpf, char *telefone, char *genero, int dia, int mes, int ano);

void DesalocaPaciente(tPaciente *);

void SalvarPaciente(tPaciente *paciente, FILE *arquivo);

tPaciente *RecuperaPaciente(FILE *arquivo);

char *ObtemCPFPaciente(tPaciente *);

char *ObtemNomePaciente(tPaciente *);

int ObtemDiaNascPaciente(tPaciente *);

int ObtemMesNascPaciente(tPaciente *);

int ObtemAnoNascPaciente(tPaciente *);

int ObtemSeFoiAtendidoPaciente(tPaciente *);

void SetaAtendidoPaciente(tPaciente *);

int ObtemIdadePaciente(tPaciente *);

char *ObtemGeneroPaciente(tPaciente *);

int VerificaSeJaExistePaciente(tPaciente **paciente, int qtdPac, char *cpf);

#endif