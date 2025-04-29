/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include <stdlib.h>
#include <string.h>
#include "sequencia.h"
#include "iterador.h"
#include "estudante.h"


#define CAPCANE 10   ////nº máx de candidaturas de um estudante

// TAD Estudante

struct _estudante {
    char* login;
    char* nome;
    char* uni;
    char* localidade;
    int idade;
    sequencia candidaturasE;    //sequencia com códigos do quarto a que o estudante se candidatou
};

estudante criaEstudante(char* login, char* nome, char* uni, char* localidade, int idade) {
    estudante e = (estudante)malloc(sizeof(struct _estudante));
    if (e == NULL) return NULL;
    e->candidaturasE = criaSequencia(CAPCANE);
    e->login = (char*)malloc(sizeof(char) * (strlen(login) + 1));
    if (e->login == NULL) {
        free(e);
        return NULL;
    }
    strcpy(e->login, login);
    e->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    if (e->nome == NULL) {
        free(e->login);
        free(e);
        return NULL;
    }
    strcpy(e->nome, nome);
    e->uni = (char*)malloc(sizeof(char) * (strlen(uni) + 1));
    if (e->uni == NULL) {
        free(e->nome);
        free(e->login);
        free(e);
        return NULL;
    }
    strcpy(e->uni, uni);
    e->localidade = (char*)malloc(sizeof(char) * (strlen(localidade) + 1));
    if (e->localidade == NULL) {
        free(e->uni);
        free(e->nome);
        free(e->login);
        free(e);
        return NULL;
    }
    strcpy(e->localidade, localidade);
    e->idade = idade;
    return e;
}

void destroiEstudante(estudante e) {
    destroiSequencia(e->candidaturasE);
    free(e->login);
    free(e->localidade);
    free(e->uni);
    free(e->nome);
    free(e);
}

void destroiGenEstudante(void* e) {
    destroiEstudante((estudante)e);
}
char * daNomeEstudante(estudante e){
    return e->nome;
}

int daIdadeEstudante(estudante e) {
    return e->idade;
}

char * daLocalidadeEstudante(estudante e){   
    return e->localidade;
}

char* daLoginEstudante(estudante e) {
    return e->login;
}

char * daUniversidadeEstudante(estudante e){   
    return e->uni;
}

int daNCandidaturasEstudante(estudante e) {
    return tamanhoSequencia(e->candidaturasE);
}

int daTamanhoSeqCEstudante(estudante e){
    return tamanhoSequencia(e->candidaturasE);
}

int candidataQuartoEstudante(estudante e, char * codigo) {
    int sucesso = 1;
    if(e==NULL){
        return 0;
    }
    for (int i = 1; i <= tamanhoSequencia(e->candidaturasE); i++) {
        if (strcmp((elementoPosSequencia(e->candidaturasE, i)), codigo) == 0) {
            sucesso = 0;
            break;
        }
    }
    if(sucesso==1){
        adicionaPosSequencia(e->candidaturasE, codigo, tamanhoSequencia(e->candidaturasE) + 1); 
    }
    return sucesso;
}

void removeSequenciaCandEstudante(estudante e) {
    destroiSequencia(e->candidaturasE);
    e->candidaturasE=criaSequencia(CAPCANE);
}

void removeCandQuartoEstudante(estudante e, char *codigo){
    if(e==NULL){
        return;
    }
    for(int i = 1; i<=tamanhoSequencia(e->candidaturasE);i++){
        if(strcmp(codigo,elementoPosSequencia(e->candidaturasE,i))==0){
            removePosSequencia(e->candidaturasE,i);
            break;
        }
    }
}

iterador listaCandidaturasEstudante(estudante e){
    return iteradorSequencia(e->candidaturasE);
}




