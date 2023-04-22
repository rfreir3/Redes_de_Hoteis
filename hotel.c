#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"

struct hotel{
    char nome[50];
    Quartos quartos;
    char local[100];
    int stars;
};

struct quartos{
    char tipo[15];
    float preco;
    int disp;
    struct quartos *next;
    struct quartos *ant;
};

Hotel* add_hotel(void){
    Hotel *novo = (Hotel*)malloc(sizeof(Hotel));
    printf("Adicionando novo hotel...\n");
    printf("Digite o nome do hotel: ");
    scanf("%s", novo->nome);
    printf("Digite a localidade do hotel: ");
    scanf("%s", novo->local);
    printf("Digite a quantidade de estrelas do hotel (entre 0 e 4) ");
    scanf("%i", &novo->stars);
    return(novo);
}









