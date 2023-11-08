#ifndef RECEITAS_H
#define RECEITAS_H
#include "autores.h"
typedef struct Receita {
    int id;
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
    int status;
    int id_autor;
} Receita;

char menu_receitas();
void cadastrar_receita(Receita receitas[], int *quantidade_receitas);
void editar_receita(Receita receitas[], int quantidade_receitas);
void deletar_receita(Receita receitas[], int quantidade_receitas);
void pesquisar_receita(Receita receitas[], int quantidade_receitas, Autor autores[], int quantidade_autores);

#endif 