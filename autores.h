#ifndef AUTORES_H
#define AUTORES_H
typedef struct Autor
{
    int id;
    char nome[50];
    char telefone[12];
    char email[50];
    int status;
} Autor;

char menu_autores();
void cadastrar_autor();
void editar_autor();
void deletar_autor();
void pesquisar_autor();
void listar_autores();
int existe_autor_id(int id);
int contar_autores();
void salvar_autor(Autor *autor);
char* buscar_autor(int id);
int existe_autor_nome(char* nome);
int existe_telefone(char* telefone);
int existe_email(char* email);
void pesquisar_autor_nome();
void pesquisar_autor_telefone();
void pesquisar_autor_email();
#endif