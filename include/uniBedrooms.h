/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#ifndef _H_UNIBEDROOMS
#define _H_UNIBEDROOMS
#include "estudante.h"
#include "gerente.h"
#include "quarto.h"
#include "localidade.h"
#include "iterador.h"

/* Tipo de dados: uniBedrooms */
typedef struct _uniBedrooms * uniBedrooms;


/* Prototipos das funcoes associadas a uniBedrooms */

/***********************************************
criaUniBedrooms - Criacao da instancia da estrutura associada a uniBedrooms.
Parametros:
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
uniBedrooms criaUniBedrooms();

/***********************************************
destroiUniBedrooms - Liberta a memoria ocupada pela instancia da estrutura associada a uniBedrooms.
Parametros:	u - uniBedrooms a destruir
Pre-condicoes: u != NULL
***********************************************/
void destroiUniBedrooms(uniBedrooms u);

/***********************************************
criaEstudanteUniBedrooms - cria um estudante e insere-o no dicionario de estudantes no uniBedrooms.
Parametros:
	u - uniBedrooms
    login - login do estudante
    nome - nome do estudante
    uni - universidade do estudante
    localidade - localidade do estudante
    idade - idade do estudante
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL && !existeGerenteUniBedrooms
***********************************************/
int criaEstudanteUniBedrooms(uniBedrooms u, char * login, char * nome,char * uni, char * localidade, int idade);

/***********************************************
removeEstudanteUniBedrooms - remove um estudante do dicionario de estudantes no uniBedrooms.
Parametros:
	u - uniBedrooms
    login - login do estudante
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL &&  removeElemDicionario
***********************************************/
int removeEstudanteUniBedrooms(uniBedrooms u, char *login);

/***********************************************
daEstudanteUniBedrooms - retorna o estudante identificado pelo seu login.
Parametros:
	u - uniBedrooms
    login - login do estudante
Retorno: retorna o estudante
Pre-condicoes: u != NULL && login != NULL
***********************************************/
estudante daEstudanteUniBedrooms(uniBedrooms u, char *login);


/***********************************************
numEstudantesUniBedrooms - retorna o  numero de estudantes no uniBedrooms.
Parametros:
	u - uniBedrooms
Retorno: Numero de Estudantes
Pre-condicoes: u != NULL 
***********************************************/
int numEstudantesUniBedrooms(uniBedrooms u);

/***********************************************
existeEstudanteUniBedrooms - retorna se existe o estudante com o login dado.
Parametros:
	u - uniBedrooms
Retorno: 1 se existir , 0 caso contrario
Pre-condicoes: u != NULL 
***********************************************/
int existeEstudanteUniBedrooms(uniBedrooms u, char *login);

/***********************************************
daNCndidaturasEstudanteUniBedrooms - retorna o numero de candidaturas de um estudante no unibedrooms.
Parametros:
	u - uniBedrooms
    login - login do estudante
Retorno: Numero de candidaturas
Pre-condicoes: u != NULL && login != NULL
***********************************************/
int daNCndidaturasEstudanteUniBedrooms(uniBedrooms u, char *login);

/***********************************************
criaGerenteUniBedrooms - cria um gerente e insere-o no dicionario de gerentes no uniBedrooms.
Parametros:
	u - uniBedrooms
    loginG - login do gerente
    nome - nome do gerente
    universidade - universidade do gerente
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL && !existeEstudanteUniBedrooms
***********************************************/
int criaGerenteUniBedrooms(uniBedrooms u, char *loginG, char *nome, char *universidade);

/***********************************************
daGerenteUniBedrooms - retorna o gerente identificado pelo seu login.
Parametros:
	u - uniBedrooms
    login - login do gerente
Retorno: retorna o gerente
Pre-condicoes: u != NULL && login != NULL
***********************************************/
gerente daGerenteUniBedrooms(uniBedrooms u, char *login);

