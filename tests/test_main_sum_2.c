/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"
#include "../include/bistromatic.h"
#include "../include/my.h"

Test(main, all_pos_big_sum)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[36] = "741585848784184+56258874967416985874";
    int size = 36;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "56259616553265770058");
}

Test(main, first_pos_second_neg_big_sum)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[37] = "741585848784184+-56258874967416985874";
    int size = 37;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "-56258133381568201690");
}