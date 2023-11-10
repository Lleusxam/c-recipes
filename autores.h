#ifndef AUTORES_H
#define AUTORES_H
typedef struct Autor
{
    int id;
    char nome[50];
    char telefone[15];
    int status;
} Autor;

char menu_autores();
void cadastrar_autor();
void editar_autor();
void deletar_autor();
void pesquisar_autor();
int existe_autor(int id);
int contar_autores();
void salvar_autor(Autor *autor);

#endif