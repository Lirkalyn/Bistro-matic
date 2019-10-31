/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** just for result
*/

#include <stdlib.h>
#include "eval_expr.h"

void fill_new_str(char *str, char *res, char *new_str, int res_size)
{
    int i;
    int j;
    int k = res_size;
    int last_a_pos;
    int num_a = 0;

    find_a(str, &last_a_pos, &num_a);
    for (i = 0; i <= (last_a_pos - num_a); i++)
        new_str[i] = str[i];
    for (j = (i + res_size - 1); j >= i; j--) {
        new_str[j] = res[(k - 1)];
        k--;
    }
    i += res_size;
    last_a_pos++;
    for (; str[last_a_pos] != '\0'; last_a_pos++) {
        new_str[i] = str[last_a_pos];
        i++;
    }
}

char *replace_expr(char *str, char *res)
{
    int i;
    int res_size;
    int str_size_no_a  = 0;
    char *new_str;

    for (res_size = 0; res[res_size] != '\0'; res_size++);
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] != 'a')
            str_size_no_a++;
    new_str = (char *)malloc((res_size + str_size_no_a + 1) * sizeof(char));
    new_str[(res_size + str_size_no_a)] = '\0';
    fill_new_str(str, res, new_str, res_size);
    return new_str;
}
