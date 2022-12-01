#include<stdio.h>
#include "baralho.h"

void imprimeCarta(Carta* carta){
    printf("valor: %c\nnaipe: %s\n", carta->valor, carta->naipe);
}


int main(){

    Baralho* minhas_cartas = cria_baralho();

    Carta c1 = {'A', "UUU"};
    Carta c2 = {'B', "VVV"};
    Carta c3 = {'C', "CCC"};
    Carta c4 = {'D', "EEE"};
    Carta c5 = {'E', "GGG"};

    adiciona_carta(minhas_cartas, c1);
    adiciona_carta(minhas_cartas, c2);
    adiciona_carta(minhas_cartas, c3);
    adiciona_carta(minhas_cartas, c4);

    Carta acesso;

    acessa_carta(minhas_cartas, 2, &acesso);

    imprimeCarta(&acesso);

    destroi_baralho(minhas_cartas);


}