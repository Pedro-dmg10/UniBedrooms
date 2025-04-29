/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uniBedrooms.h"
#include "iterador.h"
#include "dicionario.h"
#include "chaves.h"
#include "tuplo.h"
#include "quicksort.h"

#define CAPE 20000
#define CAPQ 10000
#define CAPG 1000
#define CAPL 500
#define CAPCANE 10

struct _uniBedrooms{
    dicionario gerentes;
    dicionario estudantes;
    dicionario quartos;
    dicionario localidade;
    gerente topGerentes[3];
    int numTop3;
};

uniBedrooms criaUniBedrooms(){
    uniBedrooms u = (uniBedrooms)malloc(sizeof(struct _uniBedrooms));
    if(u == NULL) return NULL;
    u->gerentes = criaDicionario(CAPG, 1);
    if(u->gerentes == NULL){
        free(u);
        return NULL;
    }
    u->estudantes = criaDicionario(CAPE, 1);
    if(u->estudantes == NULL){
        destroiDicionario(u->gerentes);
        free(u);
        return NULL;
    }
    u->quartos = criaDicionario(CAPQ,1);
    if(u->quartos ==NULL){
        destroiDicionario(u->quartos);
        free(u);
        return NULL;
    }
    u->localidade = criaDicionario(CAPL,1); // -> localidade
    if(u->localidade == NULL){
        destroiDicionario(u->localidade);
        free(u);
        return NULL;
    }
    u->numTop3=0;
    return u;
}

void destroiUniBedrooms(uniBedrooms u){
    destroiDicEElems(u->gerentes, destroiGenGerente);
    destroiDicEElems(u->estudantes, destroiGenEstudante);
    destroiDicEElems(u->quartos, destroiGenQuarto);
    destroiDicEElems(u->localidade, destroiGenLocalidade); // -> localidade
    free(u);
}

int criaEstudanteUniBedrooms(uniBedrooms u, char *login, char *nome, char *uni, char *localidade, int idade) {
    estudante e = criaEstudante(login, nome, uni, localidade, idade);
    if(existeGerenteUniBedrooms(u,login)==1){
        return 0;
    }
    if (e == NULL) {
        return 0;
    }

    int ad = adicionaElemDicionario(u->estudantes, login, e);
    if (ad != 1) {
        destroiEstudante(e);
    }

    return ad;
}

int removeEstudanteUniBedrooms(uniBedrooms u, char *login){
    estudante e = removeElemDicionario(u->estudantes, login);
    if(e == NULL){
        return 0;
    }
    else{
        destroiEstudante(e);
        return 1;
    }
}

estudante daEstudanteUniBedrooms(uniBedrooms u, char *login){
    return (estudante)elementoDicionario(u->estudantes, login);
}

int numEstudantesUniBedrooms(uniBedrooms u){
    return tamanhoDicionario(u->estudantes);
}

int existeEstudanteUniBedrooms(uniBedrooms u, char *login){
    return existeElemDicionario(u->estudantes, login);
}

int daNCndidaturasEstudanteUniBedrooms(uniBedrooms u, char *login){
    estudante e = daEstudanteUniBedrooms(u,login);
    return daNCandidaturasEstudante(e);
}

int criaGerenteUniBedrooms(uniBedrooms u, char *login, char *nome, char *uni) {
    gerente g = criaGerente(login, nome, uni);
    if(existeEstudanteUniBedrooms(u,login)==1){
        return 0;
    }
    if (g == NULL) {
        return 0;
    }
    int ad = adicionaElemDicionario(u->gerentes, login, g);
    if (ad != 1) {
        destroiGerente(g);
    }
    verificaTOP3GerenteUniBedrooms(u,login);
    return ad;
}
gerente daGerenteUniBedrooms(uniBedrooms u, char *login){
    return (gerente)elementoDicionario(u->gerentes, login);
}

int daNumGerentesUniBedrooms(uniBedrooms u){
    return tamanhoDicionario(u->gerentes);
}

int existeGerenteUniBedrooms(uniBedrooms u, char *login){
    return existeElemDicionario(u->gerentes, login);
}

char * uniGerenteUniBedrooms(uniBedrooms u, char * login){
    gerente g = daGerenteUniBedrooms(u,login);
    if(g == NULL){
        return NULL;
    } 
    return daUniversidadeGerente(g);
}

int criaQuartoUniBedrooms(uniBedrooms u, char *codigo, char *loginG, char *nomeDaResidencia, char *universidade, char *localidade, int andar, char *descricao){
    quarto q = criaQuarto(codigo,loginG, nomeDaResidencia, universidade,localidade,andar,descricao);
    if (q == NULL) {
        return 0;
    }
    int ad = adicionaElemDicionario(u->quartos, codigo, q);
    if (ad != 1) {
        destroiQuarto(q);
    }

    return ad;
}

