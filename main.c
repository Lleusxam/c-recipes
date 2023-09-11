#include <stdio.h>

    char menu_principal() {
    char opt;
    printf("=============================\n");
    printf("        MENU PRINCIPAL       \n");
    printf("=============================\n");
    printf("|   1. Menu de Receitas     |\n");
    printf("|   2. Menu de Autores      |\n");
    printf("|   3. Menu de Cardapio     |\n");
    printf("|   0. Finalizar o programa |\n");
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

char menu_cardapio() {
    char opt;
    printf("=============================\n");
    printf("        MENU CARDAPIO         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar cardapio    |\n");
    printf("|   2. Editar cardapio       |\n");
    printf("|   3. Deletar cardapio      |\n");
    printf("|   4. Atualizar cardapio    |\n");
    printf("|   5. Pesquisar cardapio    |\n");
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

void sobre() {
    printf("\nO CRecipes é um projeto educacional feito em linguagem C com o intuito de funcionar como um caderno de receitas\n");
    printf("Desenvolvedor: Maxsuel Gadelha O. da Silva\n");
    printf("Professor responsável: Flavius Gorgonio\n");
    printf("UFRN - Universidade Federal do Rio Grande do Norte\n");
}

int main(){
    char opt, opt1;
    sobre();
    
    printf("\nPressione ENTER para continuar...");
    getchar();

    do {
        opt = menu_principal();
        switch(opt) {
            case '1':
                opt1 = menu_receitas();
                switch(opt1) {
                    case '1':
                        printf("Cadastrar receita\n");
                        break;
                    case '2':
                        printf("Editar receita\n");
                        break;
                    case '3':
                        printf("Deletar receita\n");
                        break;
                    case '4':
                        printf("Atualizar receita\n");
                        break;
                    case '5':
                        printf("Pesquisar receita\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida");
                }
                break;
            case '2':
                opt1 = menu_autores();
                switch(opt1) {
                    case '1':
                        printf("Cadastrar autor\n");
                        break;
                    case '2':
                        printf("Editar autor\n");
                        break;
                    case '3':
                        printf("Deletar autor\n");
                        break;
                    case '4':
                        printf("Atualizar autor\n");
                        break;
                    case '5':
                        printf("Pesquisar autor\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida");
                }
                break;
            case '3':
                opt1 = menu_cardapio();
                switch(opt1) {
                    case '1':
                        printf("Cadastrar cardapio\n");
                        break;
                    case '2':
                        printf("Editar cardapio\n");
                        break;
                    case '3':
                        printf("Deletar cardapio\n");
                        break;
                    case '4':
                        printf("Atualizar cardapio\n");
                        break;
                    case '5':
                        printf("Pesquisar cardapio\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida");
                }
            case '0':
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opcao invalida");
        }
    } while(opt != '0');

    return 0;
}