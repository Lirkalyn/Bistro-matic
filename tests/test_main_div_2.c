/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_main.c_sum
*/

#include <criterion/criterion.h>
#include "../include/eval_expr.h"

//Test(main, all_neg_div_bug)
//{
//    char *av1 = "0123456789";
//    char *av2 = "()+-*/%";
//    char expr[47] = "-631684518461431598651/-61598846131986451326841";
//    int size = 47;

//    cr_expect_str_eq(eval_expr(av1, av2, expr, size), "0");
//}

Test(main, objectif_one_div)
{
    char *av1 = "0123456789";
    char *av2 = "()+-*/%";
    char expr[3] = "5/5";
    int size = 3;

    cr_assert_str_eq(eval_expr(av1, av2, expr, size), "01");
}