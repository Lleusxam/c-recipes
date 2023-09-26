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