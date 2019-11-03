/*
** EPITECH PROJECT, 2019
** error 2
** File description:
** error handling of divide and modulo by 0
*/

#include "my.h"
#include "bistromatic.h"

int divide_by_zero(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/' || str[i] == '%' && str[i + 1] == '0')
            return 1;
    }
    return 0;
}

char *all_error(char *av1, char *av2, char *expr)
{
    int res = 0;

    res = operator_in_the_base(av1);
    res = two_identical_digits(av1);
    res = invalid_expression(expr);
    res = unknown_digit(expr);
    res = not_enought_brackets(expr);
    res = divide_by_zero(expr);
    if (res == 1)
        return (SYNTAX_ERROR_MSG);
}