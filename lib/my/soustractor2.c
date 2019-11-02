/*
** EPITECH PROJECT, 2019
** soustractor2
** File description:
** functions to make soustractor works
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char *num1_and_num2_neg(char *num1, char *num2, char *result)
{
    char *clean_nbr = malloc(sizeof(char) * my_strlen(result) + 1);
    char *tmp_n1 = malloc(sizeof(char) * my_strlen(num1) + 1);
    char *tmp_n2 = malloc(sizeof(char) * my_strlen(num2) + 1);

    my_strcpy(tmp_n1, num1);
    my_strcpy(tmp_n2, num2);
    tmp_n1[0] = '0';
    tmp_n2[0] = '0';
    result = el_soustractor(tmp_n2, tmp_n1);
    if (nbr1_smaller(num1, num2) == 1 && my_strlen(num1) <= my_strlen(num2))
        result[0] = '0';
    else result[0] = '-';
    if (result[1] == '0') {
        for (int i = 0, j = 1 ; result[j] != '\0' ; i++, j++) {
            clean_nbr[i] = result[j];
        } if (result[0] == '-')
            clean_nbr[0] = '-';
        result = clean_nbr;
    }
    return (result);
}

char *make_tmp_n1(char *num1)
{
    char *tmp_n1 = malloc(sizeof(char) * my_strlen(num1) + 1);

    my_strcpy(tmp_n1, num1);
    tmp_n1[0] = '0';
}

char *make_tmp_n2(char *num2)
{
    char *tmp_n2 = malloc(sizeof(char) * my_strlen(num2) + 1);

    my_strcpy(tmp_n2, num2);
    tmp_n2[0] = '0';
}

char *num1_smaller_than_num2(int i, char *result)
{
    if (result[i - 1] != '0')
            result[i] = '-';
    else result[i - 1] = '-';
    return (my_revstr(result));
}