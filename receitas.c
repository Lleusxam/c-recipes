#include <stdio.h>
char menu_receitas() {
    char opt;
    printf("=============================\n");
    printf("        MENU RECEITAS        \n");
    printf("=============================\n");
    printf("|   1. Cadastrar receita    |\n");
    printf("|   2. Editar receita       |\n");
    printf("|   3. Deletar receita      |\n");
    printf("|   4. Atualizar receita    |\n");
    printf("|   5. Pesquisar receita    |\n");
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

void cadastrar_receita() {
    printf("=============================\n");
    printf("      CADASTRAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");
}

void editar_receita() {
    printf("=============================\n");
    printf("        EDITAR RECEITA       \n");
    printf("=============================\n");
    printf("\n");
}

void deletar_receita() {
    printf("=============================\n");
    printf("       DELETAR RECEITA       \n");
    printf("=============================\n");
    printf("\n");
}

void atualizar_receita() {
    printf("=============================\n");
    printf("      ATUALIZAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");
}

void pesquisar_receita() {
    printf("=============================\n");
    printf("      PESQUISAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");
}