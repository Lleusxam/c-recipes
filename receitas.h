#ifndef RECEITAS_H
#define RECEITAS_H
#include "autores.h"
typedef struct Receita
{
    int id;
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
    int status;
    int id_autor;
} Receita;

char menu_receitas();
void cadastrar_receita();
void editar_receita();
void deletar_receita();
void pesquisar_receita();
void listar_receitas();
void salvar_receita(Receita *receitas);
int contar_receitas();
int existe_receita(int id);
char* buscar_receita(int id);
int existe_receita_nome(char* nome);
void pesquisar_receita_nome(); 
void pesquisar_receita_categoria();
void pesquisar_receita_autor();
#endif