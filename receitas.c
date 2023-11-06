#include <stdio.h>
#include "receitas.h"
#include <string.h>
#include <stdlib.h>
static int ultimo_id = 0;

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


void cadastrar_receita(Receita receitas[], int *quantidade_receitas) {
    printf("=============================\n");
    printf("      CADASTRAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
    Receita nova_receita;
    printf("Nome da receita: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Descricao da receita: ");
    fgets(descricao, sizeof(descricao), stdin);

    printf("Porcoes da receita: ");
    scanf("%d", &porcoes);
    getchar();

    printf("Categoria da receita: ");
    fgets(categoria, sizeof(categoria), stdin);


    // Adicionando a receita na array de receitas
    nova_receita.id = *quantidade_receitas + 1; // Atribua o ID com base no tamanho atual do vetor
    strncpy(nova_receita.nome, nome, sizeof(nova_receita.nome));
    strncpy(nova_receita.descricao, descricao, sizeof(nova_receita.descricao));
    nova_receita.porcoes = porcoes;
    strncpy(nova_receita.categoria, categoria, sizeof(nova_receita.categoria));
    nova_receita.status = 1;

    receitas[*quantidade_receitas] = nova_receita;
    (*quantidade_receitas)++;


    printf("\nReceita cadastrada com sucesso!\n");

}

int existe_receita(Receita receitas[], int quantidade_receitas, int id) {
    
    for (int i = 0; i < quantidade_receitas; i++) {
        if (receitas[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void editar_receita(Receita receitas[], int quantidade_receitas) {
    int id;
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
    Receita nova_receita;
    printf("Digite o ID da receita que deseja editar: ");
    scanf("%d", &id);
    while (getchar() != '\n');
    int index = id - 1;

    int encontrada = existe_receita(receitas, quantidade_receitas, id);
    if(encontrada == 0) {
        printf("\nReceita não encontrada!\n");
        return;
    }

    printf("=============================\n");
    printf("        EDITAR RECEITA       \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite as novas informações para a receita (ID: %d):\n", id);
    printf("Novo nome da receita: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Nova descricao da receita: ");
    fgets(descricao, sizeof(descricao), stdin);

    printf("Nova quantidade de porcoes da receita: ");
    scanf("%d", &porcoes);
    getchar();

    printf("Nova categoria da receita: ");
    fgets(categoria, sizeof(categoria), stdin);

    // Atualizando a receita na array de receitas
    receitas[index].id = id;
    strncpy(receitas[index].nome, nome, sizeof(receitas[index].nome));
    strncpy(receitas[index].descricao, descricao, sizeof(receitas[index].descricao));
    receitas[index].porcoes = porcoes;
    strncpy(receitas[index].categoria, categoria, sizeof(receitas[index].categoria));
    receitas[index].status = 1;

    printf("\nReceita editada com sucesso!\n");
}

void deletar_receita(Receita receitas[], int quantidade_receitas) {
    int id;
    int index;
    printf("=============================\n");
    printf("       DELETAR RECEITA       \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o ID da receita que deseja deletar: ");
    scanf("%d", &id);
    getchar();
    index = id - 1;

    int encontrada = existe_receita(receitas, quantidade_receitas, id);
    if(encontrada == 0) {
        printf("\nReceita não encontrada!");
        return;
    }
    receitas[index].status = 0;
    printf("\nReceita deletada com sucesso!");

}

void pesquisar_receita(Receita receitas[], int quantidade_receitas) {
    int id;
    printf("=============================\n");
    printf("      PESQUISAR RECEITA      \n");
    printf("=============================\n");
    printf("\n");

    printf("Digite o ID da receita que deseja pesquisar: ");
    scanf("%d", &id);
    getchar();

    // Procura a receita com o ID especificado
    for (int i = 0; i < quantidade_receitas; i++) {
        if (receitas[i].id == id) {
            printf("Informações da Receita:\n");
            printf("ID: %d\n", receitas[i].id);
            printf("Nome: %s\n", receitas[i].nome);
            printf("Descrição: %s\n", receitas[i].descricao);
            printf("Porções: %d\n", receitas[i].porcoes);
            printf("Categoria: %s\n", receitas[i].categoria);
            printf("Status: %d\n", receitas[i].status);
            return; 
        }
    }
    printf("Receita com ID %d não encontrada.\n", id);
}