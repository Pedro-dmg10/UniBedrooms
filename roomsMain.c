/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "uniBedrooms.h"
#include "messages.h"

#define MAX_CMD_LENGTH 10
#define MAX_LINE_LENGTH 100
#define max_string_ids 20
#define max_string_nomes 50
#define MAX_string_descricao 200
#define ESTADO 10
#define CAPCANE 10   ////nº máx de candidaturas de um estudante

void interpretador(uniBedrooms u);
void cmdInsereNovoEstudante(uniBedrooms u, char *linha);
void cmdConsultaDadosEstudante(uniBedrooms u, char *login);
void cmdInsereNovoGerente(uniBedrooms u, char *linha);
void cmdConsultaDadosGerente(uniBedrooms u, char *linha);
void cmdInsereNovoQuarto(uniBedrooms u, char *linha);
void cmdConsultaDadosQuarto(uniBedrooms u, char *linha);
void cmdModificaEstadoQuarto(uniBedrooms u, char *linha);
void cmdRemoveQuarto(uniBedrooms u, char *linha);
void cmdInsereCandidatura(uniBedrooms u, char *linha);
void cmdAceitaCandidatura(uniBedrooms u, char *linha);
void cmdListaCandidaturas(uniBedrooms u, char *linha);
void cmdListaQuartos(uniBedrooms u);
void cmdListaQuartosVagos(uniBedrooms u, char *linha);
void cmdListaTopGerentes(uniBedrooms u);


int main(void) {
    uniBedrooms Residenciafct = criaUniBedrooms();
    interpretador(Residenciafct);
    destroiUniBedrooms(Residenciafct);
    return 0;
}

void interpretador(uniBedrooms u) {
    char comando[MAX_CMD_LENGTH];
    char linha[MAX_LINE_LENGTH];
    do {
        printf("> ");
        fgets(linha, MAX_LINE_LENGTH, stdin);
        sscanf(linha, "%s", comando);
        if(comando[0]== '#'){
            printf("\n\n");   
        }
        // Tratar comando
        if (strcmp(comando, "IE") == 0) {
            cmdInsereNovoEstudante(u, linha);
            printf("\n");          
        }
		else if(strcmp(comando, "DE")==0){
			cmdConsultaDadosEstudante(u,linha);
            printf("\n");
		}
        else if(strcmp(comando, "IG")==0){
            cmdInsereNovoGerente(u,linha);
            printf("\n");
        }
        else if(strcmp(comando, "DG")==0){
            cmdConsultaDadosGerente(u,linha);
            printf("\n");
        }
        else if(strcmp(comando, "IQ")==0){
            cmdInsereNovoQuarto(u,linha);
            printf("\n");
        }
        else if(strcmp(comando, "DQ")==0){
            cmdConsultaDadosQuarto(u,linha);
            printf("\n");
        }
        else if(strcmp(comando, "MQ")==0){
            cmdModificaEstadoQuarto(u,linha);
            printf("\n");
        }
        else if(strcmp(comando, "RQ")==0){
            cmdRemoveQuarto(u,linha);
            printf("\n");
        }
        else if(strcmp(comando,"IC")==0){
            cmdInsereCandidatura(u,linha);
            printf("\n");
        }
        else if(strcmp(comando,"AC")==0){
            cmdAceitaCandidatura(u,linha);
            printf("\n");
        }
        else if(strcmp(comando,"LC")==0){
            cmdListaCandidaturas(u,linha);
            printf("\n");
        }
        else if(strcmp(comando,"LQ")==0){
            cmdListaQuartos(u);
            printf("\n");
        }
        else if(strcmp(comando,"LL")==0){
            cmdListaQuartosVagos(u,linha);
            printf("\n");
        }
        else if(strcmp(comando,"LT")==0){
            cmdListaTopGerentes(u);
            printf("\n");
        }
        else if(strcmp(comando, "LT")!=0 && strcmp(comando, "XS")!=0 && comando[0] != '#'){
            printf("%s\n",MSG_COMANDO_INVALIDO);
            printf("\n");
            continue;
        }
    } while (strcmp(comando, "XS") != 0);
        printf("%s",MSG_SAIR);
        printf("\n\n");     
}

