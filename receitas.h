char menu_receitas();
void cadastrar_receita();
void editar_receita();
void deletar_receita();
void atualizar_receita();
void pesquisar_receita();

struct Receita {
    int id;
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
};