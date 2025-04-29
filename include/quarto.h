/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#ifndef _H_QUARTO
#define _H_QUARTO
#include "estudante.h"
#include "iterador.h"

/* Tipo de dados: quarto */
typedef struct _quarto * quarto;

/* Prototipos das funcoes associadas a um estudante */

/***********************************************
criaQuarto - Criacao da instancia da estrutura associada a um quarto.
Parametros:
     codQuarto - codigo do quarto
     loginG – login do gerente
     nomeResidencia - nome da Residencia a que o quarto pertence
     uni - universidade do quarto
     localidade - localidade do quarto
     andar - andar do quarto
     descricao - breve descricao acerca do quarto
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
quarto criaQuarto(char * codQuarto,char * loginG, char * nomeResidencia, char * uni, char * localidade, int andar, char * descricao);

/***********************************************
destroiQuarto - Liberta a memoria ocupada pela instancia da estrutura associada ao quarto.
Parametros:	q - quarto a destruir
Pre-condicoes: q != NULL
***********************************************/
void destroiQuarto(quarto q);

/***********************************************
destroiGenQuarto - Liberta a memoria ocupada pela instancia da estrutura associada ao quarto.
Parametros:	q - quarto a destruir
Pre-condicoes: q != NULL
***********************************************/
void destroiGenQuarto(void * q);

/***********************************************
daCodQuarto - Devolve o codigo do quarto.
Parametros:
	q - quarto
Retorno: codigo do quarto
Pre-condicoes: q != NULL 
***********************************************/
char * daCodQuarto(quarto q);

/***********************************************
daNomeResidencia - Devolve o nome da residencia do quarto.
Parametros:
	q - quarto
Retorno: nome da residencia do quarto
Pre-condicoes: q != NULL 
***********************************************/
char * daNomeResidenciaQuarto(quarto q);

/***********************************************
daLocalidadeQuarto - Devolve a localidade do quarto.
Parametros:
	q - quarto
Retorno: localidade do quarto
Pre-condicoes: q != NULL 
***********************************************/
char * daLocalidadeQuarto(quarto q);

/***********************************************
daUniQuarto - Devolve a universidade do quarto.
Parametros:
	q - quarto
Retorno: universidade do quarto
Pre-condicoes: q != NULL 
***********************************************/
char * daUniQuarto(quarto q);

/***********************************************
daDescricaoQuarto - Devolve a descricao do quarto.
Parametros:
	q - quarto
Retorno: descricao do quarto
Pre-condicoes: q != NULL 
***********************************************/
char * daDescricaoQuarto(quarto q);

/***********************************************
daAndarQuarto - Devolve o andar do quarto.
Parametros:
	q - quarto
Retorno: andar do quarto
Pre-condicoes: q != NULL 
***********************************************/
int daAndarQuarto(quarto q);

/***********************************************
daOcupacaoQuarto - Devolve o estado do quarto(ocupado ou livre).
Parametros:
	q - quarto
Retorno: estado do quarto
Pre-condicoes: q != NULL 
***********************************************/
char *daOcupacaoQuarto(quarto q);

/***********************************************
dadaNCandidaturasQuarto - Devolve o numero de candidaturas feitas ao quarto.
Parametros:
	q - quarto
Retorno: numero de candidaturas feitas ao quarto
Pre-condicoes: q != NULL 
***********************************************/
int daNCandidaturasQuarto(quarto q);

/***********************************************
alteraOcupacaoQuarto - Altera o estado do quarto para o estado recebido como parametro.
Parametros:
	q - quarto
    estado - novo estado do quarto
Pre-condicoes: q != NULL && (estado == "ocupado" || estado == "livre")
***********************************************/
void alteraOcupacaoQuarto(quarto q, char *estado);

/***********************************************
daLoginGerenteQuarto - Devolve o login do gerente do quarto.
Parametros:
	q - quarto
Retorno: login do gerente do quarto
Pre-condicoes: q != NULL && estado != NULL
***********************************************/
char * daLoginGerenteQuarto(quarto q);

/***********************************************
candidataEstudanteQuarto - adiciona um estudante a sequencia de candidaturas do quarto.
Parametros:
	e - estudante
    q - quarto
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: e != NULL && q != NULL
***********************************************/
int candidataEstudanteQuarto(estudante e, quarto q);

/***********************************************
listaCandidaturasQuarto - Cria e devolve um iterador para a sequencia.
Parametros:
	q - quarto
Retorno: iterador da sequencia de estudantes
Pre-condicoes: q != NULL && vaziaSequencia(q->candidaturasQ)!=1
***********************************************/
iterador listaCandidaturasQuarto(quarto q);

/***********************************************
existeCandidaturaEstudanteQuarto - Verifica se existe uma candidatura de um estudante a um quarto.
Parametros:
	e - estudante
    q - quarto
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: e != NULL && q != NULL
***********************************************/
int existeCandidaturaEstudanteQuarto(estudante e, quarto q);

/***********************************************
removeSequenciaCandQuarto - Remove todos os estudantes que estavam na sequencia de candidaturas de um quarto                                
Parametros:
	e - estudante
    q - quarto
Pre-condicoes: e != NULL && q != NULL
***********************************************/
void removeSequenciaCandQuarto(estudante e, quarto q);

/***********************************************
removeCandEstudantesQuarto - Remove o código do quarto das sequencias de todos os estudantes que se tinham candidatado                              
Parametros:
    q - quarto
Pre-condicoes: q != NULL
***********************************************/
void removeCandEstudantesQuarto(quarto q);

/***********************************************
removeCandEstudanteQuarto - Remove o estudante das sequencias de todos os quartos a que se tinha candidatado                              
Parametros:
    q - quarto
    login - login do estudante
Pre-condicoes: q != NULL && login != NULL
***********************************************/
void removeCandEstudanteQuarto(quarto q, char * login);

/***********************************************
daCodigoGenQuarto - Da o codigo de um quarto generico.
Parametros:	q - quarto pretendido
Retorno: codigo do quarto
Pre-condicoes: q != NULL
***********************************************/
void * daCodigoGenQuarto(void * q);

/***********************************************
comparaGenQuarto - compara o codigo generico de dois quartos.
Parametros:	cod1 - codigo do quarto1
            cod2 - codigo do quarto2
Retorno: 1,0,-1 de acordo com o codigo superior.            
Pre-condicoes: cod1 & cod2 != NULL
***********************************************/
int comparaGenQuarto(void * cod1, void * cod2);

#endif