void  removeQuartoUniBedrooms(uniBedrooms u, char * codigo){
    quarto q = daQuartoUniBedrooms(u,codigo);
    removeElemDicionario(u->quartos,codigo);
    destroiQuarto(q);
}

quarto daQuartoUniBedrooms(uniBedrooms u, char *codigo){
    return (quarto)elementoDicionario(u->quartos, codigo);    
}

int existeQuartoUniBedrooms(uniBedrooms u, char *codigo){
    return existeElemDicionario(u->quartos, codigo);
}

int daNQuartosUniBedrooms(uniBedrooms u){
    return tamanhoDicionario(u->quartos);
}

void modificaEstadoQuartoUniBedrooms(uniBedrooms u, char *codigo, char *estado){
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        return;
    }
    alteraOcupacaoQuarto(q,estado);
}

int daNCandidaturasQuartoUniBedrooms(uniBedrooms u, char *codigo){
    quarto q = daQuartoUniBedrooms(u,codigo);
    return daNCandidaturasQuarto(q);
}

char *daOcupacaoQuartoUniBedrooms(uniBedrooms u, char *codigo){
    quarto q = daQuartoUniBedrooms(u,codigo);
    return daOcupacaoQuarto(q);
}

char * daLoginGerenteQuartoUniBedrooms(uniBedrooms u, char *codigo){
    quarto q = daQuartoUniBedrooms(u,codigo);
    return daLoginGerenteQuarto(q);
}


int candidataQuartoEstudanteUniBedrooms(uniBedrooms u, char *codigo, char *login){
    quarto q = daQuartoUniBedrooms(u,codigo);
    estudante e = daEstudanteUniBedrooms(u,login);
    if(candidataEstudanteQuarto(e,q)==0){ 
        return 0;
    }
    if(candidataQuartoEstudante(e,daCodQuarto(q))==0){
        return 0;
    }
    else{
        return 1;
    }
}

int existeCandidaturaQuartoUniBedrooms(uniBedrooms u, char *codigo, char * login){
    estudante e = daEstudanteUniBedrooms(u,login);
    if(e==NULL){
        return 0;
    }
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        return 0;
    }
    if(existeCandidaturaEstudanteQuarto(e,q)==0){
        return 0;
    }
    else{
        return 1;
    }
}

int eliminaCandidaturasEstudanteUniBedrooms(uniBedrooms u, char * login){
    estudante e = daEstudanteUniBedrooms(u,login);
    if(e==NULL){
        return 0;
    }
    removeSequenciaCandEstudante(e);
    return 1;
}

int eliminaCandidaturasQuartoUniBedrooms(uniBedrooms u, char * login, quarto q){
    estudante e = daEstudanteUniBedrooms(u,login);
    if(e==NULL){
        return 0;
    }
    removeSequenciaCandQuarto(e,q);
    return 1;
}

void eliminaCQuartoEstudantesUniBedrooms(uniBedrooms u, char * login){
    estudante e = daEstudanteUniBedrooms(u,login);
    if(e==NULL){
        return;
    }    
    iterador it = listaCandidaturasEstudante(e);
    while(temSeguinteIterador(it)){
        quarto q = daQuartoUniBedrooms(u,seguinteIterador(it));
        removeCandEstudanteQuarto(q, daLoginEstudante(e));
    }
    destroiIterador(it);
}

void aceitaCandidaturaUniBedrooms(uniBedrooms u , char * codigo, char * login){
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        return;
    }
    gerente g = daGerenteUniBedrooms(u, daLoginGerenteQuarto(q));
    if(g==NULL){
        return;
    }
    alteraOcupacaoQuarto(q, "ocupado");
    eliminaCQuartoEstudantesUniBedrooms(u, login); //apaga as candidaturas do estudante nos outros quartos (seq outros quartos)
    removeCandEstudantesQuarto(q); //apaga as candidaturas de outros estudantes a este quarto (seq outros estudantes)
    eliminaCandidaturasEstudanteUniBedrooms(u, login); //eliminia a sequencia de candidaturas do estudante (seq estudante)
    eliminaCandidaturasQuartoUniBedrooms(u, login, q); //eliminia a sequencia de candidaturas do quarto (seq quarto)
    addQAlugadosGerente(g);
    verificaTOP3GerenteUniBedrooms(u, daLoginGerenteQuarto(q));
}

int verificaLoginGerenteQuartoUniBedrooms(uniBedrooms u, char * codigo, char *loginGerente){
    return strcmp(daLoginGerenteQuartoUniBedrooms(u,codigo),loginGerente);
}

int verificaUniGerenteUniBedrooms(uniBedrooms u, char *loginGerente, char *universidade){
    return strcmp(uniGerenteUniBedrooms(u,loginGerente),universidade);
}

