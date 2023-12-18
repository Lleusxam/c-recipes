#include <stdio.h>
#include "autores.h"
#include <string.h>
#include <stdlib.h>
#include "validacoes.h"
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
    printf("|   5. Listar autores       |\n");
    printf("|   6. Pesquisar por nome   |\n");
    printf("|   7. Pesq. por telefone   |\n");
    printf("|   8. Pesq. por email      |\n");
    printf("|   0. Retornar             |\n");
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

int contar_autores()
{
    FILE *arquivo_autores;
    int quantidade_autores = 0;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
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
int existe_autor_id(int id)
{
    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        return 0;
    }
    Autor *autor = (Autor *)malloc(sizeof(Autor));
    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor->id == id && autor->status == 1)
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
    char email[50];
    int aux;
    Autor novo_autor;

    printf("Digite o nome do autor de ID %d: ", contar_autores() + 1);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string
    uppercase(nome);

    aux = valida_nome(nome);
    if (aux == 0)
    {
        printf("\nNome inválido!\n");
        return;
    }
    aux = existe_autor_nome(nome);
    if (aux == 1)
    {
        printf("\nJá existe um autor com esse nome. Deseja cadastrar mesmo assim?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        printf("Digite sua escolha: ");
        int opcao;
        scanf("%d", &opcao);
        limpar_buffer();
        if (opcao == 0)
        {
            printf("\nVoltando ao menu principal...\n");
            return;
        }
    }

    printf("Telefone do autor (com DDD): ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strlen(telefone) - 1] = 0;

    aux = valida_telefone(telefone);

    if (aux == 0)
    {
        printf("\nTelefone inválido!\n");
        return;
    }

    aux = existe_telefone(telefone);

    if (aux == 1)
    {
        printf("\nJá existe um autor com esse telefone. Deseja cadastrar mesmo assim?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        printf("Digite sua escolha: ");
        int opcao;
        scanf("%d", &opcao);
        limpar_buffer();
        if (opcao == 0)
        {
            printf("\nVoltando ao menu principal...\n");
            return;
        }
    }

    printf("E-mail do autor: ");
    fgets(email, sizeof(email), stdin);
    email[strlen(email) - 1] = 0;
    aux = existe_email(email);

    if (aux == 1)
    {
        printf("\nJá existe um autor com esse e-mail. Deseja cadastrar mesmo assim?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        printf("Digite sua escolha: ");
        int opcao;
        scanf("%d", &opcao);
        limpar_buffer();
        if (opcao == 0)
        {
            printf("\nVoltando ao menu principal...\n");
            return;
        }
    }

    int quantidade_autores = contar_autores();
    novo_autor.id = quantidade_autores + 1;
    strncpy(novo_autor.nome, nome, sizeof(novo_autor.nome));
    strncpy(novo_autor.telefone, telefone, sizeof(novo_autor.telefone));
    strncpy(novo_autor.email, email, sizeof(novo_autor.email));
    novo_autor.status = 1;

    salvar_autor(&novo_autor);

    printf("\nAutor de ID %d cadastrado com sucesso!\n", novo_autor.id);
}

// Feito com ajuda do GitHub Copilot (https://copilot.github.com/)
void editar_autor()
{
    printf("=============================\n");
    printf("       EDITAR AUTOR          \n");
    printf("=============================\n");
    printf("\n");
    int id;
    int aux;

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para editar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }


    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    limpar_buffer();

    int encontrada = existe_autor_id(id);
    if (encontrada == 0)
    {
        printf("\nAutor não encontrado!\n");
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
            printf("3 - Email\n");
            printf("0 - Retornar\n");
            printf("Digite sua escolha: ");
            int opcao;
            scanf("%d", &opcao);
            limpar_buffer();

            switch (opcao)
            {
            case 1:
                printf("Digite o novo nome do autor de ID %d: ", autor.id);
                fgets(autor.nome, sizeof(autor.nome), stdin);
                autor.nome[strlen(autor.nome) - 1] = 0;
                uppercase(autor.nome);

                aux = valida_nome(autor.nome);
                if (aux == 0)
                {
                    printf("\nNome inválido!\n");
                    fclose(arquivo_autores);
                    return;
                }
                aux = existe_autor_nome(autor.nome);
                if (aux == 1)
                {
                    printf("\nJá existe um autor com esse nome. Deseja cadastrar mesmo assim?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("Digite sua escolha: ");
                    int opcao;
                    scanf("%d", &opcao);
                    limpar_buffer();
                    if (opcao == 0)
                    {
                        printf("\nVoltando ao menu principal...\n");
                        fclose(arquivo_autores);
                        return;
                    }
                }
                break;
            case 2:
                printf("Digite o novo telefone do autor: ");
                fgets(autor.telefone, sizeof(autor.telefone), stdin);
                // autor.telefone[strlen(autor.telefone) - 1] = 0;
                aux = valida_telefone(autor.telefone);

                if (aux == 0)
                {
                    printf("\nTelefone inválido!\n");
                    fclose(arquivo_autores);
                    return;
                }

                aux = existe_telefone(autor.telefone);

                if (aux == 1)
                {
                    printf("\nJá existe um autor com esse telefone. Deseja cadastrar mesmo assim?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("Digite sua escolha: ");
                    int opcao;
                    scanf("%d", &opcao);
                    limpar_buffer();
                    if (opcao == 0)
                    {
                        printf("\nVoltando ao menu principal...\n");
                        fclose(arquivo_autores);
                        return;
                    }
                }
                break;
            case 3:
                printf("Digite o novo email do autor: ");
                fgets(autor.email, sizeof(autor.email), stdin);
                autor.email[strlen(autor.email) - 1] = 0;
                aux = existe_email(autor.email);

                if (aux == 1)
                {
                    printf("\nJá existe um autor com esse e-mail. Deseja cadastrar mesmo assim?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("Digite sua escolha: ");
                    int opcao;
                    scanf("%d", &opcao);
                    limpar_buffer();
                    if (opcao == 0)
                    {
                        printf("\nVoltando ao menu principal...\n");
                        fclose(arquivo_autores);
                        return;
                    }
                }
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

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para deletar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    limpar_buffer();

    int encontrada = existe_autor_id(id);
    if (encontrada == 0)
    {
        printf("\nAutor não encontrado!\n");
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

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    int id;
    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    limpar_buffer();

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    
    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor->id == id && autor->status == 1)
        {
            printf("\n");
            printf("Nome: %s\n", autor->nome);
            printf("Telefone: %s\n", autor->telefone);
            printf("Email: %s\n", autor->email);
            return;
        }
    }

    printf("\nAutor não encontrado!\n");
    fclose(arquivo_autores);
}

void listar_autores()
{
    printf("=============================\n");
    printf("        LISTAR AUTORES       \n");
    printf("=============================\n");
    printf("\n");

   FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para listar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    int autor_encontrado = 0;
    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor->status == 1)
        {
            printf("\n");
            printf("ID: %d\n", autor->id);
            printf("Nome: %s\n", autor->nome);
            printf("Telefone: %s\n", autor->telefone);
            printf("Email: %s\n", autor->email);
            printf("\n");
            autor_encontrado = 1;
        }
    }
    if(!autor_encontrado) {
        printf("Não foram encontrados autores.\n");
    }

    fclose(arquivo_autores);
}


void salvar_autor(Autor *autor)
{
    FILE *arquivo_autores = fopen("autores.dat", "ab");
    fwrite(autor, sizeof(Autor), 1, arquivo_autores);
    fclose(arquivo_autores);
}

char *buscar_autor(int id)
{
    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return NULL;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (autor->id == id)
        {
            fclose(arquivo_autores);
            return autor->nome;
        }
    }

    fclose(arquivo_autores);
    return NULL;
}

int existe_autor_nome(char *nome)
{
    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        return 0;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->nome, nome) == 0)
        {
            fclose(arquivo_autores);
            free(autor);
            return 1;
        }
    }

    fclose(arquivo_autores);
    return 0;
}

