#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include <ctype.h>
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
    for (int i = 0; i < strlen(entrada); i++)
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

int valida_email(char *entrada)
{
    int i;
    int tamanho = strlen(entrada);
    int tem_arroba = 0;
    int tem_ponto = 0;

    // Verifica se o email está vazio
    if (tamanho == 0)
    {
        return 0;
    }

    // Verifica se o email tem menos de 3 caracteres
    if (tamanho < 3)
    {
        return 0;
    }

    // Verifica se o email tem espaços duplos
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

    // Verifica se o email tem arroba
    for (i = 0; i < tamanho; i++)
    {
        if (entrada[i] == '@')
        {
            tem_arroba = 1;
            break;
        }
    }

    // Verifica se o email tem ponto
    for (i = 0; i < tamanho; i++)
    {
        if (entrada[i] == '.')
        {
            tem_ponto = 1;
            break;
        }
    }

    // Verifica se o email tem arroba e ponto
    if (tem_arroba == 0 || tem_ponto == 0)
    {
        return 0;
    }

    return 1;
}


void uppercase(char *str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}
