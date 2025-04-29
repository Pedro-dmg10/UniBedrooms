/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#ifndef _H_GERENTE
#define _H_GERENTE

/* Tipo de dados: gerente */
typedef struct _gerente * gerente;

/* Prototipos das funcoes associadas a um estudante */

/***********************************************
criaGerente - Criacao da instancia da estrutura associada a um gerente.
Parametros:
     login - login do gerente
     nome – nome do gerente
     uni - universidade do gerente
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
gerente criaGerente(char *login, char *nome, char*uni);

/***********************************************
destroiGerente - Liberta a memoria ocupada pela instancia da estrutura associada ao gerente.
Parametros:	g - gerente a destruir
Pre-condicoes: g != NULL
***********************************************/
void destroiGerente(gerente g);

/***********************************************
destroiGenGerente - Liberta a memoria ocupada pela instancia da estrutura associada ao gerente.
Parametros:	g - gerente a destruir
Pre-condicoes: g != NULL
***********************************************/
void destroiGenGerente(void * g);

/***********************************************
daLoginGerente - Devolve o login do gerente dado.
Parametros:
	g - gerente
Retorno: login do gerente
Pre-condicoes: g != NULL 
***********************************************/
char * daLoginGerente(gerente g);

/***********************************************
daNomeGerente - Devolve o nome do gerente dado.
Parametros:
	g - gerente
Retorno: nome do gerente
Pre-condicoes: g != NULL 
***********************************************/
char * daNomeGerente(gerente g);

/***********************************************
daUniversidadeGerente - Devolve a universidade do gerente dado.
Parametros:
	g - gerente
Retorno: universidade do gerente
Pre-condicoes: g != NULL 
***********************************************/
char * daUniversidadeGerente(gerente g);

/***********************************************
daNQAlugadosGerente - Retorna o número de quartos alugados por um gerente.
Parametros:
g - Gerente
Retorno: Número de quartos alugados pelo gerente
Pre-condicoes: g != NULL
***********************************************/
int daNQAlugadosGerente(gerente g);

/***********************************************
addQAlugadosGerente - Incrementa o número de quartos alugados por um gerente.
Parametros:
g - Gerente
Retorno: N/A
Pre-condicoes: g != NULL
***********************************************/
void addQAlugadosGerente(gerente g);

/***********************************************
subQAlugadosGerente - Decrementa o número de quartos alugados por um gerente.
Parametros:
g - Gerente
Retorno: N/A
Pre-condicoes: g != NULL
***********************************************/
void subQAlugadosGerente(gerente g);

#endif