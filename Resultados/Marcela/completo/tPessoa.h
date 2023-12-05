#ifndef _TPESSOA_H_
#define _TPESSOA_H_

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

char *ObtemAcessoSecretario(tSecretario *);

char *ObtemDataNascPaciente(tPaciente *);

#endif