/***********************************************
existeGerenteUniBedrooms - retorna se existe o gerente com o login dado.
Parametros:
	u - uniBedrooms
    login - login do gerente
Retorno: 1 se existir , 0 caso contrario
Pre-condicoes: u != NULL && login != NULL
***********************************************/
int existeGerenteUniBedrooms(uniBedrooms u, char *login);

/***********************************************
uniGerenteUniBedrooms - Devolve a universidade do gerente.
Parametros:
	u - uniBedrooms
    login - login do gerente
Retorno: Universidade do gerente
Pre-condicoes: u != NULL && login != NULL
***********************************************/
char * uniGerenteUniBedrooms(uniBedrooms u, char * login);

/***********************************************
criaQuartoUniBedrooms - cria um quarto e insere-o no dicionario de quartos no uniBedrooms.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
    loginG - login do gerente
    nomeDaResidencia - nome da residencia
    universidade - universidade do quarto
    localidade - localidade do quarto
    andar - andar do quarto
    descricao - descricao do quarto
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL && q ! = NULL
***********************************************/
int criaQuartoUniBedrooms(uniBedrooms u, char *codigo, char *loginG, char *nomeDaResidencia, char *universidade, char *localidade, int andar, char *descricao);

/***********************************************
removeQuartoUniBedrooms - remove o quarto identificado pelo seu codigo do dicionário de quartos.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
void  removeQuartoUniBedrooms(uniBedrooms u, char * codigo);

/***********************************************
daQuartoUniBedrooms - retorna o quarto identificado pelo seu codigo.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Retorno: retorna o quarto
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
quarto daQuartoUniBedrooms(uniBedrooms u, char *codigo);

/***********************************************
existeQuartoUniBedrooms - Verifica se o quarto identificado pelo seu codigo existe no dicionário de quartos.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Retorno: Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
int existeQuartoUniBedrooms(uniBedrooms u, char *codigo);

int daNQuartosUniBedrooms(uniBedrooms u);
/***********************************************
modificaEstadoQuartoUniBedrooms - Altera o estado do quarto identificado pelo seu codigo para o estado recebido como parametro.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Pre-condicoes: u != NULL && codigo != NULL && estado != NULL
***********************************************/
void modificaEstadoQuartoUniBedrooms(uniBedrooms u, char *codigo, char *estado);

/***********************************************
daNCandidaturasQuartoUniBedrooms - Retorna o numero de candidaturas que foram feitas ao quarto identificado pelo seu codigo.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Retorno: numero de candidaturas
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
int daNCandidaturasQuartoUniBedrooms(uniBedrooms u, char *codigo);

/***********************************************
daNCandidaturasQuartoUniBedrooms - Retorna a ocupacao do quarto identificado pelo seu codigo.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Retorno: ocupacao do quarto
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
char *daOcupacaoQuartoUniBedrooms(uniBedrooms u, char *codigo);

/***********************************************
daLoginGerenteQuartoUniBedrooms - Retorna o login do gerente do quarto identificado pelo seu codigo.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Retorno: login do gerente do quarto
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
char * daLoginGerenteQuartoUniBedrooms(uniBedrooms u, char *codigo);

/***********************************************
candidataQuartoEstudanteUniBedrooms - Submete uma candidatura de um estudante com o seu login a um quarto com o seu codigo. 
                                    (adiciona o estudante a seq do quarto e o codigo do quarto a seq do estudante)
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
    login - login do estudante
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL && codigo != NULL && login != NULL
***********************************************/
int candidataQuartoEstudanteUniBedrooms(uniBedrooms u, char *codigo, char *login);

/***********************************************
existeCandidaturaQuartoUniBedrooms - Verifica se o estudante identificado pelo seu login tem uma candidatura ao quarto identificado pelo codigo.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
Retorno: Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: u != NULL && codigo != NULL
***********************************************/
int existeCandidaturaQuartoUniBedrooms(uniBedrooms u, char *codigo, char * login);

