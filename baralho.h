#ifndef BARALHO_H
#define BARALHO_H

/// @brief 
struct  carta{
    char valor;
    char naipe[4];
};

typedef struct carta Carta;
typedef struct baralho Baralho;

Baralho* cria_baralho();

int adiciona_carta(Baralho* baralho, Carta carta);

int tamanho_baralho(Baralho* baralho);

int adiciona_carta_no_inicio(Baralho* baralho, Carta carta);

int acessa_carta(Baralho* baralho, int index, Carta* carta);

int descarta_carta(Baralho* baralho, int index);

int gira_baralho(Baralho* baralho);

int destroi_baralho(Baralho* baralho);


void printa_elementos(Baralho* baralho);

void printa_de_tras_para_frente(Baralho* baralho);


#endif