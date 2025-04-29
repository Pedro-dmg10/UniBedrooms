/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#ifndef _H_ESTUDANTE
#define _H_ESTUDANTE
#include "iterador.h"

/* Tipo de dados: estudante */
typedef struct _estudante * estudante;

/* Prototipos das funcoes associadas a um estudante */

/***********************************************
criaEstudante - Criacao da instancia da estrutura associada a um estudante.
Parametros:
     login - login do estudante
     nome – nome do estudante
     uni - universidade do estudante
     localidade - localidade do estudante
     idade - idade do estudante
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
estudante criaEstudante(char * login, char * nome, char * uni, char * localidade, int idade);

/***********************************************
destroiEstudante - Liberta a memoria ocupada pela instancia da estrutura associada ao estudante.
Parametros:	e - estudante a destruir
Pre-condicoes: e != NULL
***********************************************/
void destroiEstudante(estudante e);

/***********************************************
destroiGenEstudante - Liberta a memoria ocupada pela instancia da estrutura associada ao estudante.
Parametros:	e - estudante a destruir
Pre-condicoes: e != NULL
***********************************************/
void destroiGenEstudante(void * e);

/***********************************************
daNomeEstudante - Devolve o nome do estudante dado.
Parametros:
	e - estudante
Retorno: nome do estudante
Pre-condicoes: e != NULL 
***********************************************/
char * daNomeEstudante(estudante e);

/***********************************************
daIdadeEstudante - Devolve a idade do estudante dado.
Parametros:
	e - estudante
Retorno: idade do estudante
Pre-condicoes: e != NULL 
***********************************************/
int daIdadeEstudante(estudante e);

/***********************************************
daLocalidadeEstudante - Devolve a localidade do estudante dado.
Parametros:
	e - estudante
Retorno: localidade do estudante
Pre-condicoes: e != NULL 
***********************************************/
char * daLocalidadeEstudante(estudante e);

/***********************************************
daLoginEstudante - Devolve o login do estudante dado.
Parametros:
	e - estudante
Retorno: login do estudante
Pre-condicoes: e != NULL 
***********************************************/
char * daLoginEstudante(estudante e);

/***********************************************
daUniversidadeEstudante - Devolve a universidade do estudante dado.
Parametros:
	e - estudante
Retorno: universidade do estudante
Pre-condicoes: e != NULL 
***********************************************/
char * daUniversidadeEstudante(estudante e);

/***********************************************
daNCandidaturasEstudante - Consulta o numero de candidaturas do estudante dado.
Parametros:
	e - estudante
Retorno: numero de candidaturas do estudante
Pre-condicoes: e != NULL 
***********************************************/
int daNCandidaturasEstudante(estudante e);

/***********************************************
daTamanhoSeqCEstudante - Consulta o numero de elementos na sequencia.
Parametros:
	e - estudante
Retorno: numero de elementos na sequencia
Pre-condicoes: e != NULL
***********************************************/
int daTamanhoSeqCEstudante(estudante e);

/***********************************************
candidataQuartoEstudante - adiciona o codigo de um quarto a sequencia de candidaturas.
Parametros:
	e - estudante
    codigo - codigo do quarto
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: e != NULL && codigo != NULL
***********************************************/
int candidataQuartoEstudante(estudante e, char * codigo);

/***********************************************
removeSequenciaCandEstudante - Liberta a memoria ocupada pela instancia da estrutura associada a sequencia, 
                                e criacao da instancia da estrutura associada a uma sequencia.  (Remove todos os códigos que estavam na sequencia do estudante)
Parametros:
	e - estudante 
Pre-condicoes: e != NULL
***********************************************/
void removeSequenciaCandEstudante(estudante e);

/***********************************************
removeCandQuartoEstudante - Remove da sequencia de candidaturas o codigo dado                                
Parametros:
	e - estudante
    codigo - codigo a ser retirado
Pre-condicoes: e != NULL && codigo != NULL
***********************************************/
void removeCandQuartoEstudante(estudante e, char *codigo);

/***********************************************
listaCandidaturasEstudante - Cria e devolve um iterador para a sequencia.
Parametros:
	e - estudante
Retorno: iterador da sequencia de códigos de quartos
Pre-condicoes: e != NULL && vaziaSequencia(e->candidaturasE)!=1
***********************************************/
iterador listaCandidaturasEstudante(estudante e);

#endif