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
    Autor autores[100];
    int quantidade_autores = 0;
    Cardapio cardapios[100];
    int quantidade_cardapios = 0;
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
                        cadastrar_receita();
                        break;
                    case '2':
                        editar_receita();
                        break;
                    case '3':
                        deletar_receita();
                        getchar();
                        break;
                    case '4':
                        pesquisar_receita();
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
                        cadastrar_autor(autores, &quantidade_autores);
                        break;
                    case '2':
                        editar_autor(autores, quantidade_autores);
                        break;
                    case '3':
                        deletar_autor(autores, quantidade_autores);
                        break;
                    case '4':
                        pesquisar_autor(autores, quantidade_autores);
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
                        cadastrar_cardapio(cardapios, &quantidade_cardapios);
                        break;
                    case '2':
                        editar_cardapio(cardapios, quantidade_cardapios);
                        break;
                    case '3':
                        deletar_cardapio(cardapios, quantidade_cardapios);
                        break;
                    case '4':
                        // pesquisar_cardapio(cardapios, quantidade_cardapios, receitas, quantidade_receitas);
                        // Temporariamente desativado
                        getchar();
                        break;
                    case '0':
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;
            case '4':
                opt1 = menu_ingredientes();
                switch(opt1) {
                    case '1':
                       cadastrar_ingrediente();
                        break;
                    case '2':
                        editar_ingrediente();
                        break;
                    case '3':
                        deletar_ingrediente();
                        break;
                    case '4':
                        pesquisar_ingrediente();
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