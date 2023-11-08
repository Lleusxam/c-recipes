#ifndef CARDAPIO_H
#define CARDAPIO_H
#include "receitas.h"
typedef struct Cardapio {
    int id;
    int entrada;
    int prato_principal;
    int sobremesa;
    int status;
} Cardapio;

char menu_cardapio();
void cadastrar_cardapio(Cardapio cardapios[], int *quantidade_cardapios);
void editar_cardapio(Cardapio cardapios[], int quantidade_cardapaios);
void deletar_cardapio(Cardapio cardapios[], int quantidade_cardapios);
void pesquisar_cardapio(Cardapio cardapios[], int quantidade_cardapios, Receita receitas[], int quantidade_receitas);

#define CARDAPIO_H

#endif 