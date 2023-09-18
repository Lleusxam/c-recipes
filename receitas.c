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