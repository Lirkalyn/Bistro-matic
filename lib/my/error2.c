/*
** EPITECH PROJECT, 2019
** error 2
** File description:
** error handling of divide and modulo by 0
*/

#include "my.h"
#include "bistromatic.h"
#include "error.h"

int divide_by_zero(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/' && str[i + 1] == '0')
            return 1;
        else if (str[i] == '%' && str[i + 1] == '0')
            return 1;
    }
    return 0;
}

int all_error(char *av1, char *av2, char *expr)
{
    if (operator_in_the_base(av1))
        return 1;
    if (two_identical_digits(av1))
        return 1;
    if (two_identical_digits(av2))
        return 1;
    if (invalid_expression(expr))
        return 1;
    if (unknown_digit(expr))
        return 1;
    if (not_enought_brackets(expr))
        return 1;
    if (divide_by_zero(expr))
        return 1;
}
