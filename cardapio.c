#include <stdio.h>
#include "cardapio.h"
#include "receitas.h"
#include <string.h>
#include <stdlib.h>
char menu_cardapio() {
    char opt;
    printf("=============================\n");
    printf("        MENU CARDAPIO         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar cardapio    |\n");
    printf("|   2. Editar cardapio       |\n");
    printf("|   3. Deletar cardapio      |\n");
    printf("|   4. Pesquisar cardapio    |\n");
    printf("|   0. Retornar             |\n");
    printf("=============================\n");
    printf("\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &opt);
    getchar();
    printf("\n");
    printf("Pressione ENTER para continuar...");
    getchar();
    return opt;
}

int existe_cardapio(Cardapio cardapios[], int quantidade_cardapios, int id) {
    for (int i = 0; i < quantidade_cardapios; i++) {
        if (cardapios[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void cadastrar_cardapio(Cardapio cardapios[], int *quantidade_cardapios) {
    printf("=============================\n");
    printf("      CADASTRAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
    Cardapio novo_cardapio;
    int entrada;
    int prato_principal;
    int sobremesa;
    printf("Digite o ID da receita que será a Entrada ");
    scanf("%d", &entrada);
    getchar();
    
    printf("Digite o ID da receita que será o Prato Principal ");
    scanf("%d", &prato_principal);
    getchar();
    
    printf("Digite o ID da receita que será a Sobremesa ");
    scanf("%d", &sobremesa);
    getchar();

    cardapios[*quantidade_cardapios].status = 1;

    novo_cardapio.id = *quantidade_cardapios + 1;
    novo_cardapio.entrada = entrada;
    novo_cardapio.prato_principal = prato_principal;
    novo_cardapio.sobremesa = sobremesa;
    novo_cardapio.status = 1;
    cardapios[*quantidade_cardapios] = novo_cardapio;
    (*quantidade_cardapios)++;

    printf("\nCardapio cadastrado com sucesso!\n");
}
void editar_cardapio(Cardapio cardapios[], int quantidade_cardapios) {
    int id;
    int entrada;
    int prato_principal;
    int sobremesa;
    printf("=============================\n");
    printf("        EDITAR CARDAPIO      \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o ID do cardápio: ");
    scanf("%d", &id);
    getchar();
    int index = id - 1;

    int encontrada = existe_cardapio(cardapios, quantidade_cardapios, id);
    if(encontrada == 0) {
        printf("\nCardapio não encontrado!\n");
        return;
    }

    printf("Digite o ID da receita que será a Entrada ");
    scanf("%d", &entrada);
    getchar();

    printf("Digite o ID da receita que será o Prato Principal ");
    scanf("%d", &prato_principal);
    getchar();

    printf("Digite o ID da receita que será a Sobremesa ");
    scanf("%d", &sobremesa);
    getchar();

    cardapios[index].entrada = entrada;
    cardapios[index].prato_principal = prato_principal;
    cardapios[index].sobremesa = sobremesa;

    printf("\nCardapio editado com sucesso!\n");
}

void deletar_cardapio(Cardapio cardapios[], int quantidade_cardapios) {
    int id;
    printf("=============================\n");
    printf("       DELETAR CARDAPIO      \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite o ID do cardápio: ");
    scanf("%d", &id);
    getchar();

    int index = id - 1;

    // Procura o cardápio com o ID especificado
    int encontrada = existe_cardapio(cardapios, quantidade_cardapios, id);
    if(encontrada == 0) {
        printf("\nCardapio não encontrado!\n");
        return;
    }
    cardapios[index].status = 0;
    printf("\nCardapio deletado com sucesso!\n");
}

void pesquisar_cardapio(Cardapio cardapios[], int quantidade_cardapios, Receita receitas[], int quantidade_receitas) {
    int id;
    printf("=============================\n");
    printf("      PESQUISAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
    
    printf("Digite o ID do cardápio: ");
    scanf("%d", &id);
    getchar();

    int index = id - 1;

    // Procura o cardápio com o ID especificado
    int encontrada = existe_cardapio(cardapios, quantidade_cardapios, id);
    if(encontrada == 0) {
        printf("\nCardapio não encontrado!\n");
        return;
    }
    printf("\n");
    printf("ID: %d\n", cardapios[index].id);
    printf("Entrada: %s\n", receitas[cardapios[index].entrada - 1].nome);
    printf("Prato Principal: %s\n", receitas[cardapios[index].prato_principal - 1].nome);
    printf("Sobremesa: %s\n", receitas[cardapios[index].sobremesa - 1].nome);
    printf("\n");
}