int verificaEstadoQuartoUniBedrooms(uniBedrooms u, char * novoEstado){
    return strcmp(novoEstado,"ocupado");
}

iterador listaCandidaturasQuartoUniBedrooms(uniBedrooms u, char *codigo){
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        return NULL;
    }
    else{
        return listaCandidaturasQuarto(q);
    }
}

int criaLocalidadeUniBedrooms(uniBedrooms u, char *localidades) {
    localidade l = criaLocalidade(localidades);
    
    if (l == NULL) {
        return 0;
    }

    int ad = adicionaElemDicionario(u->localidade, localidades, l);
    if (ad != 1) {
        destroiLocalidade(l);
    }

    return ad;
}

void * adicionaLocalidadeUniBedrooms(uniBedrooms u, char *localidades){
    localidade l;
    if(existeLocalidadeUniBedrooms(u,localidades)==0){
        localidade l = criaLocalidade(localidades);
        adicionaElemDicionario(u->localidade,localidades,l);
    }
    else{
      l = daLocalidadeUniBedrooms(u,localidades);
    }
    return l;
}

int removeLocalidadeUniBedrooms(uniBedrooms u, char *localidades){
    localidade l = removeElemDicionario(u->localidade, localidades);
    if(l == NULL){
        return 0;
    }
    else{
        destroiLocalidade(l);
        return 1;
    }
}

int existeLocalidadeUniBedrooms(uniBedrooms u, char * localidades){
    return existeElemDicionario(u->localidade,localidades);
}

void adicionaQuartoLocalidadeUniBedrooms(uniBedrooms u, char * localidades, char * codigo){
    localidade l = daLocalidadeUniBedrooms(u,localidades);
    if(l==NULL){
        return;
    }
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        return;
    }
    adicionaQuartoLocalidade(l,q);
}

void removeQuartoLocalidadeUniBedrooms(uniBedrooms u, char * localidades, char * codigo){
    localidade l = daLocalidadeUniBedrooms(u,localidades);
    if(l==NULL){
        return;
    }
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        return;
    }
    removeQuartoLocalidade(l,q);
}


localidade daLocalidadeUniBedrooms(uniBedrooms u, char *localidades){
    return (localidade)elementoDicionario(u->localidade, localidades);    
}


iterador listaFinalUniBedrooms(uniBedrooms u){
    int i = 0;
    int nQuartos = daNQuartosUniBedrooms(u);
    void ** vetorAux = (void**)malloc(sizeof(void*) * nQuartos);
    iterador it = listaLocalidadeUniBedrooms(u); 
        while(temSeguinteIterador(it)){
            localidade l = (localidade)seguinteIterador(it);
            iterador it2 = listaQuartoLocalidade(l);
            while(temSeguinteIterador(it2)){                    //lista quartos
                quarto q = (quarto)seguinteIterador(it2);
                vetorAux[i] = q;
                i++;
            }
            destroiIterador(it2);
        }
    destroiIterador(it);
    iterador itF= criaIterador(vetorAux,nQuartos);
    return itF;
}

iterador listaLocalidadeUniBedrooms(uniBedrooms u){ 
    iterador it = iteradorDicionario(u->localidade);
    void ** localidade = (void **)malloc(sizeof(void*) *tamanhoDicionario(u->localidade));
    int i=0;
    while(temSeguinteIterador(it)){
        localidade[i]=seguinteIterador(it);
        i++;
    }
    quickSort(localidade,0,tamanhoDicionario(u->localidade)-1, daGenLocalidade,comparaGenLocalidade);

    destroiIterador(it);
    
    it = criaIterador(localidade,tamanhoDicionario(u->localidade));
    
    return it;
}

int daNumTop3UniBedrooms(uniBedrooms u){
    return u->numTop3;
}


