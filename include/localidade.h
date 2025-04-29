/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#ifndef _H_LOCALIDADE
#define _H_lOCALIDADE
#include "quarto.h"
#include "estudante.h"
#include "iterador.h"
#include "dicionario.h"

/* Tipo de dados: quarto */
typedef struct _localidade * localidade;


/***********************************************
criaLocalidade - Cria uma nova instância de localidade com base em um nome de localidades.
Parametros:
localidades - String contendo o nome das localidades
Retorno: Nova instância de localidade
Pre-condicoes: localidades != NULL

***********************************************/
localidade criaLocalidade(char * localidades);

/***********************************************
destroiLocalidade - Libera a memória alocada para uma instância de localidade.
Parametros:
l - Instância de localidade a ser destruída
Retorno: Nenhum
Pre-condicoes: l != NULL

***********************************************/
void destroiLocalidade(localidade l);

/***********************************************
destroiGenLocalidade - Libera a memória alocada para uma instância genérica de localidade.
Parametros:
l - Instância genérica de localidade a ser destruída
Retorno: Nenhum
Pre-condicoes: l != NULL

***********************************************/
void destroiGenLocalidade(void * l);

/***********************************************
daLLocalidade - Retorna o nome das localidades de uma instância de localidade.
Parametros:
l - Instância de localidade
Retorno: String contendo o nome das localidades
Pre-condicoes: l != NULL

***********************************************/
char * daLLocalidade(localidade l);

/***********************************************
daNQuartosLocalidade - Retorna o número de quartos em uma instância de localidade.
Parametros:
l - Instância de localidade
Retorno: Número de quartos
Pre-condicoes: l != NULL

***********************************************/
int daNQuartosLocalidade(localidade l);

/***********************************************
listaQuartoLocalidade - Retorna um iterador para percorrer os quartos de uma instância de localidade.
Parametros:
l - Instância de localidade
Retorno: Iterador para percorrer os quartos
Pre-condicoes: l != NULL

***********************************************/
iterador listaQuartoLocalidade(localidade l);

/***********************************************
daGenLocalidade - Retorna uma instância genérica de localidade.
Parametros:
l - Instância de localidade
Retorno: Instância genérica de localidade
Pre-condicoes: l != NULL

***********************************************/
void * daGenLocalidade(void * l);

/***********************************************
adicionaQuartoLocalidade - Adiciona um quarto a uma instância de localidade.
Parametros:
l - Instância de localidade
q - Quarto a ser adicionado
Retorno: Nenhum
Pre-condicoes: l != NULL, q != NULL

***********************************************/
void adicionaQuartoLocalidade(localidade l, quarto q);

/***********************************************
removeQuartoLocalidade - Remove um quarto de uma instância de localidade.
Parametros:
l - Instância de localidade
q - Quarto a ser removido
Retorno: Nenhum
Pre-condicoes: l != NULL, q != NULL

***********************************************/
void removeQuartoLocalidade(localidade l,quarto q);

/***********************************************
comparaGenLocalidade - Compara duas instâncias genéricas de localidade.
Parametros:
loc1 - Primeira instância genérica de localidade
loc2 - Segunda instância genérica de localidade
Retorno: Valor inteiro indicando a relação de ordem entre as instâncias (negativo se loc1 < loc2, zero se loc1 = loc2, positivo se loc1 > loc2)
Pre-condicoes: loc1 != NULL, loc2 != NULL

***********************************************/
int comparaGenLocalidade(void * loc1, void * loc2);

#endif