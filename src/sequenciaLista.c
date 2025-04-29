/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
/*
 * sequenciaLista.c
 */

#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"
#include "noSimples.h"

/* Estrutura de dados: sequencia implementada em lista ligada simples */
struct  _sequencia{
         noSimples cabeca;
         noSimples cauda; 	//mais conveniente em lista ligada dupla
         int nroElem; 	 // conveniência
};

/* Prototipos das funcoes associadas a uma sequencia */

sequencia criaSequencia(int cap){
	sequencia s = (sequencia) malloc(sizeof(struct _sequencia));
	if ( s == NULL) return NULL;
	s->cabeca = NULL;
	s->cauda = NULL;
	s->nroElem = 0;
	return s;
}

void destroiSequencia (sequencia s ){
	noSimples  aux = s->cabeca;
	while (aux != NULL){
		s->cabeca = segNoSimples(aux);
		destroiNoSimples(aux);
		aux = s->cabeca;
	}
	free(s);
}

void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	noSimples  aux = s->cabeca;
	while (aux != NULL){
		s->cabeca = segNoSimples(aux);
		destroiElemENoSimples(aux,destroi);
		aux = s->cabeca;
	}
	free(s);
}

int vaziaSequencia(sequencia s){
	if (s->nroElem == 0)
		return 1;
	return 0;
}


int tamanhoSequencia(sequencia s){
	return s->nroElem;
}

void * elementoPosSequencia(sequencia s, int i){
	int j = 1;
	noSimples aux = s->cabeca;
	if (i == s->nroElem)
		return elemNoSimples(s->cauda);
	for(; j < i;j++)
		aux = segNoSimples(aux);
	return elemNoSimples(aux);
}

void adCabeca(sequencia s, void * e){
	noSimples aux = criaNoSimples(e,s->cabeca);
	s->cabeca = aux;
	if (s->nroElem == 0) // a sequencia estava vazia
		s->cauda = aux;
	s->nroElem++;
}
/* pre-condicao : lista nao e vazia */
void adCauda(sequencia s, void * e){
	noSimples aux = criaNoSimples(e,NULL);
	atribuiSegNoSimples(s->cauda,aux);
	s->cauda = aux;
	s->nroElem++;
}

void adMeio (sequencia s, void * e, int i){
	
	noSimples antes = s->cabeca;
	for(int j=1;j<i-1;j++){
		antes = segNoSimples(antes);
	}
	noSimples depois = segNoSimples(antes);
	
	noSimples novo = criaNoSimples(e,depois);

	s->nroElem++;
	atribuiSegNoSimples(antes,novo);// fazer
}

void adicionaPosSequencia(sequencia s, void * elem, int i){
	if (i == 1)
		adCabeca(s, elem);
	else
		if (i == s->nroElem + 1)
			adCauda(s,elem);
		else
			adMeio(s,elem,i);
}

void * rmCabeca(sequencia s){
	noSimples aux = s->cabeca;
	void * elem;
	s->cabeca = segNoSimples(aux);
	if (s->nroElem == 1) // sequencia com 1 elemento
		s->cauda = NULL;
	s->nroElem--;
	elem = elemNoSimples(aux);
	destroiNoSimples (aux);
	return elem;
}
/* pre-condicao: i != 1 */
void * rmPos(sequencia s, int i){

	noSimples antes = s->cabeca;
	for(int j=1;j<i-1;j++){
		antes = segNoSimples(antes);
	}

	//for de a obcado
	noSimples aremover = segNoSimples(antes);

	noSimples depois= segNoSimples(aremover);

	atribuiSegNoSimples(antes,depois);

	void *elem = elemNoSimples(aremover);

	destroiNoSimples(aremover);


	if(i == s->nroElem){
		s->cauda = antes;
	}//to do, atualizar cauda;
	
	s->nroElem--;
	return elem;
}

void * removePosSequencia(sequencia s, int i){
	if (i == 1)
		return rmCabeca(s);
	return rmPos(s,i);
}

iterador iteradorSequencia(sequencia s){
	void **aux;
	noSimples auxiliar = s->cabeca;
	int j =0;
	aux = (void **) malloc(s->nroElem * sizeof(void *));
	if(aux==NULL) return NULL;

	while(auxiliar != NULL){
        aux[j] = elemNoSimples(auxiliar);
		auxiliar = segNoSimples(auxiliar);
		j++;
    }
	return criaIterador(aux, s->nroElem);
	//CUIDADO: DEVE DAR AO ITERADOR UM VECTOR COM OS ELEMENTOS DA LISTA A PERCORRER
	//Fazer
	}




