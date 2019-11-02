/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(main, all_pos_same_lenght_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[23] = "84129549652*56215645526";
    int size = 23;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "04729396941498848656952");
}

Test(main, all_neg_same_lenght_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[27] = "-686446946615*-464945648464";
    int size = 27;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "0319160520730043964749360");
}

Test(main, first_neg_second_pos_same_lenght_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[24] = "-87464641384*64136514986";
    int size = 24;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "-5609677282870031780624");
}

Test(main, first_pos_second_neg_same_lenght_mul)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[24] = "56341641635*-86132968451";
    int size = 24;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "-4852872841425003057385");
}