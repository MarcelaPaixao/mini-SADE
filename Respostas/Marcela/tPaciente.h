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

void SalvarPacientesEmBinario(tPaciente **pacientes, int qtdPac, char *path);

void SalvarPacienteEmBinario(tPaciente *paciente, FILE *arq);

tPaciente **RecuperaPacientesBinario(int *qtd, char *path);

tPaciente* LerPacienteBinario(FILE *arq);

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