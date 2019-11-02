/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(main, all_pos_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[26] = "84129549652*56215645526541";
    int size = 26;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "04729396941544362743313732");
}

Test(main, first_pos_second_neg_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[45] = "854646471684616494494*-6574654451851656148451";
    int size = 45;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "-5619005229820574226115151206081785288128794");
}

Test(main, first_neg_second_pos_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[43] = "-789641652419625474125*45696584123985474165";
    int size = 43;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "-36083926197596313422574272961101063480625");
}

Test(main, all_neg_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[47] = "-464964631649464878463184*-64974646149846319431";
    int size = 47;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "030210912413617615285841371031273862037328304");
}

Test(main, all_neg_reverse_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[47] = "-64974646149846319431*-464964631649464878463184";
    int size = 47;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "030210912413617615285841371031273862037328304");
}