char menu_ingredientes();
void cadastrar_ingrediente();
void editar_ingrediente();
void deletar_ingrediente();
void atualizar_ingrediente();
void pesquisar_ingrediente();

struct Ingredientes {
    int id;
    char nome[50];
    char descricao[100];
};
