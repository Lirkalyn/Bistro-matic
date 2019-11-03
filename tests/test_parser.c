/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** test_parser
*/

#include <criterion/criterion.h>
#include "../lib/my/eval_expr.h"

Test(parsayaya, normal_parsayaya)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char *expr = "1+5*(2+2)";
    int size = 9;

    cr_assert_str_eq(parsayaya(av1, av2, expr, size), "21");
}

Test(find_bra, normal_find_bra)
{
    char *expr = "(1+(3+6/42*877)+5*-6)";
    int first_close_bra = -1;
    int last_open_bra = -1;
    _Bool find = 0;

    find_bra(expr, &first_close_bra, &find, &last_open_bra);
    cr_assert(first_close_bra == 14);
    cr_assert(last_open_bra == 3);
    cr_assert(find == 1);
}

Test(find_bra, no_bra_find_bra)
{
    char *expr = "1+3+6/42*877+5*-6";
    int first_close_bra = -1;
    int last_open_bra = -1;
    _Bool find = 0;

    find_bra(expr, &first_close_bra, &find, &last_open_bra);
    cr_assert(first_close_bra == -1);
    cr_assert(last_open_bra == -1);
    cr_assert(find == 0);
}