/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_result.c
*/

#include <criterion/criterion.h>
#include "../lib/my/eval_expr.h"

Test(fill_new_str, normal_fill_new_str)
{
    char *str = "(1+aaaaaaaaaaaa+5*-6)";
    int str_size = 9;
    char *res = "0128";
    int res_size = 4;
    char new_str[(res_size + str_size + 1)];
    new_str[(res_size + str_size)] = '\0';

    fill_new_str(str, res, new_str, res_size);
    cr_assert_str_eq(new_str, "(1+0128+5*-6)");
}

Test(replace_expr, normal_replace_expr)
{
    char *str = "(1+aaaaaaaaaaaa+5*-6)";
    char *res = "0128";

    cr_assert_str_eq(replace_expr(str, res), "(1+0128+5*-6)");
}

Test(fill_new_str, normal_fill_new_str_neg)
{
    char *str = "(1+aaaaaaaaaaaa+5*-6)";
    int str_size = 9;
    char *res = "-128";
    int res_size = 4;
    char new_str[(res_size + str_size + 1)];
    new_str[(res_size + str_size)] = '\0';

    fill_new_str(str, res, new_str, res_size);
    cr_assert_str_eq(new_str, "(1+-128+5*-6)");
}

Test(replace_expr, normal_replace_expr_neg)
{
    char *str = "(1+aaaaaaaaaaaa+5*-6)";
    char *res = "-128";

    cr_assert_str_eq(replace_expr(str, res), "(1+-128+5*-6)");
}