#include <stdio.h>
char menu_ingredientes() {
    char opt;
    printf("=============================\n");
    printf("        MENU INGREDIENTES    \n");
    printf("=============================\n");
    printf("|   1. Cadastrar ingrediente|\n");
    printf("|   2. Editar ingrediente   |\n");
    printf("|   3. Deletar ingrediente  |\n");
    printf("|   4. Atualizar ingrediente|\n");
    printf("|   5. Pesquisar ingrediente|\n");
    printf("|   0. Retornar             |\n");
    printf("=============================\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &opt);
    getchar();
    printf("\n");
    printf("Pressione ENTER para continuar...");
    getchar();
    return opt;
}

void cadastrar_ingrediente() {
    printf("=============================\n");
    printf("     CADASTRAR INGREDIENTE   \n");
    printf("=============================\n");
    printf("\n");
}

void editar_ingrediente() {
    printf("=============================\n");
    printf("       EDITAR INGREDIENTE    \n");
    printf("=============================\n");
    printf("\n");
}

void deletar_ingrediente() {
    printf("=============================\n");
    printf("      DELETAR INGREDIENTE    \n");
    printf("=============================\n");
    printf("\n");
}

void atualizar_ingrediente() {
    printf("=============================\n");
    printf("     ATUALIZAR INGREDIENTE   \n");
    printf("=============================\n");
    printf("\n");
}

void pesquisar_ingrediente() {
    printf("=============================\n");
    printf("     PESQUISAR INGREDIENTE   \n");
    printf("=============================\n");
    printf("\n");
}