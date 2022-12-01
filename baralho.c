#include<stdlib.h>
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
    if(novo_baralho != NULL){
        novo_baralho->cabeca = NULL;
        novo_baralho->tam = 0;
    }
    novo_baralho;
}

int adiciona_carta(Baralho* baralho, Carta carta){
    if(baralho == NULL)return 0;//Baralho passado não existe

    No* novo_no = (No*)malloc(sizeof(No));
    if(novo_no == NULL)return 0; // Não foi possível alocar um novo nó

    novo_no->carta = carta;
    novo_no->proximo = baralho->cabeca;
    baralho->cabeca = novo_no;
    baralho->tam++;
    return 1;
}

int acessa_carta(Baralho* baralho, int index, Carta* carta){
    if(baralho == NULL || index >= baralho->tam)return 0;
    No* procura = baralho->cabeca;
    for(int i=0; i<index; i++){
        procura = procura->proximo;
    }
    *carta = procura->carta;
    return 1;
}

int apaga_carta(Baralho* baralho, int index){
    if(baralho == NULL || index >= baralho->tam)return 0;

    if(baralho->tam == 1){
        free(baralho->cabeca);
        baralho->cabeca = NULL;
        baralho->tam--;
        return 1;
    }

    No* anterior = baralho->cabeca;
    No* apagado  =  baralho->cabeca->proximo;

    for(int i=0; i<index-1; i++){
        anterior = anterior->proximo;
        apagado = apagado->proximo;
    }

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