char menu_autores();
void cadastrar_autor();
void editar_autor();
void deletar_autor();
void atualizar_autor();
void pesquisar_autor();

struct Autor {
    int id;
    char nome[50];
    char telefone[15];
}