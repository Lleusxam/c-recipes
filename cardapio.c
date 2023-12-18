#include <stdio.h>
#include "cardapio.h"
#include "receitas.h"
#include "validacoes.h"
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
    printf("|   5. Listar cardapios      |\n");
    printf("|   6. Pesquisar por nome    |\n");
    printf("|   0. Retornar              |\n");
    printf("=============================\n");
    printf("\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &opt);
    limpar_buffer();
    printf("\n");
    printf("Pressione ENTER para continuar...");
    limpar_buffer();
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
        if (cardapio->id == id && cardapio->status == 1)
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
    char nome[100];
    int aux;
    Cardapio novo_cardapio;

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para criar um cardápio.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o ID da receita que será a Entrada: ");
    scanf("%d", &entrada);
    limpar_buffer();

    aux = existe_receita(entrada);
    if (aux == 0)
    {
        printf("\nA receita não existe.!\n");
        return;
    }

    printf("Digite o ID da receita que será o Prato Principal: ");
    scanf("%d", &prato_principal);
    limpar_buffer();

    aux = existe_receita(prato_principal);

    if (aux == 0)
    {
        printf("\nA receita não existe.!\n");
        return;
    }

    printf("Digite o ID da receita que será a Sobremesa: ");
    scanf("%d", &sobremesa);
    limpar_buffer();

    aux = existe_receita(sobremesa);

    printf("Digite um nome para identificar o cardapio: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string
    uppercase(nome);

    aux = existe_cardapio_nome(nome);
    if (aux == 1)
    {
        printf("\nJá existe um cardapio com esse nome!\n");
        return;
    }

    int quantidade_cardapios = contar_cardapios();
    novo_cardapio.id = quantidade_cardapios + 1;
    novo_cardapio.entrada = entrada;
    novo_cardapio.prato_principal = prato_principal;
    novo_cardapio.sobremesa = sobremesa;
    strncpy(novo_cardapio.nome, nome, sizeof(novo_cardapio.nome));
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
    int aux;

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        printf("Não há cardápios cadastrados para editar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o ID do cardapio que deseja editar: ");
    scanf("%d", &id);
    limpar_buffer();

    int encontrada = existe_cardapio(id);
    if (encontrada == 0)
    {
        printf("\nCardapio não encontrado!\n");
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
            printf("\n4. Nome");
            printf("\n0. Retornar");
            printf("\nDigite sua escolha: ");
            int opcao;
            scanf("%d", &opcao);
            limpar_buffer();

            switch (opcao)
            {

            case 1:
            {
                printf("Digite o novo ID da receita que será a Entrada: ");
                scanf("%d", &cardapio.entrada);
                limpar_buffer();

                aux = existe_receita(cardapio.entrada);

                if (aux == 0)
                {
                    printf("\nA receita não existe.!\n");
                    return;
                }

                break;
            }

            case 2:
            {
                printf("Digite o novo ID da receita que será o Prato Principal: ");
                scanf("%d", &cardapio.prato_principal);
                limpar_buffer();

                aux = existe_receita(cardapio.prato_principal);

                if (aux == 0)
                {
                    printf("\nA receita não existe.!\n");
                    return;
                }

                break;
            }

            case 3:
            {
                printf("Digite o novo ID da receita que será a Sobremesa: ");
                scanf("%d", &cardapio.sobremesa);
                limpar_buffer();

                aux = existe_receita(cardapio.sobremesa);

                if (aux == 0)
                {
                    printf("\nA receita não existe.!\n");
                    return;
                }

                break;
            }
            case 4:
            {
                printf("Digite um novo nome para identificar o cardapio: ");
                fgets(cardapio.nome, sizeof(cardapio.nome), stdin);
                cardapio.nome[strlen(cardapio.nome) - 1] = 0; // Remove o \n do final da string
                uppercase(cardapio.nome);

                aux = existe_cardapio_nome(cardapio.nome);
                if (aux == 1)
                {
                    printf("\nJá existe um cardapio com esse nome!\n");
                    return;
                }

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

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        printf("Não há cardápios cadastrados para deletar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o ID do cardápio que deseja deletar: ");
    scanf("%d", &id);
    limpar_buffer();

    // Procura o cardápio com o ID especificado
    int encontrada = existe_cardapio(id);
    if (encontrada == 0)
    {
        printf("\nCardapio não encontrado!\n");
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
            limpar_buffer();
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

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        printf("Não há cardápios cadastrados para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o ID do cardápio que deseja pesquisar: ");
    scanf("%d", &id);
    limpar_buffer();

    Cardapio *cardapio = (Cardapio *)malloc(sizeof(Cardapio));

    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (cardapio->id == id && cardapio->status == 1)
        {
            char *entrada = buscar_receita(cardapio->entrada);
            char *prato_principal = buscar_receita(cardapio->prato_principal);
            char *sobremesa = buscar_receita(cardapio->sobremesa);
            printf("\n");
            printf("ID: %d\n", cardapio->id);
            printf("Entrada: %s\n", entrada);
            printf("Prato Principal: %s\n", prato_principal);
            printf("Sobremesa: %s\n", sobremesa);
            return;
        }
    }
    printf("\nCardapio não encontrado!\n");
    fclose(arquivo_cardapios);
}

void listar_cardapios()
{
    printf("=============================\n");
    printf("       LISTAR CARDAPIOS      \n");
    printf("=============================\n");
    printf("\n");

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        printf("Não há cardápios cadastrados para listar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    Cardapio *cardapio = (Cardapio *)malloc(sizeof(Cardapio));

    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (cardapio->status == 1)
        {
            char *entrada = buscar_receita(cardapio->entrada);
            char *prato_principal = buscar_receita(cardapio->prato_principal);
            char *sobremesa = buscar_receita(cardapio->sobremesa);
            printf("\n");
            printf("ID: %d\n", cardapio->id);
            printf("Nome: %s\n", cardapio->nome);
            printf("Entrada: %s\n", entrada);
            printf("Prato Principal: %s\n", prato_principal);
            printf("Sobremesa: %s\n", sobremesa);
        }
    }
    fclose(arquivo_cardapios);
}

void salvar_cardapio(Cardapio *cardapio)
{
    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "ab");
    fwrite(cardapio, sizeof(Cardapio), 1, arquivo_cardapios);
    fclose(arquivo_cardapios);
}


int existe_cardapio_nome(char *nome)
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
        if (strcmp(cardapio->nome, nome) == 0 && cardapio->status == 1)
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

void pesquisar_cardapio_nome()
{
    printf("=============================\n");
    printf("  PESQUISAR CARDAPIO POR NOME\n");
    printf("=============================\n");
    printf("\n");

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL)
    {
        printf("Não há cardápios cadastrados para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    char nome[100];
    printf("Digite o nome do cardápio que deseja pesquisar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string
    uppercase(nome);

    Cardapio *cardapio = (Cardapio *)malloc(sizeof(Cardapio));

    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios))
    {
        if (strcmp(cardapio->nome, nome) == 0 && cardapio->status == 1)
        {
            char *entrada = buscar_receita(cardapio->entrada);
            char *prato_principal = buscar_receita(cardapio->prato_principal);
            char *sobremesa = buscar_receita(cardapio->sobremesa);
            printf("\n");
            printf("ID: %d\n", cardapio->id);
            printf("Entrada: %s\n", entrada);
            printf("Prato Principal: %s\n", prato_principal);
            printf("Sobremesa: %s\n", sobremesa);
            return;
        }
    }
    printf("\nCardapio não encontrado!\n");
    fclose(arquivo_cardapios);
}