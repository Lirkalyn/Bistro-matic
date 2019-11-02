/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(main, objectif_zero_mod)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[3] = "5%5";
    int size = 3;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "0");
}