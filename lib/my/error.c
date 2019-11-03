/*
** EPITECH PROJECT, 2019
** error
** File description:
** errors handling;
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

int operator_in_the_base(char *base)
{
    int i;

    for (i = 0; base[i] != '\0'; i++)
    {
        if (base[i] == '+' || base[i] == '*'
        || base[i] == '/' || base[i] == '%'
        || base[i] == '(' || base[i] == ')'
        || base[i] == '-') {
            return 1;
        }
    }
    return 0;
}

int two_identical_digits(char *base)
{
    int i;
    int j;
    char *cpy_base = malloc(sizeof(char) * (my_strlen(base) + 2));

    cpy_base[(my_strlen(base) + 1)] = '\0';
    my_strcpy(cpy_base, base);
    for (i = 0; base[i] != '\0'; i++) {
        for (j = i + 1; cpy_base[j] != '\0'; j++) {
            if (base[i] == cpy_base[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int invalid_expression(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '(')
            return 1;
    }
    return 0;
}

int unknown_digit(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+'
        || str[i] == '-' || str[i] == '*' || str[i] == '/'
        || str[i] == '%' || str[i] == '(' || str[i] == ')');
        else
            return 1;
    }
    return 0;
}

int not_enought_brackets(char *str)
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
        return 1;
    return 0;
}
