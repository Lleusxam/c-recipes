#include <stdio.h>

void menu_principal() {
    printf("=============================\n");
    printf("        MENU PRINCIPAL       \n");
    printf("=============================\n");
    printf("|   1. Menu de Receitas     |\n");
    printf("|   2. Menu de Autores      |\n");
    printf("|   3. Menu de Cardapio     |\n");
    printf("=============================\n");
}

void menu_receitas() {
    char opt;
    printf("=============================\n");
    printf("        MENU RECEITAS        \n");
    printf("=============================\n");
    printf("|   1. Cadastrar receita    |\n");
    printf("|   2. Editar receita       |\n");
    printf("|   3. Deletar receita      |\n");
    printf("|   4. Atualizar receita    |\n");
    printf("|   5. Pesquisar receita    |\n");
    printf("=============================\n");
    printf("\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &opt);
    getchar();
    printf("\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

void menu_autores() {
    char opt;
    printf("=============================\n");
    printf("        MENU AUTORES         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar autor      |\n");
    printf("|   2. Editar autor         |\n");
    printf("|   3. Deletar autor        |\n");
    printf("|   4. Atualizar autor      |\n");
    printf("|   5. Pesquisar autor      |\n");
    printf("=============================\n");
    printf("\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &opt);
    getchar();
    printf("\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

void menu_cardapio() {
    char opt;
    printf("=============================\n");
    printf("        MENU CARDAPIO         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar cardapio    |\n");
    printf("|   2. Editar cardapio       |\n");
    printf("|   3. Deletar cardapio      |\n");
    printf("|   4. Atualizar cardapio    |\n");
    printf("|   5. Pesquisar cardapio    |\n");
    printf("=============================\n");
    printf("\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &opt);
    getchar();
    printf("\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

void sobre() {
    printf("\nO CRecipes é um projeto educacional feito em linguagem C com o intuito de funcionar como um caderno de receitas\n");
    printf("Desenvolvedor: Maxsuel Gadelha O. da Silva\n");
    printf("Professor responsável: Flavius Gorgonio\n");
    printf("UFRN - Universidade Federal do Rio Grande do Norte\n");
}

int main(){
    sobre();
    
    printf("\n");

    menu_principal();
    
    printf("\n");
    
    menu_receitas();
    
    printf("\n");
    
    menu_autores();
    
    printf("\n");
    
    menu_cardapio();
}