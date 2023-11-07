typedef struct Autor {
    int id;
    char nome[50];
    char telefone[15];
    int status;
} Autor;

char menu_autores();
void cadastrar_autor(Autor autores[], int *quantidade_autores);
void editar_autor(Autor autores[], int quantidade_autores);
void deletar_autor();
void pesquisar_autor(Autor autores[], int quantidade_autores);