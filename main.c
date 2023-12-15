#include <stdio.h>
#include <stdlib.h>
#include "receitas.h"
#include "autores.h"
#include "cardapio.h"
#include "validacoes.h"

char menu_principal()
{
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

void sobre()
{
    printf("\nO CRecipes é um projeto educacional feito em linguagem C com o intuito de funcionar como um caderno de receitas\n");
    printf("Desenvolvedor: Maxsuel Gadelha O. da Silva\n");
    printf("Professor responsável: Flavius Gorgonio\n");
    printf("UFRN - Universidade Federal do Rio Grande do Norte\n");
}

int main()
{
    char opt, opt1;
    sobre();

    printf("\nPressione ENTER para continuar...");
    limpar_buffer();

    do
    {
        opt = menu_principal();
        switch (opt)
        {
        case '1':
            opt1 = menu_receitas();
            switch (opt1)
            {
            case '1':
                cadastrar_receita();
                break;
            case '2':
                editar_receita();
                break;
            case '3':
                deletar_receita();
                break;
            case '4':
                pesquisar_receita();
                break;
            case '5':
                listar_receitas();
                break;
            case '6':
                pesquisar_receita_nome();
                break;
            case '7':
                pesquisar_receita_categoria();
                break;
            case '8':
                pesquisar_receita_autor();
                break;
            case '0':
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida\n");
                limpar_buffer();
            }
            break;
        case '2':
            opt1 = menu_autores();
            switch (opt1)
            {
            case '1':
                cadastrar_autor();
                break;
            case '2':
                editar_autor();
                break;
            case '3':
                deletar_autor();
                break;
            case '4':
                pesquisar_autor();
                break;
            case '5':
                listar_autores();
            case '0':
                printf("Voltando ao menu principal...\n");
                break;
            case '6':
                pesquisar_autor_nome();
                break;
            case '7':
                pesquisar_autor_telefone();
                break;
            case '8':
                pesquisar_autor_email();
                break;
            default:
                printf("Opcao invalida\n");
                limpar_buffer();
            }
            break;
        case '3':
            opt1 = menu_cardapio();
            switch (opt1)
            {
            case '1':
                cadastrar_cardapio();
                break;
            case '2':
                editar_cardapio();
                break;
            case '3':
                deletar_cardapio();
                break;
            case '4':
                pesquisar_cardapio();
                break;
            case '5':
                listar_cardapios();
                break;
            case '6':
                pesquisar_cardapio_nome();
                break;
            case '0':
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida\n");
                limpar_buffer();
            }
            break;
        case '0':
            printf("Finalizando o programa...\n");
            break;
        default:
            printf("Opcao invalida\n");
            limpar_buffer();
        }
    } while (opt != '0');

    return 0;
}