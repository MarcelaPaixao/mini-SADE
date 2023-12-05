#ifndef _TAGENTE_H_
#define _TAGENTE_H_

typedef struct tMedico tMedico;

tMedico *CadastraMedico();

typedef struct tPaciente tPaciente;

tPaciente *CadastraPaciente();

typedef struct tSecretario tSecretario;

tSecretario *CadastraSecretario();

void DesalocaMedico(tMedico *);

void DesalocaSecretario(tSecretario *);

void DesalocaPaciente(tPaciente *);

void SalvarMedico(tMedico *medico, FILE *arquivo);

void SalvarPaciente(tPaciente *paciente, FILE *arquivo);

void SalvarSecretario(tSecretario *secretario, FILE *arquivo);

tMedico *RecuperaMedico(FILE *arquivo);

tSecretario *RecuperaSecretario(FILE *arquivo);

tPaciente *RecuperaPaciente(FILE *arquivo);

/*Usar função pra verificar se ja existe alguem cadastrado com esse cpf;
usar pela main mandando todas as pessoas cadastradas
Talvez colocar função em tConsulta.h*/
int verificaEhIgualCPF(int cpf1, int cpf2);

#endif