void cmdInsereNovoEstudante(uniBedrooms u, char *linha) { 
    char login[max_string_ids], nomeEstudante[max_string_nomes], localidade[max_string_nomes], universidade[max_string_nomes];
    int idade;

    if (sscanf(linha, " %*s %19s %[^\n]\n", login, nomeEstudante) != 2) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    fgets(linha, max_string_ids + max_string_nomes, stdin);
    sscanf(linha, "%d %[^\n]\n", &idade , localidade);
    fgets(linha, max_string_nomes, stdin);
    sscanf(linha, "%[^\n]", universidade);
    if (criaEstudanteUniBedrooms(u, login, nomeEstudante, universidade, localidade, idade) != 1) {
        printf("%s",MSG_UTILIZADOR_EXISTENTE);
        printf("\n");
    } else {
        printf("%s",MSG_REGISTO_ESTUDANTE_OK);
        printf("\n");
    }
}

void cmdConsultaDadosEstudante(uniBedrooms u, char *linha){
	char login[max_string_ids];
	if (sscanf(linha, " %*s %19s", login) != 1) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
	estudante e = daEstudanteUniBedrooms(u, login);

	if(e == NULL){
		printf("%s\n",MSG_ESTUDANTE_INEXISTENTE);
	}else{
		printf("%s, %s, %d anos, %s",daLoginEstudante(e),daNomeEstudante(e),daIdadeEstudante(e),daLocalidadeEstudante(e));
		printf("\n");
		printf("%s",daUniversidadeEstudante(e));
        printf("\n");
	}
}

void cmdInsereNovoGerente(uniBedrooms u, char *linha) {
    char login[max_string_ids], nomeGerente[max_string_nomes], universidade[max_string_nomes];

    if (sscanf(linha, "%*s %19s %[^\n]\n", login, nomeGerente) != 2) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    fgets(linha, max_string_nomes, stdin);
    sscanf(linha, "%[^\n]", universidade);
    if (criaGerenteUniBedrooms(u, login, nomeGerente, universidade)!= 1) {
        printf("%s",MSG_UTILIZADOR_EXISTENTE);
        printf("\n");
    } else {
        printf("%s",MSG_REGISTO_GERENTE_OK); 
        printf("\n");      
    }
}

void cmdConsultaDadosGerente(uniBedrooms u, char *linha){
	char login[max_string_ids];
	if (sscanf(linha, "%*s %19s", login) != 1) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
	gerente g = daGerenteUniBedrooms(u, login);
	if(g == NULL){
		printf("%s",MSG_GERENTE_INEXISTENTE);
        printf("\n");
	}else{
		printf("%s, %s",daLoginGerente(g),daNomeGerente(g));
        printf("\n"); 
		printf("%s",daUniversidadeGerente(g));
        printf("\n");
	}
}

void cmdInsereNovoQuarto(uniBedrooms u, char *linha){ 
    char codigo[max_string_ids], loginGerente[max_string_ids], nomeResidencia[max_string_nomes], universidade[max_string_nomes],localidade[max_string_nomes];
    char descricao[MAX_string_descricao];
    int andar;

    if (sscanf(linha, " %*s %19s %19s", codigo, loginGerente) != 2) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    fgets(linha, max_string_nomes, stdin);
    sscanf(linha, "%[^\n]", nomeResidencia);

    fgets(linha, max_string_nomes, stdin);
    sscanf(linha, "%[^\n]", universidade);

    fgets(linha, max_string_nomes, stdin);
    sscanf(linha, "%[^\n]", localidade);

    fgets(linha, max_string_ids, stdin);
    sscanf(linha, "%d", &andar);

    fgets(linha, MAX_string_descricao, stdin);
    sscanf(linha, "%[^\n]", descricao);

    if(existeQuartoUniBedrooms(u,codigo)==1){
        printf("%s",MSG_QUARTO_EXISTENTE);
        printf("\n");
    }
    else if(existeGerenteUniBedrooms(u, loginGerente)==0){
        printf("%s",MSG_GERENTE_INEXISTENTE);
        printf("\n");
        return;
    }
    else if(verificaUniGerenteUniBedrooms(u, loginGerente, universidade)){ 
        printf("%s",MSG_OP_NAO_AUTORIZADA);
        printf("\n");
    }
    else if(criaQuartoUniBedrooms(u,codigo,loginGerente,nomeResidencia,universidade,localidade,andar,descricao)!=1){   
        printf("%s",MSG_QUARTO_EXISTENTE);
        printf("\n");
    }
    else{
        printf("%s",MSG_REGISTO_QUARTO_OK);
        printf("\n");
        adicionaLocalidadeUniBedrooms(u,localidade);
        adicionaQuartoLocalidadeUniBedrooms(u,localidade,codigo);
    } 
}

