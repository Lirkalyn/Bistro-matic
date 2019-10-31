/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_result2.c
*/

#include <criterion/criterion.h>
#include "../lib/my/eval_expr.h"

Test(find_a, normal_find_a)
{
    char *str = "(1+aaaaaaaaaaaa+5*-6)";
    int last_a_pos = 0;
    int num_a = 0;

    find_a(str, &last_a_pos, &num_a);
    cr_assert(last_a_pos == 14);
    cr_assert(num_a == 12);
}