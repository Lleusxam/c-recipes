#include <stdio.h>
#include "cardapio.h"
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
    char entrada[100];
    char prato_principal[100];
    char sobremesa[100];
    Cardapio novo_cardapio;
    printf("Entrada: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strlen(entrada) - 1] = 0; // Remove o \n do final da string

    printf("Prato Principal: ");
    fgets(prato_principal, sizeof(prato_principal), stdin);
    prato_principal[strlen(prato_principal) - 1] = 0;

    printf("Sobremesa: ");
    fgets(sobremesa, sizeof(sobremesa), stdin);
    sobremesa[strlen(sobremesa) - 1] = 0;

    // Adicionando o cardapio na array de cardapios
    novo_cardapio.id = *quantidade_cardapios + 1; // Atribua o ID com base no tamanho atual do vetor
    strncpy(novo_cardapio.entrada, entrada, sizeof(novo_cardapio.entrada));
    strncpy(novo_cardapio.prato_principal, prato_principal, sizeof(novo_cardapio.prato_principal));
    strncpy(novo_cardapio.sobremesa, sobremesa, sizeof(novo_cardapio.sobremesa));
    novo_cardapio.status = 1;
    
    cardapios[*quantidade_cardapios] = novo_cardapio;
    (*quantidade_cardapios)++;
}
void editar_cardapio(Cardapio cardapios[], int quantidade_cardapios) {
    int id;
    char entrada[100];
    char prato_principal[100];
    char sobremesa[100];
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
    
    printf("Digite as novas informações para o cardápio (ID: %d):\n", id);
    printf("Nova entrada: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strlen(entrada) - 1] = 0; // Remove o \n do final da string

    printf("Novo prato principal: ");
    fgets(prato_principal, sizeof(prato_principal), stdin);
    prato_principal[strlen(prato_principal) - 1] = 0;

    printf("Nova sobremesa: ");
    fgets(sobremesa, sizeof(sobremesa), stdin);
    sobremesa[strlen(sobremesa) - 1] = 0;

    // Atualizando o cardapio na array de cardapios
    strncpy(cardapios[index].entrada, entrada, sizeof(cardapios[index].entrada));
    strncpy(cardapios[index].prato_principal, prato_principal, sizeof(cardapios[index].prato_principal));
    strncpy(cardapios[index].sobremesa, sobremesa, sizeof(cardapios[index].sobremesa));
    cardapios[index].status = 1;

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

void pesquisar_cardapio(Cardapio cardapios[], int quantidade_cardapios) {
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
    printf("Informações do cardápio:\n");
    printf("Entrada: %s\n", cardapios[index].entrada);
    printf("Prato Principal: %s\n", cardapios[index].prato_principal);
    printf("Sobremesa: %s\n", cardapios[index].sobremesa);
    printf("Status: %d\n", cardapios[index].status);
}