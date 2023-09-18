#include <stdio.h>
char menu_autores() {
    char opt;
    printf("=============================\n");
    printf("        MENU AUTORES         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar autor      |\n");
    printf("|   2. Editar autor         |\n");
    printf("|   3. Deletar autor        |\n");
    printf("|   4. Atualizar autor      |\n");
    printf("|   5. Pesquisar autor      |\n");
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