/*
** EPITECH PROJECT, 2019
** error 2
** File description:
** error handling of divide and modulo by 0
*/

#include "my.h"
#include "bistromatic.h"

char *divide_by_zero(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/' || str[i] == '%' && str[i + 1] == '0')
            return (SYNTAX_ERROR_MSG);
    }
}