void verificaTOP3GerenteUniBedrooms(uniBedrooms u, char *login) {
    gerente g = daGerenteUniBedrooms(u, login);
    if (g == NULL) {
        return;
    }

    if (u->numTop3 == 0) {  // Se o top3 ainda estiver vazio
        u->topGerentes[0] = g;
        u->numTop3++;
        return;
    } else if (u->numTop3 == 1) {    // Se só estiver um gerente no top3
        if (g != u->topGerentes[0]) {      // Se se adiciona um novo gerente ao top3
            if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[0])) {
                u->topGerentes[1] = u->topGerentes[0];
                u->topGerentes[0] = g;
            } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[0])) {
                if (strcmp(daLoginGerente(u->topGerentes[0]), daLoginGerente(g)) < 0) {    
                    u->topGerentes[1] = g;
                } else {
                    u->topGerentes[1] = u->topGerentes[0];
                    u->topGerentes[0] = g;
                }
            }
            u->numTop3++;
        }
        return;
    } else if (u->numTop3 == 2) {    // Se já estiverem 2 gerentes no top3
        if (g != u->topGerentes[0] && g != u->topGerentes[1]) {   // Se se adiciona um novo gerente ao top3
            if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[1])) {
                u->topGerentes[2] = u->topGerentes[1];
                u->topGerentes[1] = g;
            } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[1])) {
                if (strcmp(daLoginGerente(u->topGerentes[1]), daLoginGerente(g)) < 0) {    //Se o gerente que estava em segundo é Alfredo e o novo é Bernardo
                    u->topGerentes[2] = g;
                } else {
                    u->topGerentes[2] = u->topGerentes[1];
                    u->topGerentes[1] = g;
                    if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[0])) {
                        u->topGerentes[1] = u->topGerentes[0];
                        u->topGerentes[0] = g;
                    } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[0])) {
                        if (strcmp(daLoginGerente(g), daLoginGerente(u->topGerentes[0])) < 0) {   //Se o novo gerente é Alfredo e o que estava em primeiro é Bernardo
                            u->topGerentes[1] = u->topGerentes[0];
                            u->topGerentes[0] = g;
                        }
                    }
                }
            }
            u->numTop3++;
        } else if (g == u->topGerentes[1]) {
            if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[0])) {
                u->topGerentes[1] = u->topGerentes[0];
                u->topGerentes[0] = g;
            } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[0])) {
                if (strcmp(daLoginGerente(u->topGerentes[0]), daLoginGerente(g)) > 0) {   //Se o gerente que estava em primeiro é Alfredo e o novo é Bernardo
                    u->topGerentes[1] = g;
                } else {
                    u->topGerentes[1] = u->topGerentes[0];
                    u->topGerentes[0] = g;
                }
            }
        }
    } else {    // Se as 3 posições do top3 estiverem todas ocupadas
        if (g != u->topGerentes[0] && g != u->topGerentes[1] && g != u->topGerentes[2]) {   // Se se adiciona um gerente ao top3
            if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[2])){
                u->topGerentes[2]=g;
            }
            else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[2])) {
                if (strcmp(daLoginGerente(g), daLoginGerente(u->topGerentes[2])) < 0) {    //Se o novo gerente é Alfredo e o que está em 3º é Bernardo
                    u->topGerentes[2] = g;
                    if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[1])) {
                        if (strcmp(daLoginGerente(g), daLoginGerente(u->topGerentes[1])) < 0) {    //Se o novo gerente é Alfredo e o que está em 2º é Bernardo
                            u->topGerentes[2] = u->topGerentes[1];
                            u->topGerentes[1] = g;
                            if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[0])) {
                                if (strcmp(daLoginGerente(g), daLoginGerente(u->topGerentes[0])) > 0) {     //Se o novo gerente é Alfredo e o que está em 1º é Bernardo
                                    u->topGerentes[1] = u->topGerentes[0];
                                    u->topGerentes[0] = g;
                                }
                            }
                        }
                    }
                }
            }
        } else if (g == u->topGerentes[2]) {
            if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[1])) {
                u->topGerentes[2] = u->topGerentes[1];
                u->topGerentes[1] = g;
            } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[1])) {
                if (strcmp(daLoginGerente(u->topGerentes[1]), daLoginGerente(g)) < 0) {      //Se o que estava em 2º é Alfredo e o novo é Bernardo
                    u->topGerentes[2] = g;
                } else {
                    u->topGerentes[2] = u->topGerentes[1];
                    u->topGerentes[1] = g;
                    if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[0])) {
                        u->topGerentes[1] = u->topGerentes[0];
                        u->topGerentes[0] = g;
                    } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[0])) {
                        if (strcmp(daLoginGerente(g), daLoginGerente(u->topGerentes[0])) < 0) {    //Se o novo é Alfredo e o que estava em 1º é Bernardo
                            u->topGerentes[1] = u->topGerentes[0];
                            u->topGerentes[0] = g;
                        }
                    }
                }
            }
        } else if (g == u->topGerentes[1]) {
            if (daNQAlugadosGerente(g) > daNQAlugadosGerente(u->topGerentes[0])) {
                u->topGerentes[1] = u->topGerentes[0];
                u->topGerentes[0] = g;
            } else if (daNQAlugadosGerente(g) == daNQAlugadosGerente(u->topGerentes[0])) {
                if (strcmp(daLoginGerente(u->topGerentes[0]), daLoginGerente(g)) < 0) {       //Se o que estava em primeiro é Alfredo e o novo é Bernardo
                    u->topGerentes[1] = g;
                } else {
                    u->topGerentes[1] = u->topGerentes[0];
                    u->topGerentes[0] = g;
                }
            }
        }
    }
    return;
}



char * retornaTop3UniBedrooms(uniBedrooms u, int pos){
    return daLoginGerente(u->topGerentes[pos]);
}


