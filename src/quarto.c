/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include <stdlib.h>
#include <string.h>
#include "sequencia.h"
#include "iterador.h"
#include "estudante.h"
#include "quarto.h"

#define CAPCANQ 20000  //nº máx de candidaturas a um quarto
#define LIMDES 200

struct _quarto{
    char * codQuarto;
    char * nomeResidencia;
    char * localidade;
    char * uni;
    char * descricao;
    char * loginG;
    char * ocupacao;
    int andar;
    sequencia candidaturasQ;   // sequencia com os logins dos estudantes candidatos a um quarto
};

quarto criaQuarto(char * codQuarto,char * loginG, char * nomeResidencia, char * uni, char * localidade, int andar, char * descricao){
    quarto q = (quarto)malloc(sizeof(struct _quarto));
    if(q == NULL)
        return NULL;
    
    q->candidaturasQ = criaSequencia(CAPCANQ);
    
    q->codQuarto = (char *)malloc(sizeof(char) * (strlen(codQuarto) + 1));
    if(q->codQuarto == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->codQuarto, codQuarto);

    q->loginG = (char *)malloc(sizeof(char) * (strlen(loginG) + 1));
    if(q->loginG == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->loginG, loginG);

    q->nomeResidencia = (char *)malloc(sizeof(char) * (strlen(nomeResidencia) + 1));
    if(q->nomeResidencia == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->nomeResidencia, nomeResidencia);

    q->uni = (char *)malloc(sizeof(char) * (strlen(uni) + 1));
    if(q->uni == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->uni, uni);

    q->localidade = (char *)malloc(sizeof(char) * (strlen(localidade) + 1));
    if(q->localidade == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->localidade, localidade);

    q->descricao = (char *)malloc(sizeof(char) * (strlen(descricao) + 1));
    if(q->descricao == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->descricao, descricao);
    q->ocupacao = (char *)malloc(sizeof(char) * (strlen("ocupado") + 1));
    if(q->ocupacao == NULL){
        destroiQuarto(q);
        return NULL;
    }
    strcpy(q->ocupacao,"livre");

    q->andar = andar;
    
    return q;
}

void destroiQuarto(quarto q){
    destroiSequencia(q->candidaturasQ);
    free(q->codQuarto);
    free(q->nomeResidencia);
    free(q->loginG);
    free(q->uni);
    free(q->localidade);
    free(q->descricao);
    free(q);
}

void destroiGenQuarto(void * q){
    destroiQuarto((quarto)q);
}

char * daCodQuarto(quarto q){
    return q->codQuarto;
}

char * daNomeResidenciaQuarto(quarto q){
    return q->nomeResidencia;
}

char * daLocalidadeQuarto(quarto q){
    return q->localidade;
}

char * daUniQuarto(quarto q){
    return q->uni;
}

char * daDescricaoQuarto(quarto q){
    return q->descricao;
}

int daAndarQuarto(quarto q){
    return q->andar;
}    

char * daLoginGerenteQuarto(quarto q){
    return q->loginG;
}

char *daOcupacaoQuarto(quarto q){
    return q->ocupacao;
}

int daNCandidaturasQuarto(quarto q){
    return tamanhoSequencia(q->candidaturasQ);
}

void alteraOcupacaoQuarto(quarto q, char *estado){
    strcpy(q->ocupacao,estado);
}

int candidataEstudanteQuarto(estudante e, quarto q) {
    int sucesso = 1;
    for (int i = 1; i <= tamanhoSequencia(q->candidaturasQ); i++) {
        if (strcmp(daLoginEstudante(elementoPosSequencia(q->candidaturasQ, i)), daLoginEstudante(e)) == 0) {
            sucesso = 0;
            break;
        }
    }
    if(sucesso==1){
        adicionaPosSequencia(q->candidaturasQ, e, tamanhoSequencia(q->candidaturasQ) + 1);
    }
    return sucesso;
}

iterador listaCandidaturasQuarto(quarto q){
    return iteradorSequencia(q->candidaturasQ);
}

int existeCandidaturaEstudanteQuarto(estudante e, quarto q){
    int sucesso = 0;
    for (int i = 0; i < tamanhoSequencia(q->candidaturasQ); i++) {
        if (strcmp(daLoginEstudante(elementoPosSequencia(q->candidaturasQ, i)), daLoginEstudante(e)) == 0) {
            sucesso = 1;
            break;
        }
    }
    return sucesso;
}

void removeSequenciaCandQuarto(estudante e, quarto q){  
    destroiSequencia(q->candidaturasQ);
    q->candidaturasQ = criaSequencia(CAPCANQ);
}

void removeCandEstudantesQuarto(quarto q){
    iterador it = listaCandidaturasQuarto(q);
    while(temSeguinteIterador(it)){
        estudante e = (estudante)seguinteIterador(it);
        removeCandQuartoEstudante(e, daCodQuarto(q));
    }
    destroiIterador(it);
}

void removeCandEstudanteQuarto(quarto q, char * login){ 
    if(q==NULL){
        return;
    }
    for(int i = 1; i<=tamanhoSequencia(q->candidaturasQ);i++){
        if(strcmp(login,daLoginEstudante(elementoPosSequencia(q->candidaturasQ,i)))==0){
            removePosSequencia(q->candidaturasQ,i);
            break;
        }
    }
}

void * daCodigoGenQuarto(void * q){
    return (void *)daCodQuarto((quarto)q);
}   

int comparaGenQuarto(void * cod1, void * cod2){
    return strcmp(cod1,cod2);
}