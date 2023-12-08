#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *ObtemGeneroPaciente(tPaciente *);

int VerificaSeJaExistePaciente(tPaciente **paciente, int qtdPac, char *cpf);

#endif