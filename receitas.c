#include <stdio.h>
#include "receitas.h"
#include "autores.h"
#include <string.h>
#include <stdlib.h>

char menu_receitas() {
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

int contar_receitas() {
    FILE *arquivo;
    int quantidade_receitas = 0;
    arquivo = fopen("receitas.dat", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Receita *receita = (Receita *) malloc(sizeof(Receita));
    while (fread(receita, sizeof(Receita), 1, arquivo)) {
        quantidade_receitas++;
    }
    fclose(arquivo);
    free(receita);
    return quantidade_receitas;

}

void cadastrar_receita() {
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

int existe_receita(int id) {
    FILE *arquivo;
    arquivo = fopen("receitas.dat", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    Receita *receita = (Receita *) malloc(sizeof(Receita));
    while (fread(receita, sizeof(Receita), 1, arquivo)) {
        if (receita->id == id) {
            fclose(arquivo);
            free(receita);
            return 1;
        }
    }
    fclose(arquivo);
    free(receita);
    return 0;
}


// Feito com ajuda do GitHub Copilot (https://copilot.github.com/)
void editar_receita() {
    int id;
    printf("=============================\n");
    printf("       EDITAR RECEITA        \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o ID da receita que deseja editar: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_receita(id);
    if(encontrada == 0) {
        printf("\nReceita não encontrada!");
        return;
    }

    FILE *arquivo;
    arquivo = fopen("receitas.dat", "rb+");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Receita receita;
    while (fread(&receita, sizeof(Receita), 1, arquivo)) {
        if (receita.id == id) {
            printf("\nQual campo deseja editar? (nome, descricao, porcoes, categoria, autor): ");
            char campo[20];
            fgets(campo, sizeof(campo), stdin);
            campo[strlen(campo) - 1] = 0;

            if (strcmp(campo, "nome") == 0) {
                printf("\nDigite o novo nome: ");
                char novo_nome[100];
                fgets(novo_nome, sizeof(novo_nome), stdin);
                novo_nome[strlen(novo_nome) - 1] = 0;
                strncpy(receita.nome, novo_nome, sizeof(receita.nome));
            } else if (strcmp(campo, "descricao") == 0) {
                printf("\nDigite a nova descricao: ");
                char nova_descricao[500];
                fgets(nova_descricao, sizeof(nova_descricao), stdin);
                nova_descricao[strlen(nova_descricao) - 1] = 0;
                strncpy(receita.descricao, nova_descricao, sizeof(receita.descricao));
            } else if (strcmp(campo, "porcoes") == 0) {
                printf("\nDigite a nova quantidade de porcoes: ");
                int nova_porcoes;
                scanf("%d", &nova_porcoes);
                getchar();
                receita.porcoes = nova_porcoes;
            } else if (strcmp(campo, "categoria") == 0) {
                printf("\nDigite a nova categoria: ");
                char nova_categoria[50];
                fgets(nova_categoria, sizeof(nova_categoria), stdin);
                nova_categoria[strlen(nova_categoria) - 1] = 0;
                strncpy(receita.categoria, nova_categoria, sizeof(receita.categoria));
            } else if (strcmp(campo, "autor") == 0) {
                printf("\nDigite o novo ID do autor: ");
                int novo_id_autor;
                scanf("%d", &novo_id_autor);
                getchar();
                receita.id_autor = novo_id_autor;
            } else {
                printf("\nCampo inválido!");
                return;
            }

            fseek(arquivo, -sizeof(Receita), SEEK_CUR);
            fwrite(&receita, sizeof(Receita), 1, arquivo);
            fclose(arquivo);
            printf("\nReceita editada com sucesso!\n");
            return;
        }
    }

    fclose(arquivo);
}



void deletar_receita() {
    int id;
    printf("=============================\n");
    printf("       DELETAR RECEITA       \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite o ID da receita que deseja deletar: ");
    scanf("%d", &id);
    getchar();

    int encontrada = existe_receita(id);
    if(encontrada == 0) {
        printf("\nReceita não encontrada!");
        return;
    }

    FILE *arquivo;
    arquivo = fopen("receitas.dat", "rb+");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Receita receita;
    while (fread(&receita, sizeof(Receita), 1, arquivo)) {
        if (receita.id == id) {
            receita.status = 0;
            fseek(arquivo, -sizeof(Receita), SEEK_CUR);
            fwrite(&receita, sizeof(Receita), 1, arquivo);
            fclose(arquivo);
            printf("\nReceita deletada com sucesso!\n");
            printf("Pressione ENTER para continuar...");
            getchar();
            return;
        }
    }

    fclose(arquivo);
}

void pesquisar_receita() {
    printf("=============================\n");
    printf("      PESQUISAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");

    int id;
    printf("Digite o ID da receita que deseja pesquisar: ");
    scanf("%d", &id);
    getchar();

    FILE *arquivo;
    arquivo = fopen("receitas.dat", "rb");  
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }
    Receita *receita = (Receita *) malloc(sizeof(Receita));
    
    while (fread(receita, sizeof(Receita), 1, arquivo)) {
        if (receita->id == id) {
            printf("\n");
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receita->id);
            printf("Nome: %s\n", receita->nome);
            printf("Descricao: %s\n", receita->descricao);
            printf("Porcoes: %d\n", receita->porcoes);
            printf("Categoria: %s\n", receita->categoria);
            printf("Status: %d\n", receita->status);
            printf("Autor: %d\n", receita->id_autor);
            break;
        }
    }

}
void salvar_receita(Receita *receita) {
    FILE *arquivo;
    arquivo = fopen("receitas.dat", "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    fwrite(receita, sizeof(Receita), 1, arquivo);
    fclose(arquivo);
    free(receita);
}