/***********************************************
eliminaCandidaturasEstudanteUniBedrooms - Remove todas as candidaturas de um estudante.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
    login - login do estudante
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL && login != NULL
***********************************************/
int eliminaCandidaturasEstudanteUniBedrooms(uniBedrooms u, char * login);

/***********************************************
eliminaCandidaturasEstudanteUniBedrooms - Remove os codigos dos quartos a que um estudante se candidatou, na sua sequencia de candidaturas.
Parametros:
	u - uniBedrooms
    login - login do estudante
    q - quarto
Retorno: 1 - sucesso, 0 - sem sucesso
Pre-condicoes: u != NULL && q != NULL && login != NULL
***********************************************/
int eliminaCandidaturasQuartoUniBedrooms(uniBedrooms u, char * login, quarto q);

/***********************************************
eliminaCQuartoEstudantesUniBedrooms - Remove todas as candidaturas de um estudante nas sequencias dos quartos.
Parametros:
	u - uniBedrooms
    login - login do estudante
Pre-condicoes: u != NULL && login != NULL
***********************************************/
void eliminaCQuartoEstudantesUniBedrooms(uniBedrooms u, char * login);

/***********************************************
aceitaCandidaturaUniBedrooms - Completa todos os processos de uma candidatura bem sucedida.
Parametros:
	u - uniBedrooms
    codigo - codigo do quarto
    login - login do estudante
Pre-condicoes: u != NULL codigo != NULL && login != NULL
***********************************************/
void aceitaCandidaturaUniBedrooms(uniBedrooms u , char * codigo, char * login);

/***********************************************
daNumGerentesUniBedrooms - Retorna o número de gerentes no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
Retorno: Número de gerentes no sistema
Pre-condicoes: u != NULL
***********************************************/
int daNumGerentesUniBedrooms(uniBedrooms u);

/***********************************************
adicionaLocalidadeUniBedrooms - Adiciona uma nova localidade ao sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade a ser adicionada
Retorno: Ponteiro para a localidade adicionada
Pre-condicoes: u != NULL, localidades != NULL
***********************************************/
void * adicionaLocalidadeUniBedrooms(uniBedrooms u, char *localidades);

/***********************************************
adicionaQuartoLocalidadeUniBedrooms - Adiciona um novo quarto a uma localidade existente no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade onde o quarto será adicionado
codigo - Código do quarto a ser adicionado
Retorno: Nenhum
Pre-condicoes: u != NULL, localidades != NULL, codigo != NULL
***********************************************/
void adicionaQuartoLocalidadeUniBedrooms(uniBedrooms u, char * localidades, char * codigo);

/***********************************************
removeQuartoLocalidadeUniBedrooms - Remove um quarto de uma localidade existente no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade de onde o quarto será removido
codigo - Código do quarto a ser removido
Retorno: Nenhum
Pre-condicoes: u != NULL, localidades != NULL, codigo != NULL
***********************************************/
void removeQuartoLocalidadeUniBedrooms(uniBedrooms u, char * localidades, char * codigo);

/***********************************************
existeLocalidadeUniBedrooms - Verifica se uma localidade existe no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade a ser verificada
Retorno: 1 se a localidade existe, 0 caso contrário
Pre-condicoes: u != NULL, localidades != NULL
***********************************************/
int existeLocalidadeUniBedrooms(uniBedrooms u, char * localidades);

/***********************************************
daLocalidadeUniBedrooms - Retorna um ponteiro para a localidade no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade
Retorno: Ponteiro para a localidade, ou NULL se não encontrada
Pre-condicoes: u != NULL, localidades != NULL
***********************************************/
localidade daLocalidadeUniBedrooms(uniBedrooms u, char *localidades);

/***********************************************
listaLocalidadeUniBedrooms - Retorna um iterador para percorrer a lista de localidades no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
Retorno: Iterador para a lista de localidades
Pre-condicoes: u != NULL
***********************************************/
iterador listaLocalidadeUniBedrooms(uniBedrooms u);

