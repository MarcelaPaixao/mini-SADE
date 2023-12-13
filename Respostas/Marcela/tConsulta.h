#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include "tBiopsia.h"
#include "tLesao.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tEncaminhamento.h"
#include "tReceita.h"
#include "tFila.h"

typedef struct tConsulta tConsulta;

/**
 * Função que cria um ponteiro para consulta e o preenche com informações do médico e do paciente passados como parâmetro,
 * além de outras infomações necessárias para a realização da consulta;
 */
tConsulta *IniciaConsulta(tPaciente *paciente, tMedico *medico);

/**
 * Função que recebe o ponteiro para consulta e o desaloca da memória.
 */
void DesalocaConsulta(tConsulta *consulta);

/**
 * Função que imprime na tela o menu de opções para o usuário realizar a consulta.
 */
void ImprimeMenuConsulta();

/**
 * Função que cadastra uma lesão dentro da consulta passada como parâmetro.
 */
void CadastraLesao(tConsulta *consulta);

/**
 * Função que, após verificar se há lesões que precisam de cirurgia, solicita a biopsia 
 * para as lesões em questão e a envia para a fila de impressão passada como parâmetro.
 */
void SolicitaBiopsia(tConsulta *consulta, tFila *fila);

/**
 * Função que cria um encaminhamento e o envia para a fila de impressão passada como parâmetro.
 */
void EncaminhaPaciente(tConsulta *consulta, tFila *fila);

/**
 * Função que lê as informações necessárias para criar uma receita e a envia para a fila de impressão passada como parâmetro.
 */
void GeraReceita(tConsulta *consulta, tFila *fila);

/**
 * Função que retorna a quantidade de lesões da consulta.
 */
int ObtemQtdLesoes(tConsulta *consulta);

/**
 * Função que retorna a soma do tamanho de todas as lesões da consulta.
 */
int ObtemSomaTamanhoLesoes(tConsulta *consulta);

/**
 * Função que retorna a soma total da quantidade de cirurgias da consulta.
 */
int ObtemTotalCirurgia(tConsulta *consulta);

/**
 * Função que retorna a soma total da quantidade de crioterapias da consulta.
 */
int ObtemTotalCrioterapia(tConsulta *consulta);

/**
 * Função que retorna uma string com cpf do paciente da consulta.
 */
char *ObtemCpfPaciente(tConsulta *consulta);

/**
 * Função que recebe um vetor de ponteiros para estruturas tConsulta, além da quantidade 
 * de consultas, e o path da pasta onde o arquivo deve ser criado, e cria um arquivo biário
 * contendo as consultas.
 */
void SalvarConsultasEmBinario(tConsulta **consultas, int qtd, char *path);

/**
 * Função que recebe um ponteiro para preencher com a quatidade de consultas e o path da pasta onde 
 * o arquivo binário está. A função lê o que está no arquivo, cria e retorna um vetor de ponteiros 
 * para estruturas tConsulta preenchido com as informações lidas.
 */
tConsulta **RecuperaConsultasBinario(int *qtd, char *path);

#endif