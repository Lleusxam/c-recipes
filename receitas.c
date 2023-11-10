#include <stdio.h>
#include "receitas.h"
#include "autores.h"
#include <string.h>
#include <stdlib.h>

char menu_receitas()
{
    char opt;
    printf("=============================\n");
    printf("        MENU RECEITAS        \n");
    printf("=============================\n");
    printf("|   1. Cadastrar receita    |\n");
    printf("|   2. Editar receita       |\n");
    printf("|   3. Deletar receita      |\n");
    printf("|   4. Pesquisar receita    |\n");
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

int contar_receitas()
{
    FILE *arquivo_receitas;
    int quantidade_receitas = 0;
    arquivo_receitas = fopen("receitas.dat", "rb");
    if (arquivo_receitas == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        printf("Gerando novo arquivo...\n");
        return 0;
    }
    Receita *receita = (Receita *)malloc(sizeof(Receita));
    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        quantidade_receitas++;
    }
    fclose(arquivo_receitas);
    free(receita);
    return quantidade_receitas;
}

void cadastrar_receita()
{
    printf("=============================\n");
    printf("      CADASTRAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
    int id_autor;
    Receita nova_receita;
    printf("Nome da receita: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string

    printf("Descricao da receita: ");
    fgets(descricao, sizeof(descricao), stdin);
    descricao[strlen(descricao) - 1] = 0;

    printf("Porcoes da receita: ");
    scanf("%d", &porcoes);
    getchar();

    printf("Categoria da receita: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = 0;

    printf("Digite o ID do autor da receita: ");
    scanf("%d", &id_autor);
    getchar();

    int quantidade_receitas = contar_receitas();
    nova_receita.id = quantidade_receitas + 1;
    strncpy(nova_receita.nome, nome, sizeof(nova_receita.nome));
    strncpy(nova_receita.descricao, descricao, sizeof(nova_receita.descricao));
    nova_receita.porcoes = porcoes;
    strncpy(nova_receita.categoria, categoria, sizeof(nova_receita.categoria));
    nova_receita.id_autor = id_autor;
    nova_receita.status = 1;

    salvar_receita(&nova_receita);

    printf("\nReceita cadastrada com sucesso!\n");
}

int existe_receita(int id)
{
    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb");
    if (arquivo_receitas == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Receita *receita = (Receita *)malloc(sizeof(Receita));
    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (receita->id == id)
        {
            fclose(arquivo_receitas);
            free(receita);
            return 1;
        }
    }
    fclose(arquivo_receitas);
    free(receita);
    return 0;
}

// Feito com ajuda do GitHub Copilot (https://copilot.github.com/)
void editar_receita()
{
    printf("=============================\n");
    printf("       EDITAR RECEITA        \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID da receita que deseja editar: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_receita(id);
    if (encontrada == 0)
    {
        printf("\nReceita não encontrada!\n");
        return;
    }

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Receita receita;
    while (fread(&receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (receita.id == id)
        {
            printf("\nQual campo deseja editar?");
            printf("\n1. Nome");
            printf("\n2. Descricao");
            printf("\n3. Porcoes");
            printf("\n4. Categoria");
            printf("\n5. Autor");
            printf("\n0. Retornar");
            printf("\nDigite sua escolha: ");
            int opcao;
            scanf("%d", &opcao);
            getchar();

            switch (opcao)
            {
            case 1:
            {
                char nome[100];
                printf("Digite o novo nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strlen(nome) - 1] = 0;
                strncpy(receita.nome, nome, sizeof(receita.nome));
                break;
            }
            case 2:
            {
                char descricao[500];
                printf("Digite a nova descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strlen(descricao) - 1] = 0;
                strncpy(receita.descricao, descricao, sizeof(receita.descricao));
                break;
            }
            case 3:
            {
                int porcoes;
                printf("Digite a nova quantidade de porcoes: ");
                scanf("%d", &porcoes);
                getchar();
                receita.porcoes = porcoes;
                break;
            }
            case 4:
            {
                char categoria[50];
                printf("Digite a nova categoria: ");
                fgets(categoria, sizeof(categoria), stdin);
                categoria[strlen(categoria) - 1] = 0;
                strncpy(receita.categoria, categoria, sizeof(receita.categoria));
                break;
            }
            case 5:
            {
                int id_autor;
                printf("Digite o novo ID do autor: ");
                scanf("%d", &id_autor);
                getchar();
                receita.id_autor = id_autor;
                break;
            }
            case 0:
            {
                printf("\nVoltando ao menu principal...\n");
                fclose(arquivo_receitas);
                return;
            }
            default:
            {
                printf("Opcao invalida\n");
                return;
            }
            }

            fseek(arquivo_receitas, -sizeof(Receita), SEEK_CUR);
            fwrite(&receita, sizeof(Receita), 1, arquivo_receitas);
            fclose(arquivo_receitas);
            printf("\nReceita editada com sucesso!\n");
            return;
        }
    }

    fclose(arquivo_receitas);
}

void deletar_receita()
{
    int id;
    printf("=============================\n");
    printf("       DELETAR RECEITA       \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite o ID da receita que deseja deletar: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_receita(id);
    if (encontrada == 0)
    {
        printf("\nReceita não encontrada!\n");
        return;
    }

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Receita receita;
    while (fread(&receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (receita.id == id)
        {
            receita.status = 0;
            fseek(arquivo_receitas, -sizeof(Receita), SEEK_CUR);
            fwrite(&receita, sizeof(Receita), 1, arquivo_receitas);
            fclose(arquivo_receitas);
            printf("\nReceita deletada com sucesso!\n");
            printf("Pressione ENTER para continuar...");
            getchar();
            return;
        }
    }

    fclose(arquivo_receitas);
}

void pesquisar_receita()
{
    printf("=============================\n");
    printf("      PESQUISAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID da receita que deseja pesquisar: ");
    scanf("%d", &id);
    getchar();

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb");
    if (arquivo_receitas == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }
    Receita *receita = (Receita *)malloc(sizeof(Receita));

    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (receita->id == id)
        {
            printf("\n");
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receita->id);
            printf("Nome: %s\n", receita->nome);
            printf("Descricao: %s\n", receita->descricao);
            printf("Porcoes: %d\n", receita->porcoes);
            printf("Categoria: %s\n", receita->categoria);
            printf("Status: %d\n", receita->status);
            printf("Autor: %d\n", receita->id_autor);
            return;
        }
    }
    printf("\nReceita não encontrada!\n");
    fclose(arquivo_receitas);
}
void salvar_receita(Receita *receita)
{
    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "ab");
    fwrite(receita, sizeof(Receita), 1, arquivo_receitas);
    fclose(arquivo_receitas);
    free(receita);
}