typedef struct Receita {
    int id;
    char nome[100];
    char descricao[500];
    int porcoes;
    char categoria[50];
    int status;
} Receita;

typedef struct Receita Receita;
char menu_receitas();
void cadastrar_receita(Receita receitas[], int *quantidade_receitas);
void editar_receita(Receita receitas[], int quantidade_receitas);
void deletar_receita(Receita receitas[], int quantidade_receitas);
void pesquisar_receita(Receita receitas[], int quantidade_receitas);