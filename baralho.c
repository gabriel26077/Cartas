#include <stdlib.h>
#include "baralho.h"

typedef struct no{
   Carta carta;
   struct no* proximo; 
}No;


struct baralho{
    No* cabeca;
    int tam;
};


Baralho* cria_baralho(){
    Baralho* novo_baralho = (Baralho*)malloc(sizeof(Baralho));
    if(novo_baralho != NULL){ //se o baralho foi alocado com sucesso
        novo_baralho->cabeca = NULL; //aponta para nada pq não foi adicionada nenhuma carta
        novo_baralho->tam = 0;  //autoexplicativo
    }
    return novo_baralho;
}

int adiciona_carta(Baralho* baralho, Carta carta){ //preenchimento em pilha, as cartas vão sendo adicionadas no início
    if(baralho == NULL)return 0;//Baralho passado não existe

    No* novo_no = (No*)malloc(sizeof(No));
    if(novo_no == NULL)return 0; // Não foi possível alocar um novo nó

    novo_no->carta = carta;
    novo_no->proximo = baralho->cabeca; //aponta para a carta que nesse momento é a primeira
    baralho->cabeca = novo_no; //agora o novo_no vira a cabeça
    baralho->tam++; //atualiza a quantidade de cartas do baralho
    return 1; //nada pegou fogo
}

int acessa_carta(Baralho* baralho, int index, Carta* carta){ //fotocópia de cartas ou método getter da deep web
    if(baralho == NULL || index >= baralho->tam)return 0; //baralho não existe ou índice passado excede a quantidade de cartas que existem no baralho
    No* procurador = baralho->cabeca; //"entra" pro baralho
    for(int i=0; i<index; i++){//avança na estrutura de nós até chegar no nó que corresponde ao index
        procurador = procurador->proximo;   //esse é o jeito :/
    }
    *carta = procurador->carta; //"copia" a informação da carta encontrada para uma carta em branco.
    return 1; //esperamos que nada tenha pego fogo
}

int descarta_carta(Baralho* baralho, int index){
    if(baralho == NULL || index >= baralho->tam)return 0;//baralho não existe ou índice passado excede a quantidade de cartas que existem no baralho
    
    if(baralho->tam == 1){ 
        free(baralho->cabeca);
        baralho->cabeca = NULL;
        baralho->tam--;
        return 1;
    }

    No* anterior = baralho->cabeca;

    for(int i=0; i<index-1; i++){
        anterior = anterior->proximo;
    }
    
    No* apagado = anterior->proximo;
    anterior->proximo = apagado->proximo;

    free(apagado); 
    baralho->tam--;
    return 1;
}

int destroi_baralho(Baralho* baralho){
    if(baralho == NULL)return 0;
    while(baralho->tam > 0)
        apaga_carta(baralho, 0);
    free(baralho);
    return 1;
}