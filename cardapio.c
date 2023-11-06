#include <stdio.h>
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

void cadastrar_cardapio() {
    printf("=============================\n");
    printf("      CADASTRAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
}

void editar_cardapio() {
    printf("=============================\n");
    printf("        EDITAR CARDAPIO      \n");
    printf("=============================\n");
    printf("\n");
}

void deletar_cardapio() {
    printf("=============================\n");
    printf("       DELETAR CARDAPIO      \n");
    printf("=============================\n");
    printf("\n");
}

void atualizar_cardapio() {
    printf("=============================\n");
    printf("      ATUALIZAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
}

void pesquisar_cardapio() {
    printf("=============================\n");
    printf("      PESQUISAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
}