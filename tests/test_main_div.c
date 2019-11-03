/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(main, all_pos_div)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[35] = "6599316643684158513/664316435168451";
    int size = 35;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "09933");
}

Test(main, first_pos_second_neg_div)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[38] = "68453198645189654163/-6316515645316458";
    int size = 38;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "-10837");
}

Test(main, first_neg_second_pos_div)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[47] = "-64513168541538651/9653131985614198645198561431";
    int size = 47;

    cr_expect_str_eq(eval_expr(av1, av2, expr, size), "0");
}

Test(main, all_neg_div)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[44] = "-631684518461431598651/-61598846136451326841";
    int size = 44;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "010");
}

Test(main, all_neg_reverse_div)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[44] = "-61598846136451326841/-631684518461431598651";
    int size = 44;

    cr_expect_str_eq(eval_expr(av1, av2, expr, size),
        "0");
}