# C-Recipes
O C-Recipes é um projeto educacional feito em linguagem C com o intuito de funcionar como um caderno de receitas.

# Como proceder a compilação
Com o terminal aberto na pasta do projeto, utilize o comando *make*.
Sistemas Linux contam com o comando make nativamente, mas será necessário instala-lo caso o sistema utilizado seja Windows.

Caso não deseje usar o make, pode-se compilar normalmente utilizando o gcc:

gcc -std=c99 -c *.c

gcc -std=c99 -c *.h

gcc -std=c99 -o c-recipes *.c

c-recipes.exe

# Como executar
Após a compilação, no mesmo terminal e caminho, utilize o comando *./c-recipes*.
