#include <stdio.h>
#include "autores.h"
#include <string.h>
#include <stdlib.h>
char menu_autores()
{
    char opt;
    printf("=============================\n");
    printf("        MENU AUTORES         \n");
    printf("=============================\n");
    printf("|   1. Cadastrar autor      |\n");
    printf("|   2. Editar autor         |\n");
    printf("|   3. Deletar autor        |\n");
    printf("|   4. Pesquisar autor      |\n");
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

int contar_autores()
{
    FILE *arquivo_autores;
    int quantidade_autores = 0;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        printf("Gerando novo arquivo...\n");
        return 0;
    }
    Autor *autor = (Autor *)malloc(sizeof(Autor));
    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        quantidade_autores++;
    }
    fclose(arquivo_autores);
    free(autor);
    return quantidade_autores;
}

// Feito com ajuda do GitHub Copilot (https://copilot.github.com/)
int existe_autor(int id)
{
    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Autor *autor = (Autor *)malloc(sizeof(Autor));
    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor->id == id)
        {
            fclose(arquivo_autores);
            free(autor);
            return 1;
        }
    }
    fclose(arquivo_autores);
    free(autor);
    return 0;
}

void cadastrar_autor()
{
    printf("=============================\n");
    printf("      CADASTRAR AUTOR        \n");
    printf("=============================\n");
    printf("\n");
    char nome[50];
    char telefone[15];
    Autor novo_autor;

    printf("Nome do autor: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string

    printf("Telefone do autor: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strlen(telefone) - 1] = 0;

    int quantidade_autores = contar_autores();
    novo_autor.id = quantidade_autores + 1;
    strncpy(novo_autor.nome, nome, sizeof(novo_autor.nome));
    strncpy(novo_autor.telefone, telefone, sizeof(novo_autor.telefone));
    novo_autor.status = 1;

    salvar_autor(&novo_autor);

    printf("\nAutor cadastrado com sucesso!\n");
}

void editar_autor()
{
    int id;
    printf("=============================\n");
    printf("       EDITAR AUTOR          \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_autor(id);
    if (encontrada == 0)
    {
        printf("\nAutor não encontrado!\n");
        return;
    }

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura e escrita");
        return;
    }

    Autor autor;
    while (fread(&autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor.id == id)
        {
            printf("\nQual campo deseja editar?\n");
            printf("1 - Nome\n");
            printf("2 - Telefone\n");
            printf("0 - Retornar\n");
            printf("Digite sua escolha: ");
            int opcao;
            scanf("%d", &opcao);
            getchar();

            switch (opcao)
            {
            case 1:
                printf("Digite o novo nome do autor: ");
                fgets(autor.nome, sizeof(autor.nome), stdin);
                autor.nome[strlen(autor.nome) - 1] = 0;
                break;
            case 2:
                printf("Digite o novo telefone do autor: ");
                fgets(autor.telefone, sizeof(autor.telefone), stdin);
                autor.telefone[strlen(autor.telefone) - 1] = 0;
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                fclose(arquivo_autores);
                return;
            default:
                printf("\nOpção inválida!\n");
                fclose(arquivo_autores);
                return;
            }

            fseek(arquivo_autores, -sizeof(Autor), SEEK_CUR);
            fwrite(&autor, sizeof(Autor), 1, arquivo_autores);
            printf("\nAutor editado com sucesso!\n");
            fclose(arquivo_autores);
            return;
        }
    }

    fclose(arquivo_autores);
}

void deletar_autor()
{
    int id;
    printf("=============================\n");
    printf("       DELETAR AUTOR         \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_autor(id);
    if (encontrada == 0)
    {
        printf("\nAutor não encontrado!\n");
        return;
    }

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura e escrita");
        return;
    }

    Autor autor;
    while (fread(&autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor.id == id)
        {
            autor.status = 0;
            fseek(arquivo_autores, -sizeof(Autor), SEEK_CUR);
            fwrite(&autor, sizeof(Autor), 1, arquivo_autores);
            printf("\nAutor deletado com sucesso!\n");
            fclose(arquivo_autores);
            return;
        }
    }

    fclose(arquivo_autores);
}

void pesquisar_autor()
{
    printf("=============================\n");
    printf("      PESQUISAR AUTOR        \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    getchar();

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor->id == id)
        {
            printf("\n");
            printf("Nome: %s\n", autor->nome);
            printf("Telefone: %s\n", autor->telefone);
            printf("Status %d\n", autor->status);
            return;
        }
    }

    printf("\nAutor não encontrado!\n");
    fclose(arquivo_autores);
}

void salvar_autor(Autor *autor)
{
    FILE *arquivo_autores = fopen("autores.dat", "ab");
    fwrite(autor, sizeof(Autor), 1, arquivo_autores);
    fclose(arquivo_autores);
}