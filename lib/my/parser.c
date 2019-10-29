/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** le parsing ça passe
*/

#include <stdio.h>
#include <stdlib.h>
#include "eval_expr.h"

char *pre_clac_fork(char *calc_poi, int signes)
{
    char **num;
    int i;
    int pos = 0;
//    int signes = 0; send signes from calling function ?
    char *op;
    int res;

//    nbr_signes(calc_poi, &signes);
    num = (char **)malloc((signes + 2) * sizeof(char *));
    num[(signes + 1)] = 0;
    printf("(signes + 1) = %d\n", (signes + 1));
    //printf("signes = %d\n", signes);
    op = (char *)malloc((signes + 1) * sizeof(char));
    op[signes] = '\0';
    calc_num_size(calc_poi, num);
    put_zero(num, signes);
    fill_num(calc_poi, num, op);
    printf("again\n");
    put_zero(num, signes);
    return calc_fork(num, op, signes);
}

void find_bra(char *str, int *first_close_bra, _Bool *find, int *last_open_bra)
{
    int i;
    int len;

    for (len = 0; str[len] != '\0'; len++);
    for (i = 0; i < len; i++) {
        if (str[i] == ')' && *find == 0) {
            *first_close_bra = i;
            *find = 1;
        }
    }
    *find = 0;
    for (i = *first_close_bra; i >= 0; i--) {
        if (str[i] == '(' && *find == 0) {
            *last_open_bra = i;
            *find = 1;
        }
    }
}

char *brackets(char *expr, int len)
{
//    int i;
//    int j = 0;
    int first_close_bra = -1;
    _Bool find = 0;
    int last_open_bra = -1;
    char *calc_poi;
    char *res;
    int signes = 0;

    find_bra(expr, &first_close_bra, &find, &last_open_bra);
//    printf("first_close_bra = %d et last_open_bra = %d\n", first_close_bra, last_open_bra);
    if (first_close_bra == -1)
        return expr;
    calc_poi = (char *)malloc((first_close_bra - last_open_bra) * sizeof(char));
    calc_poi[(first_close_bra - last_open_bra - 1)] = '\0';
    fill_calc_poi(last_open_bra, first_close_bra, calc_poi, expr);
    printf("calc_poi = %s\n", calc_poi);
    nbr_signes(calc_poi, &signes);
    printf("signes = %d\n", signes);
    res = pre_clac_fork(calc_poi, signes);
    printf("res = %s\n", res);
    fill_expr_w_a(last_open_bra, first_close_bra, expr);
    printf("expr = %s\n", expr);
    expr = replace_expr(expr, res); // for later
    if (first_close_bra != -1)
        brackets(expr, len);
}

int parsayaya(char const *av1, char const *av2,
        char const *expr, unsigned int size)
{
    int i;
//    int len;
    char *res;
    char *str;
//    int result = 0;
//    _Bool neg = 0;

//    for (len = 0; expr[len] != '\0'; len++);
    res = (char *)malloc((size + 3) * sizeof(char));
    res[0] = '(';
    res[(size + 1)] = ')';
    res[(size + 2)] = '\0';
    for (i = 0; i < size; i++)
        res[i + 1] = expr[i];
    printf("res = %s size = %d\n", res, size);
    str = brackets(res, size);
    printf("fin = %s", str);
/*    for (i = 0; stt[i] != '\0'; i++) {
        if (stt[0] == '-' && neg == 0) {
            neg = 1;
            i++;
        }
        result = ((result * 10) + (stt[i] - '0'));
        }*//* //------
//        if (neg == 1)
//            result *= (-1);
    return result;*/
}

int eval_expr(char const *av1, char const *av2,
        char const *expr, unsigned int size)
{
    int i;
    int brackets = 0;

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(')
            brackets++;
        else if (expr[i] == ')')
            brackets--;
    }
    if (brackets != 0)
        return 84;
    printf("test = %s\n", expr);
    return parsayaya(av1, av2, expr, size);
}

