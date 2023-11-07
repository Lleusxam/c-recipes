#include <stdio.h>
#include "autores.h"
#include <string.h>
#include <stdlib.h>
char menu_autores() {
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

int existe_autor(Autor autores[], int quantidade_autores, int id) {
    for (int i = 0; i < quantidade_autores; i++) {
        if (autores[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void cadastrar_autor(Autor autores[], int *quantidade_autores) {
    printf("=============================\n");
    printf("      CADASTRAR AUTOR        \n");
    printf("=============================\n");
    printf("\n");
    char nome[100];
    char telefone[15];
    Autor novo_autor;
    printf("Nome do autor: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string

    printf("Telefone do autor: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strlen(telefone) - 1] = 0;

    // Adicionando o autor na array de autores
    novo_autor.id = *quantidade_autores + 1; // Atribua o ID com base no tamanho atual do vetor
    strncpy(novo_autor.nome, nome, sizeof(novo_autor.nome));
    strncpy(novo_autor.telefone, telefone, sizeof(novo_autor.telefone));
    novo_autor.status = 1;

    autores[*quantidade_autores] = novo_autor;
    (*quantidade_autores)++;

    printf("\nAutor cadastrado com sucesso!\n");

}

void editar_autor(Autor autores[], int quantidade_autores) {
    int id;
    char nome[100];
    char telefone[15];

    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    getchar();
    int index = id - 1;

    int encontrada = existe_autor(autores, quantidade_autores, id);
    if(encontrada == 0) {
        printf("\nAutor não encontrado!\n");
        return;
    }

    printf("=============================\n");
    printf("      EDITAR AUTOR           \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite as novas informações do autor %s:\n", autores[index].nome);
    printf("Novo nome do autor: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = 0; // Remove o \n do final da string

    printf("Novo telefone do autor: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strlen(telefone) - 1] = 0;

    // Atualizando o autor na array de autores
    strncpy(autores[index].nome, nome, sizeof(autores[index].nome));
    strncpy(autores[index].telefone, telefone, sizeof(autores[index].telefone));

    printf("\nAutor atualizado com sucesso!\n");
}

void deletar_autor(Autor autores[], int quantidade_autores) {
    int id;
    printf("=============================\n");
    printf("      DELETAR AUTOR          \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    getchar();
    int index = id - 1;

    int encontrada = existe_autor(autores, quantidade_autores, id);
    if(encontrada == 0) {
        printf("\nAutor não encontrado!\n");
        return;
    }

    autores[index].status = 0;
    printf("\nAutor deletado com sucesso!\n");
}

void pesquisar_autor(Autor autores[], int quantidade_autores) {
    printf("=============================\n");
    printf("      PESQUISAR AUTOR        \n");
    printf("=============================\n");
    printf("\n");
    int id;
    printf("Digite o ID do autor: ");
    scanf("%d", &id);
    getchar();
    int index = id - 1;

    int encontrada = existe_autor(autores, quantidade_autores, id);
    if(encontrada == 0) {
        printf("\nAutor não encontrado!\n");
        return;
    }
    printf("\n");
    printf("Informações do Autor:\n");
    printf("ID: %d\n", autores[index].id);
    printf("Nome: %s\n", autores[index].nome);
    printf("Telefone: %s\n", autores[index].telefone);
    printf("Status: %d\n", autores[index].status);
}