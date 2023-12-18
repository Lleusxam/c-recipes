#include <stdio.h>
#include "receitas.h"
#include "autores.h"
#include "validacoes.h"
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
    printf("|   5. Listar receitas      |\n");
    printf("|   6. Pesq. por nome       |\n");
    printf("|   7. Pesq. por categoria  |\n");
    printf("|   8. Pesq. por autor      |\n");
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
    int aux;
    Receita nova_receita;

    FILE *arquivo_autores = fopen("./autores.dat", "rb");
    if(arquivo_autores == NULL) {
        printf("Não há autores cadastrados para atribuir uma receita.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Nome da receita: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string
    uppercase(nome); // Converte a string para maiúscula


    aux = valida_nome(nome);
    if (aux == 0)
    {
        printf("Nome inválido!\n");
        return;
    }

    aux = existe_receita_nome(nome);

    if (aux == 1)
    {
        printf("Nome já cadastrado!\n");
        return;
    }
    
    printf("Descricao da receita: ");
    fgets(descricao, sizeof(descricao), stdin);
    descricao[strlen(descricao) - 1] = 0;
    uppercase(descricao);

    if (strlen(descricao) == 0 || strlen(descricao) > 500)
    {
        printf("Descricao inválida!\n");
        return;
    }


    printf("Porcoes da receita: ");
    scanf("%d", &porcoes);
    limpar_buffer();

    if (porcoes <= 0 || porcoes > 100)
    {
        printf("Quantidade de porcoes inválida!\n");
        return;
    }

    printf("Categoria da receita: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = 0;
    uppercase(categoria);

    aux = valida_nome(categoria);
    
    if (aux == 0 || strlen(categoria) > 50)
    {
        printf("Categoria inválida!\n");
        return;
    }


    printf("Digite o ID do autor da receita: ");
    scanf("%d", &id_autor);
    limpar_buffer();

    aux = existe_autor_id(id_autor);
    if (aux == 0)
    {
        printf("Autor não encontrado!\n");
        return;
    }

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
        if (receita->id == id && receita->status == 1)
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

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para editar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    int id;
    printf("Digite o ID da receita que deseja editar: ");
    scanf("%d", &id);
    limpar_buffer();

    int encontrada = existe_receita(id);
    if (encontrada == 0)
    {
        printf("\nReceita não encontrada!\n");
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
            limpar_buffer();

            switch (opcao)
            {
            case 1:
            {
                char nome[100];
                printf("Digite o novo nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strlen(nome) - 1] = 0;
                uppercase(nome);

                int aux = valida_nome(nome);
                if (aux == 0)
                {
                    printf("Nome inválido!\n");
                    return;
                }

                aux = existe_receita_nome(nome);

                if (aux == 1)
                {
                    printf("Nome já cadastrado!\n");
                    return;
                }

                strncpy(receita.nome, nome, sizeof(receita.nome));
                break;
            }
            case 2:
            {
                char descricao[500];
                printf("Digite a nova descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strlen(descricao) - 1] = 0;
                uppercase(descricao);

                if (strlen(descricao) == 0 || strlen(descricao) > 500)
                {
                    printf("Descricao inválida!\n");
                    return;
                }

                strncpy(receita.descricao, descricao, sizeof(receita.descricao));
                break;
            }
            case 3:
            {
                int porcoes;
                printf("Digite a nova quantidade de porcoes: ");
                scanf("%d", &porcoes);
                limpar_buffer();

                if (porcoes <= 0 || porcoes > 100)
                {
                    printf("Quantidade de porcoes inválida!\n");
                    return;
                }

                receita.porcoes = porcoes;
                break;
            }
            case 4:
            {
                char categoria[50];
                printf("Digite a nova categoria: ");
                fgets(categoria, sizeof(categoria), stdin);
                categoria[strlen(categoria) - 1] = 0;
                uppercase(categoria);

                int aux = valida_nome(categoria);
                if (aux == 0 || strlen(categoria) > 50)
                {
                    printf("Categoria inválida!\n");
                    return;
                }

                strncpy(receita.categoria, categoria, sizeof(receita.categoria));
                break;
            }
            case 5:
            {
                int id_autor;
                printf("Digite o novo ID do autor: ");
                scanf("%d", &id_autor);
                limpar_buffer();
                
                int aux = existe_autor_id(id_autor);
                if (aux == 0)
                {
                    printf("Autor não encontrado!\n");
                    return;
                }

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

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para deletar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o ID da receita que deseja deletar: ");
    scanf("%d", &id);
    limpar_buffer();

    int encontrada = existe_receita(id);
    if (encontrada == 0)
    {
        printf("\nReceita não encontrada!\n");
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
            limpar_buffer();
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

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }
    printf("Digite o ID da receita que deseja pesquisar: ");
    scanf("%d", &id);
    limpar_buffer();
    
    Receita *receita = (Receita *)malloc(sizeof(Receita));

    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (receita->id == id && receita->status == 1)
        {
            char *nome_autor;    
            printf("\n");
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receita->id);
            printf("Nome: %s\n", receita->nome);
            printf("Descricao: %s\n", receita->descricao);
            printf("Porcoes: %d\n", receita->porcoes);
            printf("Categoria: %s\n", receita->categoria);
            nome_autor = buscar_autor(receita->id_autor);
            printf("Autor: %s\n", nome_autor);
            return;
        }
    }
    printf("\nReceita não encontrada!\n");
    fclose(arquivo_receitas);
}

void listar_receitas()
{
    printf("=============================\n");
    printf("        LISTAR RECEITAS      \n");
    printf("=============================\n");
    printf("\n");

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para listar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    Receita *receita = (Receita *)malloc(sizeof(Receita));

    int receita_encontrada = 0;
    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if(receita->status == 1) 
        {
        printf("ID: %d\n", receita->id);
        printf("Nome: %s\n", receita->nome);
        printf("Descricao: %s\n", receita->descricao);
        printf("Porcoes: %d\n", receita->porcoes);
        printf("Categoria: %s\n", receita->categoria);
        char *nome_autor = buscar_autor(receita->id_autor);
        printf("Autor: %s\n", nome_autor);
        printf("\n");
        receita_encontrada = 1;
        }
    }

    if(!receita_encontrada) {
        printf("Não há receitas cadastradas para listar.\n");
    }
    fclose(arquivo_receitas);
}


void salvar_receita(Receita *receita)
{
    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "ab");
    fwrite(receita, sizeof(Receita), 1, arquivo_receitas);
    fclose(arquivo_receitas);
}

char* buscar_receita(int id) {
    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb");
    if (arquivo_receitas == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return NULL;
    }

    Receita *receita = (Receita *)malloc(sizeof(Receita));

    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (receita->id == id)
        {
            char* nome = (char*)malloc(sizeof(char) * 50);
            strcpy(nome, receita->nome);
            fclose(arquivo_receitas);
            free(receita);
            return nome;
        }
    }
    fclose(arquivo_receitas);
    free(receita);
    return NULL;
}

int existe_receita_nome(char* nome) {
    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb");
    if (arquivo_receitas == NULL)
    {
        return 0;
    }

    Receita *receita = (Receita *)malloc(sizeof(Receita));

    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (strcmp(receita->nome, nome) == 0)
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

void pesquisar_receita_nome() {
    printf("=============================\n");
    printf(" PESQUISAR RECEITA POR NOME  \n");
    printf("=============================\n");
    printf("\n");
    char nome[100];

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }
    
    printf("Digite o nome da receita que deseja pesquisar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0;
    uppercase(nome);
    Receita *receita = (Receita *)malloc(sizeof(Receita));

    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (strcmp(receita->nome, nome) == 0 && receita->status == 1)
        {
            char *nome_autor;    
            printf("\n");
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receita->id);
            printf("Nome: %s\n", receita->nome);
            printf("Descricao: %s\n", receita->descricao);
            printf("Porcoes: %d\n", receita->porcoes);
            printf("Categoria: %s\n", receita->categoria);
            nome_autor = buscar_autor(receita->id_autor);
            printf("Autor: %s\n", nome_autor);
            return;
        }
    }
    printf("\nReceita não encontrada!\n");
    fclose(arquivo_receitas);
    free(receita);
}

void pesquisar_receita_categoria() {
    printf("=============================\n");
    printf("PESQUISAR RECEITA POR CATEGORIA\n");
    printf("=============================\n");
    printf("\n");
    char categoria[50];

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite a categoria da receita que deseja pesquisar: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strlen(categoria) - 1] = 0;
    uppercase(categoria);
    
    Receita *receita = (Receita *)malloc(sizeof(Receita));

    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if (strcmp(receita->categoria, categoria) == 0 && receita->status == 1)
        {
            char *nome_autor;    
            printf("\n");
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receita->id);
            printf("Nome: %s\n", receita->nome);
            printf("Descricao: %s\n", receita->descricao);
            printf("Porcoes: %d\n", receita->porcoes);
            printf("Categoria: %s\n", receita->categoria);
            nome_autor = buscar_autor(receita->id_autor);
            printf("Autor: %s\n", nome_autor);
        }
    }
    fclose(arquivo_receitas);
    free(receita);
}

