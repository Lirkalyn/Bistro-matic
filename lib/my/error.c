/*
** EPITECH PROJECT, 2019
** error
** File description:
** errors handling;
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

char *operator_in_the_base(char *base)
{
    int i;

    for (i = 0; base[i] != '\0'; i++)
    {
        if (base[i] == '+' || base[i] == '*'
        || base[i] == '/' || base[i] == '%'
        || base[i] == '(' || base[i] == ')'
        || base[i] == '-') {
            return (SYNTAX_ERROR_MSG);
        }
    }
}

char *two_identical_digits(char *base)
{
    int i;
    int j;
    char *cpy_base = malloc(sizeof(char) * (my_strlen(base) + 1));

    my_strcpy(cpy_base, base);
    for (i = 0; base[i] != '\0'; i++) {
        for (j = i + 1; cpy_base[j] != '\0'; j++) {
            if (base[i] == cpy_base[j]) {
                return (SYNTAX_ERROR_MSG);
            }
        }
    }
}

char *invalid_expression(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '(')
            return (SYNTAX_ERROR_MSG);
    }
}

char *unknown_digit(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+'
        || str[i] == '-' || str[i] == '*' || str[i] == '/'
        || str[i] == '%' || str[i] == '(' || str[i] == ')');
        else
            return (SYNTAX_ERROR_MSG);
    }
}

char *not_enought_brackets(char *str)
{
    int i;
    int brackets = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            brackets++;
        else if (str[i] == ')')
            brackets--;
    }
    if (brackets != 0)
        return (SYNTAX_ERROR_MSG);
}