/***********************************************
listaFinalUniBedrooms - Retorna um iterador para percorrer a lista de quartos no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
Retorno: Iterador para a lista de quartos
Pre-condicoes: u != NULL
***********************************************/
iterador listaFinalUniBedrooms(uniBedrooms u);

/***********************************************
criaLocalidadeUniBedrooms - Cria uma nova localidade no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade a ser criada
Retorno: 1 se a localidade foi criada com sucesso, 0 caso contrário
Pre-condicoes: u != NULL, localidades != NULL
***********************************************/
int criaLocalidadeUniBedrooms(uniBedrooms u, char *localidades);

/***********************************************
removeLocalidadeUniBedrooms - Remove uma localidade do sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
localidades - Nome da localidade a ser removida
Retorno: 1 se a localidade foi removida com sucesso, 0 caso contrário
Pre-condicoes: u != NULL, localidades != NULL
***********************************************/
int removeLocalidadeUniBedrooms(uniBedrooms u, char *localidades);

/***********************************************
verificaTOP3GerenteUniBedrooms - Verifica se um gerente está entre os TOP 3 gerentes do sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
login - Login do gerente a ser verificado
Retorno: Nenhum
Pre-condicoes: u != NULL, login != NULL
***********************************************/
void verificaTOP3GerenteUniBedrooms(uniBedrooms u, char * login);

/***********************************************
daNumTop3UniBedrooms - Retorna o número total de TOP 3 gerentes no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
Retorno: Número total de TOP 3 gerentes
Pre-condicoes: u != NULL
***********************************************/
int daNumTop3UniBedrooms(uniBedrooms u);

/***********************************************
retornaTop3UniBedrooms - Retorna o nome do gerente na posição especificada no TOP 3 gerentes do sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
pos - Posição do gerente no TOP 3 (começando em 1)
Retorno: Nome do gerente na posição especificada
Pre-condicoes: u != NULL, pos >= 1
***********************************************/
char * retornaTop3UniBedrooms(uniBedrooms u, int pos);

/***********************************************
verificaLoginGerenteQuartoUniBedrooms - Verifica se o login de um gerente está associado a um determinado quarto no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
codigo - Código do quarto a ser verificado
loginGerente - Login do gerente a ser verificado
Retorno: 1 se o login do gerente está associado ao quarto, 0 caso contrário
Pre-condicoes: u != NULL, codigo != NULL, loginGerente != NULL
***********************************************/
int verificaLoginGerenteQuartoUniBedrooms(uniBedrooms u, char * codigo, char *loginGerente);

/***********************************************
verificaUniGerenteUniBedrooms - Verifica se um gerente está associado a uma determinada universidade no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
loginGerente - Login do gerente a ser verificado
universidade - Nome da universidade a ser verificada
Retorno: 1 se o gerente está associado à universidade, 0 caso contrário
Pre-condicoes: u != NULL, loginGerente != NULL, universidade != NULL
***********************************************/
int verificaUniGerenteUniBedrooms(uniBedrooms u, char *loginGerente, char *universidade);

/***********************************************
verificaEstadoQuartoUniBedrooms - Verifica se um estado é válido para um quarto no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
novoEstado - Novo estado a ser verificado
Retorno: 1 se o estado é válido, 0 caso contrário
Pre-condicoes: u != NULL, novoEstado != NULL
***********************************************/
int verificaEstadoQuartoUniBedrooms(uniBedrooms u, char * novoEstado);

/***********************************************
listaCandidaturasQuartoUniBedrooms - Retorna um iterador com a lista de candidaturas associadas a um quarto no sistema UniBedrooms.
Parametros:
u - Sistema UniBedrooms
codigo - Código do quarto
Retorno: Iterador com a lista de candidaturas do quarto
Pre-condicoes: u != NULL, codigo != NULL
***********************************************/
iterador listaCandidaturasQuartoUniBedrooms(uniBedrooms u, char *codigo);

#endif