void cmdConsultaDadosQuarto(uniBedrooms u, char *linha){
    char codigo[max_string_ids];
    if (sscanf(linha, "%*s %19s", codigo) != 1) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    quarto q = daQuartoUniBedrooms(u,codigo);
    if(q==NULL){
        printf("%s\n",MSG_QUARTO_INEXISTENTE);
    }
    else{
        printf("%s, %s\n",codigo, daNomeResidenciaQuarto(q));
        printf("%s\n",daUniQuarto(q));
        printf("%s\n",daLocalidadeQuarto(q));
        printf("%d\n",daAndarQuarto(q));
        printf("%s\n",daDescricaoQuarto(q));
        printf("%s\n", daOcupacaoQuarto(q));
    }
}


void cmdModificaEstadoQuarto(uniBedrooms u, char *linha){    
    char codigo[max_string_ids], loginGerente[max_string_ids], novoEstado[ESTADO];
    if (sscanf(linha, "%*s %19s %19s %9s", codigo,loginGerente,novoEstado) != 3) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    if(existeQuartoUniBedrooms(u,codigo)==0){
        printf("%s\n",MSG_QUARTO_INEXISTENTE);
    }
    else if(verificaLoginGerenteQuartoUniBedrooms(u,codigo,loginGerente)){ 
        printf("%s\n",MSG_OP_NAO_AUTORIZADA);
    }
    else if(verificaEstadoQuartoUniBedrooms(u, novoEstado)==0 && daNCandidaturasQuartoUniBedrooms(u,codigo)!=0){ 
            printf("%s\n",MSG_CANDIDATURAS_ACTIVAS);
    }
    else{
        modificaEstadoQuartoUniBedrooms(u, codigo, novoEstado);  
        printf("%s",MSG_QUARTO_ATUALIZADO);
        printf("\n");
    }
}

