#include <stdio.h>
#include <stdlib.h>
#include "quarto.h"
#include "hotel.h"

struct quarto{
    char tipo[20];
    float preco;
    int disp;
    int num;
};

Quarto *add_quarto(void){
    int qntd, i;
    printf("Informe quantos quartos deseja adicionar no hotel: ");
    scanf("%d", &qntd);
    if(qntd<=0){
        printf("Valor invalido!");
        return(NULL);
    }
    Quarto **novo_quarto = (Quarto**)malloc(qntd * sizeof(Quarto*));

    for(i=0;i<=qntd;i++){
        printf("Digite o numero do quarto: ");
        scanf("%d", &novo_quarto[i]->num);
        printf("Digite o tipo do quarto: ");
        scanf("%s", novo_quarto[i]->tipo);
        printf("Digite o preco do quarto: ");
        scanf("%f", &novo_quarto[i]->preco);
        do{
            printf("Digite 0 se o quarto esta disponivel, e 1 se nao estiver: ");
            scanf("%d", &novo_quarto[i]->disp);
        }while((novo_quarto[i]->disp == 0)||(novo_quarto[i]->disp == 1));
    }
    return(novo_quarto);
}

void consultar_quartos(Lista *lista){
	Lista *percorre;
    char nome_hotel[50];
    printf("Digite o nome do hotel que deseja consultar: ");
    scanf("%s", nome_hotel);
	for(percorre=lista; percorre!=NULL; percorre=percorre->prox){
		if(strcmp(percorre->info->nome, nome_hotel) == 0){
            if(percorre->info->room->disp == 0){
                printf("Localidade: %s\n", percorre->info->local);
                printf("Avaliacao: %s", percorre->info->avalia);
                printf("Numero do quarto: %d\n", percorre->info->room->num);
                printf("Tipo do quarto: %s\n", percorre->info->room->tipo);
                printf("Preco: %f\n", &percorre->info->room->preco);
            }
            else{
                printf("Quarto indisponivel!\n");
            }    
		}
        else{
            printf("Hotel nao encontrado!\n");
        }
	}
}

void quantitativa_quartos(Lista *lista){
    Lista *percorre;
    int cont;
    char novo_hotel[50];
    printf("Digite o nome do hotel que deseja consultar: ");
    scanf("%s", novo_hotel);
    
    for(percorre=lista; percorre!=NULL; percorre = percorre->prox){
        if(strcmp(percorre->info->nome, novo_hotel) == 0){
            if(percorre->info->room!=NULL){
                cont++;
            }
        }
    }
    printf("Quantitativa de quartos no hotel %s: %d", novo_hotel, cont);
}