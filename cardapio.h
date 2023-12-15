#ifndef CARDAPIO_H
#define CARDAPIO_H
#include "receitas.h"
typedef struct Cardapio
{
    int id;
    int entrada;
    int prato_principal;
    int sobremesa;
    char nome[100];
    int status;
} Cardapio;

char menu_cardapio();
void cadastrar_cardapio();
void editar_cardapio();
void deletar_cardapio();
void pesquisar_cardapio();
void listar_cardapios();
void salvar_cardapio(Cardapio *cardapio);
int existe_cardapio(int id);
int existe_cardapio_nome(char* nome);
void pesquisar_cardapio_nome();
#endif