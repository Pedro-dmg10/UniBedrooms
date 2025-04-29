/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
/*
 * dicionario.h
 */
#include <stdlib.h>
#include "tuplo.h"
#include "iterador.h"
#include "dicionario.h"
#include "chaves.h"
#include "noSimples.h"

struct _dicionario {
    noSimples* elems;
    int numElems;
    int capacidade;
    int tamanho;
    int tipoCh;
};

int ePrimo(int n) {
    int primo = 1;
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primo = 0;
        }
    }
    return primo;
}

int primo(int n) {
    while (!ePrimo(n)) {
        n++;
    }
    return n;
}

dicionario criaDicionario(int cap, int tipoChave) {
    dicionario d;
    int i;
    d = (dicionario) malloc(sizeof(struct _dicionario));
    if (d == NULL) {
        return NULL;
    }
    d->tamanho = primo(2 * cap);
    d->elems = (noSimples*) malloc(sizeof(noSimples) * d->tamanho);
    if (d->elems == NULL) {
        free(d);
        return NULL;
    }
    for (i = 0; i < d->tamanho; i++) {
        d->elems[i] = NULL;
    }
    d->numElems = 0;
    d->capacidade = cap;
    d->tipoCh = tipoChave;
    return d;
}

void destroiDicionario(dicionario d) {
    int i = 0;
    noSimples aux;
    tuplo t;
    for (; i < d->tamanho; i++) {
        aux = d->elems[i];
        while (aux != NULL) {
            d->elems[i] = segNoSimples(aux);
            t = (tuplo) elemNoSimples(aux);
            destroiNoSimples(aux);
            destroiTuplo(t);
            aux = d->elems[i];
        }
    }
    free(d);
}

void destroiDicEElems(dicionario d, void (*destroi)(void*)) {
    int i = 0;
    noSimples aux;
    tuplo t;
    for (; i < d->tamanho; i++) {
        aux = d->elems[i];
        while (aux != NULL) {
            d->elems[i] = segNoSimples(aux);
            t = elemNoSimples(aux);
            destroi(segTuplo(t));
            destroiNoSimples(aux);
            destroiTuplo(t);
            aux = d->elems[i];
        }
    }
    free(d);
}

int vazioDicionario(dicionario d) {
    return (d->numElems == 0) ? 1 : 0;
}

int tamanhoDicionario(dicionario d) {
    return d->numElems;
}

int existeElemDicionario(dicionario d, void* ch) {
    return (elementoDicionario(d, ch) != NULL) ? 1 : 0;
}

void* elementoDicionario(dicionario d, void* ch) {
    tuplo t;
    noSimples auxNo;
    int pos = dispersao(ch, d->tamanho, d->tipoCh);
    auxNo = d->elems[pos];
    while (auxNo != NULL) {
        t = elemNoSimples(auxNo);
        if (igualChaves(priTuplo(t), ch, d->tipoCh) == 1) {
            return segTuplo(t);
        }
        auxNo = segNoSimples(auxNo);
    }
    return NULL;
}

int adicionaElemDicionario(dicionario d, void* ch, void* elem) {
    int pos;
    noSimples auxNo;

    if (existeElemDicionario(d, ch) == 1) {
        return 0;
    }

	tuplo auxT = criaTuplo(d->tipoCh,ch,elem);
    pos = dispersao(ch, d->tamanho, d->tipoCh);
    auxNo = d->elems[pos];

    if (auxNo == NULL) {

        d->elems[pos] = criaNoSimples(auxT, NULL);

    }
    if (auxNo != NULL) {

        noSimples no = criaNoSimples(auxT, auxNo);
        d->elems[pos] = no;
        
    }
    d->numElems++;
    return 1;
}


void* removeElemDicionario(dicionario d, void* ch) {
    tuplo tuplo;
    void* elem;
    void* auxCh;
    noSimples auxNo, antNo = NULL;
    int pos = dispersao(ch, d->tamanho, d->tipoCh);
    auxNo = d->elems[pos];
    if (auxNo == NULL) {
        return 0;
    }
    while (auxNo != NULL) {
        tuplo = elemNoSimples(auxNo);
        auxCh = priTuplo(tuplo);
        if (igualChaves(auxCh, ch, d->tipoCh) == 1) {
            elem = segTuplo(tuplo);
            if (antNo == NULL) {
                d->elems[pos] = segNoSimples(auxNo);
            } else {
                atribuiSegNoSimples(antNo, segNoSimples(auxNo));
            }
            destroiTuplo(tuplo);
            destroiNoSimples(auxNo);
            d->numElems--;
            return elem;
        }
        antNo = auxNo;
        auxNo = segNoSimples(auxNo);
    }
    return NULL;
}

iterador iteradorDicionario(dicionario d) {
    void** auxV = malloc(sizeof(void*) * d->numElems);
    noSimples no;
    tuplo tuplo;
    int contador = 0;
    int i;

    for (i = 0; i < d->tamanho; i++) { 

        no = d->elems[i];   
        if (no != NULL) {   

            while (no != NULL) {  
                tuplo = elemNoSimples(no);
                auxV[contador] = segTuplo(tuplo);
                contador++;
                no = segNoSimples(no);
            }    

        } 

    } 

    return criaIterador(auxV, contador);
}


iterador iteradorChaveDicionario(dicionario d) {
    void** auxV = malloc(sizeof(void*) * d->numElems);
    noSimples no;
    tuplo tuplo;
    int contador = 0;
    int i;

    for (i = 0; i < d->tamanho; i++) {
        no = d->elems[i];
        if (no != NULL) {
            while (no != NULL) {
                tuplo = elemNoSimples(no);
                auxV[contador] = priTuplo(tuplo);
                contador++;
                no = segNoSimples(no);
            }
        }
    }

    return criaIterador(auxV, contador);
}

