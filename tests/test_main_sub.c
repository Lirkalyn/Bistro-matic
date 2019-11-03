/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(main, all_pos_sub)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[3] = "3-6";
    int size = 3;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "-3");
}

Test(main, first_pos_second_neg_sub)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[8] = "852--951";
    int size = 8;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "1803");
}

Test(main, first_neg_second_pos_sub)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[26] = "-761964949-751586275684685";
    int size = 26;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "-751587037649634");
}

Test(main, all_neg_sub)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[35] = "-7894562169585--7854129632147841695";
    int size = 35;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "7854121737585672110");
}

Test(main, all_neg_reverse_sub)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[35] = "-7854129632147841695--7894562169585";
    int size = 35;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "-7854121737585672110");
}