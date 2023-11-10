#include <stdio.h>
#include "cardapio.h"
#include "receitas.h"
#include <string.h>
#include <stdlib.h>
char menu_cardapio() {
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

int contar_cardapios() {
    FILE *arquivo_cardapios;
    int quantidade_cardapios = 0;
    arquivo_cardapios = fopen("cardapios.dat", "rb");
    if (arquivo_cardapios == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Cardapio *cardapio = (Cardapio *) malloc(sizeof(Cardapio));
    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios)) {
        quantidade_cardapios++;
    }
    fclose(arquivo_cardapios);
    free(cardapio);
    return quantidade_cardapios;
}

int existe_cardapio(int id) {
    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb");
    if (arquivo_cardapios == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Cardapio *cardapio = (Cardapio *) malloc(sizeof(Cardapio));
    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios)) {
        if (cardapio->id == id) {
            fclose(arquivo_cardapios);
            free(cardapio);
            return 1;
        }
    }
    fclose(arquivo_cardapios);
    free(cardapio);
    return 0;

}

void cadastrar_cardapio() {
    printf("=============================\n");
    printf("      CADASTRAR CARDAPIO     \n");
    printf("=============================\n");
    printf("\n");
    int entrada;
    int prato_principal;
    int sobremesa;
    Cardapio novo_cardapio;
    printf("Digite o ID da receita que será a Entrada ");
    scanf("%d", &entrada);
    getchar();

    printf("Digite o ID da receita que será o Prato Principal ");
    scanf("%d", &prato_principal);
    getchar();

    printf("Digite o ID da receita que será a Sobremesa ");
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

void editar_cardapio() {
    printf("=============================\n");
    printf("        EDITAR CARDAPIO      \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID do cardápio: ");
    scanf("%d", &id);
    getchar();

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Cardapio cardapio;
    int encontrada = 0;
    while (fread(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios)) {
        if (cardapio.id == id) {
            encontrada = 1;
            break;
        }
    }

    if (encontrada == 0) {
        printf("\nCardapio não encontrado!\n");
        fclose(arquivo_cardapios);
        return;
    }

    printf("\nEscolha o campo que deseja editar:\n");
    printf("1. Entrada\n");
    printf("2. Prato Principal\n");
    printf("3. Sobremesa\n");
    printf("0. Retornar\n");
    printf("Digite sua opção: ");

    int opcao;
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1: {
            int entrada;
            printf("Digite o ID da receita que será a Entrada: ");
            scanf("%d", &entrada);
            getchar();
            cardapio.entrada = entrada;
            break;
        }
        case 2: {
            int prato_principal;
            printf("Digite o ID da receita que será o Prato Principal: ");
            scanf("%d", &prato_principal);
            getchar();
            cardapio.prato_principal = prato_principal;
            break;
        }
        case 3: {
            int sobremesa;
            printf("Digite o ID da receita que será a Sobremesa: ");
            scanf("%d", &sobremesa);
            getchar();
            cardapio.sobremesa = sobremesa;
            break;
        }
        case 0:
            fclose(arquivo_cardapios);
            return;
        default:
            printf("\nOpção inválida!\n");
            fclose(arquivo_cardapios);
            return;
    }

    fseek(arquivo_cardapios, -sizeof(Cardapio), SEEK_CUR);
    fwrite(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios);
    fclose(arquivo_cardapios);

    printf("\nCardapio editado com sucesso!\n");
}



void deletar_cardapio() {
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
    if(encontrada == 0) {
        printf("\nCardapio não encontrado!\n");
        return;
    }

    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "rb+");
    if (arquivo_cardapios == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Cardapio cardapio;
    while (fread(&cardapio, sizeof(Cardapio), 1, arquivo_cardapios)) {
        if (cardapio.id == id) {
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

void pesquisar_cardapio() {
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
    if (arquivo_cardapios == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Cardapio *cardapio = (Cardapio *) malloc(sizeof(Cardapio));

    while (fread(cardapio, sizeof(Cardapio), 1, arquivo_cardapios)) {
        if (cardapio->id == id) {
            printf("\nID: %d\n", cardapio->id);
            printf("Entrada: %d\n", cardapio->entrada);
            printf("Prato Principal: %d\n", cardapio->prato_principal);
            printf("Sobremesa: %d\n", cardapio->sobremesa);
            break;
        }
    }
}


void salvar_cardapio(Cardapio *cardapio) {
    FILE *arquivo_cardapios;
    arquivo_cardapios = fopen("cardapios.dat", "ab");
    // if (arquivo_cardapios == NULL) {
    //     perror("Erro ao abrir o arquivo para escrita");
    //     return;
    // }
    fwrite(cardapio, sizeof(Cardapio), 1, arquivo_cardapios);
    fclose(arquivo_cardapios);
    free(cardapio);
}