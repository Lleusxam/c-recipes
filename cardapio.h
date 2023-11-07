typedef struct Cardapio {
    int id;
    char entrada[100];
    char prato_principal[100];
    char sobremesa[100];
    int status;
} Cardapio;

char menu_cardapio();
void cadastrar_cardapio(Cardapio cardapios[], int *quantidade_cardapios);
void editar_cardapio(Cardapio cardapios[], int quantidade_cardapaios);
void deletar_cardapio(Cardapio cardapios[], int quantidade_cardapios);
void pesquisar_cardapio(Cardapio cardapios[], int quantidade_cardapios);