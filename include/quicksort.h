/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#ifndef _H_QUICKSORT
#define _H_QUICKSORT
/***********************************************
troca - Troca os valores enter as variaveis.
Parametros:
	a - variavel1
    b - variavel2
Retorno: a e b com os valores trocados
Pre-condicoes: a & b != NULL 
***********************************************/
void troca(void **a, void **b) ;

/***********************************************
quickSort - Ordena um vetor utilizando o algoritmo QuickSort.
Parametros:
v - Vetor a ser ordenado
esq - Índice do elemento mais à esquerda do vetor a ser considerado
dir - Índice do elemento mais à direita do vetor a ser considerado
daChave - Função que retorna a chave do elemento no vetor
compChaves - Função que compara duas chaves e retorna um valor inteiro indicando a relação de ordem entre elas
Retorno: Vetor v ordenado em ordem crescente com base na função de comparação especificada
Pre-condicoes: v != NULL, esq >= 0, dir >= 0, daChave != NULL, compChaves != NULL
***********************************************/
void quickSort(void *v[], int esq, int dir,
               void *(*daChave)(void *),
               int (*compChaves)(void *, void *));
#endif