void cmdRemoveQuarto(uniBedrooms u, char *linha){    
    char codigo[max_string_ids], loginGerente[max_string_ids];
    if (sscanf(linha, "%*s %19s %19s", codigo,loginGerente) != 2) {
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    if(existeQuartoUniBedrooms(u,codigo)==0){
        printf("%s\n",MSG_QUARTO_INEXISTENTE);
    }
    else if(verificaLoginGerenteQuartoUniBedrooms(u,codigo,loginGerente)){ 
        printf("%s\n",MSG_OP_NAO_AUTORIZADA);
    }
    else if(daNCandidaturasQuartoUniBedrooms(u,codigo)!=0){
        printf("%s\n",MSG_CANDIDATURAS_ACTIVAS);
    }
    else{
        removeQuartoLocalidadeUniBedrooms(u,daLocalidadeQuarto(daQuartoUniBedrooms(u,codigo)),codigo);
        removeQuartoUniBedrooms(u,codigo);
        printf("%s",MSG_REMOCAO_QUARTO_OK);
        printf("\n");
        
    }
}

void cmdInsereCandidatura(uniBedrooms u, char *linha){
    char codigo[max_string_ids], loginEstudante[max_string_ids];
    if (sscanf(linha, "%*s %19s %19s", loginEstudante, codigo) != 2){
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    if(existeEstudanteUniBedrooms(u,loginEstudante)==0){
        printf("%s\n",MSG_ESTUDANTE_INEXISTENTE);
        return;
    }
    if (daNCndidaturasEstudanteUniBedrooms(u,loginEstudante) >= CAPCANE){
        printf("%s\n",MSG_OP_NAO_AUTORIZADA);
        return;
    }
    if(existeQuartoUniBedrooms(u,codigo)==0){
        printf("%s\n",MSG_QUARTO_INEXISTENTE);
        return;
    }
    if(verificaEstadoQuartoUniBedrooms(u,daOcupacaoQuartoUniBedrooms(u, codigo))==0){
        printf("%s\n",MSG_QUARTO_OCUPADO);
        return;
    }
    if(candidataQuartoEstudanteUniBedrooms(u,codigo,loginEstudante)==0){ 
        printf("%s\n",MSG_CANDIDATURA_EXISTENTE);
    }
    else{
        printf("%s\n",MSG_REGISTO_CANDIDATURA_OK);
    }
}

void cmdAceitaCandidatura(uniBedrooms u, char *linha){
    char codigo[max_string_ids], loginGerente[max_string_ids], loginEstudante[max_string_ids];
    if (sscanf(linha, "%*s %19s %19s %19s", codigo, loginGerente, loginEstudante) != 3){
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    if(existeQuartoUniBedrooms(u,codigo)==0){
        printf("%s\n",MSG_QUARTO_INEXISTENTE);
    }
    else if(verificaLoginGerenteQuartoUniBedrooms(u,codigo,loginGerente)){ 
        printf("%s\n",MSG_OP_NAO_AUTORIZADA);
    }
    else if(existeCandidaturaQuartoUniBedrooms(u,codigo,loginEstudante)==0){   
        printf("%s\n",MSG_CANDIDATURA_INEXISTENTE);
    }
    else{
        aceitaCandidaturaUniBedrooms(u,codigo,loginEstudante);
        printf("%s\n",MSG_ACEITAR_CANDIDATURA);
        
    }
}

void cmdListaCandidaturas(uniBedrooms u, char *linha){
    char codigo[max_string_ids], loginGerente[max_string_ids];
    if (sscanf(linha, "%*s %19s %19s", codigo, loginGerente) != 2){
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    
    if (!existeQuartoUniBedrooms(u,codigo)) {
        printf("%s\n", MSG_QUARTO_INEXISTENTE);
        return;
    }
    if(verificaLoginGerenteQuartoUniBedrooms(u,codigo,loginGerente)){ 
        printf("%s\n",MSG_OP_NAO_AUTORIZADA);
    }
    else if(daNCandidaturasQuartoUniBedrooms(u,codigo)==0){
        printf("%s\n", MSG_INEXISTENCIA_CANDIDATURAS);
    }
    else{
        iterador it = listaCandidaturasQuartoUniBedrooms(u,codigo); 
        while(temSeguinteIterador(it)){
            estudante e = (estudante)seguinteIterador(it);
            printf("%s, %s, %s\n",daLoginEstudante(e), daNomeEstudante(e), daUniversidadeEstudante(e));
        }
        destroiIterador(it);
    }
}

void cmdListaQuartos(uniBedrooms u){
    if(daNQuartosUniBedrooms(u)==0){
        printf("%s\n",MSG_INEXISTENCIA_QUARTOS);
        return;
    }
    iterador it = listaFinalUniBedrooms(u);
    while(temSeguinteIterador(it)){                    //lista quartos
        quarto q = (quarto)seguinteIterador(it);
        printf("%s %s\n",daLocalidadeQuarto(q), daCodQuarto(q));
        printf("%s\n",daUniQuarto(q));
        printf("%s\n\n",daNomeResidenciaQuarto(q));
    }
    destroiIterador(it);
    /*
    iterador it = listaLocalidadeUniBedrooms(u); 
        while(temSeguinteIterador(it)){
            localidade l = (localidade)seguinteIterador(it);
            iterador it2 = listaQuartoLocalidade(l);
            while(temSeguinteIterador(it2)){                    //lista quartos
                quarto q = (quarto)seguinteIterador(it2);
                printf("%s %s\n",daLLocalidade(l), daCodQuarto(q));
                printf("%s\n",daUniQuarto(q));
                printf("%s\n\n",daNomeResidenciaQuarto(q));
            }
            destroiIterador(it2);
        }
    destroiIterador(it);
    */
}

void cmdListaQuartosVagos(uniBedrooms u, char *linha){
    char localidades[max_string_nomes];
    int contador = 0; 
    if (sscanf(linha, "%*s %[^\n]", localidades) != 1){
        printf("%s\n",MSG_COMANDO_INVALIDO);
        return;
    }
    localidade l = daLocalidadeUniBedrooms(u,localidades);
    if(l==NULL){
        printf("%s\n",MSG_INEXISTENCIA_QUARTOS_LOCAL);
        return;
    }
    if(daNQuartosLocalidade(l)==0){
        printf("%s\n",MSG_INEXISTENCIA_QUARTOS_LOCAL);
        return;
    }
    else{
        iterador it = listaQuartoLocalidade(l);
        while(temSeguinteIterador(it)){
            quarto q = (quarto)seguinteIterador(it);
            if(verificaEstadoQuartoUniBedrooms(u,daOcupacaoQuartoUniBedrooms(u, daCodQuarto(q)))!=0){  
                printf("%s %s\n",daLLocalidade(l), daCodQuarto(q));
                printf("%s\n",daUniQuarto(q));
                printf("%s\n\n",daNomeResidenciaQuarto(q)); 
                contador++;
            }
        }
    }
    if(contador==0){
        printf("%s\n",MSG_INEXISTENCIA_QUARTOS_LOCAL);
    }
}

void cmdListaTopGerentes(uniBedrooms u){
    if(daNumGerentesUniBedrooms(u)==0){
        printf("%s\n",MSG_INEXISTENCIA_GERENTES);
    }
    else{
        for(int i=0;i<daNumTop3UniBedrooms(u);i++){
            gerente g = daGerenteUniBedrooms(u, retornaTop3UniBedrooms(u,i));
            printf("%s alugou %d quartos\n", retornaTop3UniBedrooms(u,i), daNQAlugadosGerente(g) );
        }
    }
    
}
