#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Lê e descarta caracteres do buffer até encontrar '\n' ou EOF
    }
}

int valida_natural(char *entrada)
{
    int i;
    for (i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] < '0' || entrada[i] > '9')
        {
            return 0;
        }
    }
    if (atoi(entrada) <= 0)
    {
        return 0;
    }
    return 1;
}

int valida_telefone(char *entrada)
{
    int i;
    for (i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] < '0' || entrada[i] > '9')
        {
            return 0;
        }
    }
    if (strlen(entrada) != 11)
    {
        return 0;
    }
    return 1;
}

int valida_nome(char *entrada)
{
    int i;
    int tamanho = strlen(entrada);

    // Verifica se o nome está vazio
    if (tamanho == 0)
    {
        return 0;
    }

    // Verifica se o nome tem menos de 3 caracteres
    if (tamanho < 3)
    {
        return 0;
    }

    // Verifica se o nome tem números
    for (i = 0; i < tamanho; i++)
    {
        if (entrada[i] >= '0' && entrada[i] <= '9')
        {
            return 0;
        }
    }

    // Verifica se o nome tem espaços duplos
    for (i = 0; i < tamanho - 1; i++)
    {
        if (entrada[i] == ' ' && entrada[i + 1] == ' ')
        {
            return 0;
        }
    }

    // Verifica se o último caractere é um espaço vazio
    if (entrada[tamanho - 1] == ' ')
    {
        return 0;
    }

    return 1;
}