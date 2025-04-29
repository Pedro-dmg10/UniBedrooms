/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include <stdlib.h>
#include <string.h>
#include "localidade.h"
#include "iterador.h"
#include "chaves.h"
#include "tuplo.h"
#include "quicksort.h"

#define CAPQ 10000

struct _localidade{
    char * localidades;
    dicionario quartos;
};

localidade criaLocalidade(char * localidades){
    localidade l = (localidade)malloc(sizeof(struct _localidade));
    if(l == NULL){
        return NULL;
    }
    l->quartos = criaDicionario(CAPQ,1);
    if(l->quartos == NULL){
        destroiDicionario(l->quartos);
        free(l);
        return NULL;
    }
    l->localidades = (char *)malloc(sizeof(char) * (strlen(localidades) + 1));
    if(l->localidades == NULL){
        destroiLocalidade(l);
        return NULL;
    }
    strcpy(l->localidades, localidades);

    return l;
}

void destroiLocalidade(localidade l){
    destroiDicionario(l->quartos);
    free(l->localidades);
    free(l);
}

void destroiGenLocalidade(void *l){
    destroiLocalidade((localidade)l);
}

int daNQuartosLocalidade(localidade l){
    return tamanhoDicionario(l->quartos);
}

char * daLLocalidade(localidade l){
    return l->localidades;
}

void * daGenLocalidade(void * l){
    return (void *)daLLocalidade((localidade)l);
}

void adicionaQuartoLocalidade(localidade l, quarto q){
    adicionaElemDicionario(l->quartos,daCodQuarto(q),q);
}

void removeQuartoLocalidade(localidade l,quarto q){
    removeElemDicionario(l->quartos,daCodQuarto(q));
}

int comparaGenLocalidade(void * loc1, void * loc2){
    return strcmp(loc1,loc2);
}

iterador listaQuartoLocalidade(localidade l){ 
    iterador it = iteradorDicionario(l->quartos);
    void ** quartos = (void **)malloc(sizeof(void*) *tamanhoDicionario(l->quartos));
    int i=0;
    while(temSeguinteIterador(it)){
        quartos[i]=seguinteIterador(it);
        i++;
    }
    quickSort(quartos,0,tamanhoDicionario(l->quartos)-1, daCodigoGenQuarto,comparaGenQuarto);
    destroiIterador(it);
    
    it = criaIterador(quartos,tamanhoDicionario(l->quartos));
    return it;
}




