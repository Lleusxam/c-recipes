#include <stdio.h>
#include <stdlib.h>
#include "receitas.h"
#include "autores.h"
#include "cardapio.h"
#include "ingredientes.h"

char menu_principal() {
    char opt;
    printf("=============================\n");
    printf("        MENU PRINCIPAL       \n");
    printf("=============================\n");
    printf("|   1. Menu de Receitas     |\n");
    printf("|   2. Menu de Autores      |\n");
    printf("|   3. Menu de Cardapio     |\n");
    printf("|   4. Menu de Ingredientes |\n");
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
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '2':
                        printf("Editar receita\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '3':
                        printf("Deletar receita\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '4':
                        printf("Atualizar receita\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '5':
                        printf("Pesquisar receita\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;
            case '2':
                opt1 = menu_autores();
                switch(opt1) {
                    case '1':
                        printf("Cadastrar autor\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '2':
                        printf("Editar autor\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '3':
                        printf("Deletar autor\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '4':
                        printf("Atualizar autor\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '5':
                        printf("Pesquisar autor\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;
            case '3':
                opt1 = menu_cardapio();
                switch(opt1) {
                    case '1':
                        printf("Cadastrar cardapio\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '2':
                        printf("Editar cardapio\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '3':
                        printf("Deletar cardapio\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '4':
                        printf("Atualizar cardapio\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '5':
                        printf("Pesquisar cardapio\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                break;
                }
            case '4':
                opt1 = menu_ingredientes();
                switch(opt1) {
                    case '1':
                        printf("Cadastrar ingrediente\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '2':
                        printf("Editar ingrediente\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '3':
                        printf("Deletar ingrediente\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '4':
                        printf("Atualizar ingrediente\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '5':
                        printf("Pesquisar ingrediente\n");
                        printf("EM CONSTRUCAO\n");
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;
            case '0':
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while(opt != '0');

    return 0;
}