int existe_telefone(char *telefone)
{
    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        return 0;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->telefone, telefone) == 0)
        {
            fclose(arquivo_autores);
            free(autor);
            return 1;
        }
    }

    fclose(arquivo_autores);
    return 0;
}

int existe_email(char *email)
{
    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        return 0;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->email, email) == 0)
        {
            fclose(arquivo_autores);
            free(autor);
            return 1;
        }
    }

    fclose(arquivo_autores);
    return 0;
}

void pesquisar_autor_nome()
{
    printf("=============================\n");
    printf("    PESQUISAR AUTOR POR NOME \n");
    printf("=============================\n");
    printf("\n");

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    char nome[50];
    printf("Digite o nome do autor: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0;
    uppercase(nome);

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->nome, nome) == 0 && autor->status == 1)
        {
            printf("\n");
            printf("ID: %d\n", autor->id);
            printf("Nome: %s\n", autor->nome);
            printf("Telefone: %s\n", autor->telefone);
            printf("\n");
            return;
        }
    }

    printf("\nAutor não encontrado!\n");
    fclose(arquivo_autores);
}   

void pesquisar_autor_telefone()
{
    printf("=============================\n");
    printf(" PESQUISAR AUTOR POR TELEFONE\n");
    printf("=============================\n");
    printf("\n");

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    char telefone[15];
    printf("Digite o telefone do autor: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strlen(telefone) - 1] = 0;

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->telefone, telefone) == 0 && autor->status == 1)
        {
            printf("\n");
            printf("ID: %d\n", autor->id);
            printf("Nome: %s\n", autor->nome);
            printf("Telefone: %s\n", autor->telefone);
            printf("\n");
            return;
        }
    }

    printf("\nAutor não encontrado!\n");
    fclose(arquivo_autores);
}

void pesquisar_autor_email()
{
    printf("=============================\n");
    printf("   PESQUISAR AUTOR POR EMAIL \n");
    printf("=============================\n");
    printf("\n");

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "r+b");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    char email[50];
    printf("Digite o email do autor: ");
    fgets(email, sizeof(email), stdin);
    email[strlen(email) - 1] = 0;

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->email, email) == 0 && autor->status == 1)
        {
            printf("\n");
            printf("ID: %d\n", autor->id);
            printf("Nome: %s\n", autor->nome);
            printf("Telefone: %s\n", autor->telefone);
            printf("\n");
            return;
        }
    }

    printf("\nAutor não encontrado!\n");
    fclose(arquivo_autores);
}