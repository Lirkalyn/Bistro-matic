/*
** EPITECH PROJECT, 2019
** d
** File description:
** d
*/

#include <stdlib.h>
#include "eval_expr.h"

void fill_calc_poi(int last_open_bra, int first_close_bra,
        char *calc_poi, char *expr)
{
    int i;
    int j = 0;

    for (i = (last_open_bra + 1); i <= (first_close_bra - 1); i++) {
        calc_poi[j] = expr[i];
        j++;
    }
}

void fill_expr_w_a(int last_open_bra, int first_close_bra, char *expr)
{
    int i;

    for (i = last_open_bra; i <= first_close_bra; i++) {
        expr[i] = 'a';
    }
}

void calc_num_size(char *calc_poi, char **num)
{
    int i;
    int j;
    int size = 0;
    int pois = 0;

    for (i = 0; calc_poi[i] != '\0'; i++) {
        if (calc_poi[i] >= '0' && calc_poi[i] <= '9')
            size++;
        if (calc_poi[(i + 1)] == '+' || calc_poi[(i + 1)] == '-'
            || calc_poi[(i + 1)] == '*' || calc_poi[(i + 1)] == '/'
            || calc_poi[(i + 1)] == '%' || calc_poi[(i + 1)] == '\0') {
            num[pois] = (char *)malloc((size + 2) * sizeof(char));
            num[pois][(size + 1)] = '\0';
            for (j = 0; j < (size + 1); j++)
                num[pois][j] = '0';
            pois++;
            i++;
            size = 0;
        }
    }
}

void fill_num(char *calc_poi, char **num, char *op)
{
    int i;
    int j = 1;
    int pois = 0;

    for (i = 0 ; calc_poi[i] != '\0'; i++) {
        if (calc_poi[i] >= '0' && calc_poi[i] <= '9')
            num[pois][j++] = calc_poi[i];
        if (calc_poi[(i + 1)] == '+' || calc_poi[(i + 1)] == '-'
            || calc_poi[(i + 1)] == '*' || calc_poi[(i + 1)] == '/'
            || calc_poi[(i + 1)] == '%') {
            if (calc_poi[(i + 2)] == '-')
                num[(pois + 1)][0] = '-';
            if (calc_poi[0] == '-')
                num[0][0] = '-';
            op[pois] = calc_poi[(i + 1)];
            pois++;
            i++;
            j = 1;
        }
    }
}