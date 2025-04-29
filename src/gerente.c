/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include <stdlib.h>
#include <string.h>
#include "gerente.h"
#include "dicionario.h"
#include "quarto.h"
#include "iterador.h"
#include <stdio.h>

#define CAPQ 20

struct _gerente{
    char *login;
    char *nome;
    char *uni;
    int quartosAlugados;
};

gerente criaGerente(char *login, char*nome, char *uni){
    gerente g = (gerente)malloc(sizeof(struct _gerente));
    if(g==NULL)return NULL;
    g->login=(char *)malloc(sizeof(char) * (strlen(login)+1));
    if(g->login==NULL){
        free(g);
        return NULL;
    }
    strcpy(g->login,login);
    g->nome=(char *)malloc(sizeof(char) * (strlen(nome)+1));
    if(g->nome==NULL){
        free(g);
        return NULL;
    }
    strcpy(g->nome,nome);
    g->uni=(char *)malloc(sizeof(char) * (strlen(uni)+1));
    if(g->uni==NULL){
        free(g);
        return NULL;
    }
    strcpy(g->uni,uni);

    g->quartosAlugados=0;
    return g;
}
void destroiGerente(gerente g){
    free(g->login);
    free(g->nome);    
    free(g->uni);
    free(g);
}
void destroiGenGerente(void * g){
    destroiGerente((gerente) g);
}
char * daLoginGerente(gerente g){
    return g->login;
}

int daNQAlugadosGerente(gerente g){
    return g->quartosAlugados;
}

void  addQAlugadosGerente(gerente g){
    g->quartosAlugados++;
}
void subQAlugadosGerente(gerente g){
    g->quartosAlugados--;
}

char * daNomeGerente(gerente g){
    return g->nome;
}
char * daUniversidadeGerente(gerente g){
    return g->uni;
}
