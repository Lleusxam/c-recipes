#ifndef CARDAPIO_H
#define CARDAPIO_H
#include "receitas.h"
typedef struct Cardapio
{
    int id;
    int entrada;
    int prato_principal;
    int sobremesa;
    int status;
} Cardapio;

char menu_cardapio();
void cadastrar_cardapio();
void editar_cardapio();
void deletar_cardapio();
void pesquisar_cardapio();
void salvar_cardapio(Cardapio *cardapio);
int existe_cardapio(int id);
#endif