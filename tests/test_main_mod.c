/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

Test(main, all_pos_mod)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[31] = "6541986451985461%68451865416845";
    int size = 31;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "039059237385186");
}

Test(main, first_pos_second_neg_mod)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[31] = "684518518651486%-96485619685184";
    int size = 31;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "-87366438829986");
}

Test(main, first_neg_second_pos_mod)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[35] = "-6835416451986541864%68418561986451";
    int size = 35;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "08401831831742");
}

Test(main, all_neg_mod)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[38] = "-684351684531641684531%-63519865312465";
    int size = 38;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "-25711034705766");
}

Test(main, all_neg_reverse_mod)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[38] = "-63519865312465%-684351684531641684531";
    int size = 38;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size),
        "-63519865312465");
}