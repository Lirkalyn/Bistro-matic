/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** zert
*/

#include <stdlib.h>

void find_a(char *str, int *last_a_pos, int *num_a)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            *last_a_pos = i;
            *num_a += 1;
        }
    }
}

int clean(char *str)
{
    int i;
    int len = 0;

    if (str[0] == '0' && str[1] == '\0')
        return 0;
    for (len = 0; str[len] != '\0'; len++);
    if (str[0] == '0')
        for (i = 0; i < len; i++)
            str[i] = str[(i + 1)];
    else if (str[0] == '-' && str[1] == '0')
        for (i = 1; i < len; i++)
            str[i] = str[(i + 1)];
    if (str[0] == '0')
        clean(str);
}

char *complete_res(char const *expr, char *res, unsigned int size)
{
    int i;

    if (expr[0] == '-' && expr[1] == '(') {
        res = (char *)malloc((size + 5) * sizeof(char));
        res[0] = '(';
        res[1] = '-';
        res[2] = '1';
        res[3] = '*';
        for (i = 0; i < size; i++)
            res[i + 4] = expr[(i + 1)];
        res[size + 3] = ')';
        res[(size + 4)] = '\0';
    } else {
        res = (char *)malloc((size + 3) * sizeof(char));
        res[0] = '(';
        res[(size + 1)] = ')';
        res[(size + 2)] = '\0';
        for (i = 0; i < size; i++)
            res[i + 1] = expr[i];
    }
    return res;
}
