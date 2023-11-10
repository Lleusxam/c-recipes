#include <stdio.h>
#include "cardapio.h"
#include "receitas.h"
#include <string.h>
#include <stdlib.h>
char menu_cardapio()
{
    char opt;
    printf("=============================\n");
    printf("        MENU CARDAPIO         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar cardapio    |\n");
    printf("|   2. Editar cardapio       |\n");
    printf("|   3. Deletar cardapio      |\n");
    printf("|   4. Pesquisar cardapio    |\n");
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

int contar_cardapios()
{
    FILE *arquivo_cardapios;
    int quantidade_cardapios = 0;
    arquivo_cardapios = fopen("cardapios.dat", "rb");
    if (arquivo_cardapios == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        printf("Gerando novo arquivo...\n");
        return 0;
    }
    Cardapio *cardapio = (Cardapio *)malloc(sizeof(Cardapio));
    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        quantidade_cardapios++;
    }
    fclose(arquivo_cardapios);
    free(cardapio);
    return quantidade_cardapios;
}

int existe_cardapio(int id)
{
    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb");
    if (arquivo_cardapios == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Cardapio *cardapio = (Cardapio *)malloc(sizeof(Cardapio));
    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (cardapio->id == id)
        {
            fclose(arquivo_cardapios);
            free(cardapio);
            return 1;
        }
    }
    fclose(arquivo_cardapios);
    free(cardapio);
    return 0;
}

void cadastrar_cardapio()
{
    printf("=============================\n");
    printf("      CADASTRAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
    int entrada;
    int prato_principal;
    int sobremesa;
    Cardapio novo_cardapio;
    printf("Digite o ID da receita que será a Entrada: ");
    scanf("%d", &entrada);
    getchar();

    printf("Digite o ID da receita que será o Prato Principal: ");
    scanf("%d", &prato_principal);
    getchar();

    printf("Digite o ID da receita que será a Sobremesa: ");
    scanf("%d", &sobremesa);
    getchar();

    int quantidade_cardapios = contar_cardapios();
    novo_cardapio.id = quantidade_cardapios + 1;
    novo_cardapio.entrada = entrada;
    novo_cardapio.prato_principal = prato_principal;
    novo_cardapio.sobremesa = sobremesa;
    novo_cardapio.status = 1;

    salvar_cardapio(&novo_cardapio);

    printf("\nCardapio cadastrado com sucesso!\n");
}

// Feito com ajuda do GitHub Copilot (https://copilot.github.com/)
void editar_cardapio()
{
    printf("=============================\n");
    printf("       EDITAR CARDAPIO       \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID do cardapio que deseja editar: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_cardapio(id);
    if (encontrada == 0)
    {
        printf("\nCardapio não encontrado!\n");
        return;
    }

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Cardapio cardapio;
    while (fread(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (cardapio.id == id)
        {
            printf("\nQual campo deseja editar?");
            printf("\n1. Entrada");
            printf("\n2. Prato Principal");
            printf("\n3. Sobremesa");
            printf("\n0. Retornar");
            printf("\nDigite sua escolha: ");
            int opcao;
            scanf("%d", &opcao);
            getchar();

            switch (opcao)
            {

            case 1:
            {
                printf("Digite o novo ID da receita que será a Entrada: ");
                scanf("%d", &cardapio.entrada);
                getchar();
                break;
            }

            case 2:
            {
                printf("Digite o novo ID da receita que será o Prato Principal: ");
                scanf("%d", &cardapio.prato_principal);
                getchar();
                break;
            }

            case 3:
            {
                printf("Digite o novo ID da receita que será a Sobremesa: ");
                scanf("%d", &cardapio.sobremesa);
                getchar();
                break;
            }

            case 0:
            {
                printf("\nVoltando ao menu principal...\n");
                fclose(arquivo_cardapios);
                return;
            }

            default:
            {
                printf("\nOpcao invalida\n");
                fclose(arquivo_cardapios);
                return;
            }
            }

            fseek(arquivo_cardapios, -sizeof(Cardapio), SEEK_CUR);
            fwrite(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios);
            fclose(arquivo_cardapios);
            printf("\nCardapio editado com sucesso!\n");
            return;
        }
    }

    fclose(arquivo_cardapios);
}

void deletar_cardapio()
{
    int id;
    printf("=============================\n");
    printf("       DELETAR CARDAPIO      \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite o ID do cardápio que deseja deletar: ");
    scanf("%d", &id);
    getchar();

    // Procura o cardápio com o ID especificado
    int encontrada = existe_cardapio(id);
    if (encontrada == 0)
    {
        printf("\nCardapio não encontrado!\n");
        return;
    }

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Cardapio cardapio;
    while (fread(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (cardapio.id == id)
        {
            cardapio.status = 0;
            fseek(arquivo_cardapios, -sizeof(Cardapio), SEEK_CUR);
            fwrite(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios);
            fclose(arquivo_cardapios);
            printf("\nCardapio deletado com sucesso!\n");
            printf("Pressione ENTER para continuar...");
            getchar();
            return;
        }
    }
}

void pesquisar_cardapio()
{
    printf("=============================\n");
    printf("      PESQUISAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID do cardápio que deseja pesquisar: ");
    scanf("%d", &id);
    getchar();

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb");
    if (arquivo_cardapios == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Cardapio *cardapio = (Cardapio *)malloc(sizeof(Cardapio));

    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (cardapio->id == id)
        {
            printf("\nID: %d\n", cardapio->id);
            printf("Entrada: %d\n", cardapio->entrada);
            printf("Prato Principal: %d\n", cardapio->prato_principal);
            printf("Sobremesa: %d\n", cardapio->sobremesa);
            return;
        }
    }
    printf("\nCardapio não encontrado!\n");
    fclose(arquivo_cardapios);
}

void salvar_cardapio(Cardapio *cardapio)
{
    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "ab");
    fwrite(cardapio, sizeof(Cardapio), 1, arquivo_cardapios);
    fclose(arquivo_cardapios);
    free(cardapio);
}