void pesquisar_receita_autor() {
    printf("=============================\n");
    printf("PESQUISAR RECEITA POR AUTOR\n");
    printf("=============================\n");
    printf("\n");
    char nome_autor[50];
    int id_autor;

    FILE *arquivo_receitas;
    arquivo_receitas = fopen("receitas.dat", "rb+");
    if (arquivo_receitas == NULL)
    {
        printf("Não há receitas cadastradas para pesquisar.\n");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }
    
    printf("Digite o nome do autor que deseja pesquisar: ");
    fgets(nome_autor, sizeof(nome_autor), stdin);
    nome_autor[strlen(nome_autor) - 1] = 0;
    uppercase(nome_autor);

    FILE *arquivo_autores;
    arquivo_autores = fopen("autores.dat", "rb");
    if (arquivo_autores == NULL)
    {
        printf("Não há autores cadastrados para pesquisar.");
        printf("Pressione ENTER para continuar\n");
        getchar();
        return;
    }

    Autor *autor = (Autor *)malloc(sizeof(Autor));

    while (fread(autor, sizeof(Autor), 1, arquivo_autores))
    {
        if (strcmp(autor->nome, nome_autor) == 0)
        {
            id_autor = autor->id;
        }
    }

    Receita *receita = (Receita *)malloc(sizeof(Receita));
    int autor_encontrado = 0;
    while (fread(receita, sizeof(Receita), 1, arquivo_receitas))
    {
        if(receita->id_autor == id_autor && receita->status == 1)
        {
            printf("\n");
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receita->id);
            printf("Nome: %s\n", receita->nome);
            printf("Descricao: %s\n", receita->descricao);
            printf("Porcoes: %d\n", receita->porcoes);
            printf("Categoria: %s\n", receita->categoria);
            printf("Autor: %s\n", nome_autor);
            autor_encontrado = 1;
        }
    }
    if (autor_encontrado == 0)
    {
        printf("\nAutor não encontrado ou não possui receitas cadastradas.\n");
    }
    fclose(arquivo_receitas);
    free(receita);
    fclose(arquivo_autores);
    free(autor);
}
