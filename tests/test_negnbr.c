/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** test_negnbr.c
*/

#include <criterion/criterion.h>
#include "../lib/my/eval_expr.h"

Test(fill_calc_poi, normal_fill_calc_poi)
{
    char *expr = "(1+(3+6/42*877)+5*-6)";
    int first_close_bra = 14;
    int last_open_bra = 3;
    char calc_poi[11];

    calc_poi[11] = '\0';
    fill_calc_poi(last_open_bra, first_close_bra, calc_poi, expr);
    cr_assert_str_eq(calc_poi, "3+6/42*877");
}

Test(fill_expr_w_a, normal_fill_expr_w_a)
{
    char expr[22] = "(1+(3+6/42*877)+5*-6)";
    int first_close_bra = 14;
    int last_open_bra = 3;

    fill_expr_w_a(last_open_bra, first_close_bra, expr);
    cr_assert_str_eq(expr, "(1+aaaaaaaaaaaa+5*-6)");
}

Test(calc_num_size, normal_calc_num_size)
{
    char calc_poi[10] = "3+6/42*877";
    char *num[5];
    num[4] = 0;

    calc_num_size(calc_poi, num);
    cr_assert_str_eq(num[0], "00");
    cr_assert_str_eq(num[1], "00");
    cr_assert_str_eq(num[2], "000");
    cr_assert_str_eq(num[3], "0000");
    cr_assert(num[4] == 0);
}

Test(calc_num_size, normal_calc_num_size_2)
{
    char calc_poi[19] = "3+6/42*877+965-12/1";
    char *num[8];
    num[7] = 0;

    calc_num_size(calc_poi, num);
    cr_assert_str_eq(num[0], "00");
    cr_assert_str_eq(num[1], "00");
    cr_assert_str_eq(num[2], "000");
    cr_assert_str_eq(num[3], "0000");
    cr_assert_str_eq(num[4], "0000");
    cr_assert_str_eq(num[5], "000");
    cr_assert_str_eq(num[6], "00");
    cr_assert(num[7] == 0);
}

Test(fill_num, normal_fill_num)
{
    char calc_poi[10] = "3+6/42*877";
    char op[4];
    char *num[5];

    op[3] = '\0';
    num[4] = 0;
    calc_num_size(calc_poi, num);
    fill_num(calc_poi, num, op);
    cr_assert_str_eq(num[0], "03");
    cr_assert_str_eq(num[1], "06");
    cr_assert_str_eq(num[2], "042");
    cr_assert_str_eq(num[3], "0877");
    cr_assert_str_eq(op, "+/*");
    cr_assert(num[4] == 0);
}