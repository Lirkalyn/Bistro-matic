/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** test_negnbr2.c
*/

#include <criterion/criterion.h>
#include "../lib/my/eval_expr.h"

Test(fill_num, normal_fill_num_2)
{
    char calc_poi[19] = "3+6/42*877+965-12/1";
    char op[7];
    char *num[8];

    op[6] = '\0';
    num[7] = 0;
    calc_num_size(calc_poi, num);
    fill_num(calc_poi, num, op);
    cr_assert_str_eq(num[0], "03");
    cr_assert_str_eq(num[1], "06");
    cr_assert_str_eq(num[2], "042");
    cr_assert_str_eq(num[3], "0877");
    cr_assert_str_eq(num[4], "0965");
    cr_assert_str_eq(num[5], "012");
    cr_assert_str_eq(num[6], "01");
    cr_assert_str_eq(op, "+/*+-/");
    cr_assert(num[7] == 0);
}

Test(fill_num, normal_fill_num_neg)
{
    char calc_poi[12] = "3+-6/42*-877";
    char op[4];
    char *num[5];

    op[3] = '\0';
    num[4] = 0;
    calc_num_size(calc_poi, num);
    fill_num(calc_poi, num, op);
    cr_assert_str_eq(num[0], "03");
    cr_assert_str_eq(num[1], "-6");
    cr_assert_str_eq(num[2], "042");
    cr_assert_str_eq(num[3], "-877");
    cr_assert_str_eq(op, "+/*");
    cr_assert(num[4] == 0);
}

Test(fill_num, normal_fill_num_2_neg)
{
    char calc_poi[22] = "3+6/-42*877+-965--12/1";
    char op[7];
    char *num[8];

    op[6] = '\0';
    num[7] = 0;
    calc_num_size(calc_poi, num);
    fill_num(calc_poi, num, op);
    cr_assert_str_eq(num[0], "03");
    cr_assert_str_eq(num[1], "06");
    cr_assert_str_eq(num[2], "-42");
    cr_assert_str_eq(num[3], "0877");
    cr_assert_str_eq(num[4], "-965");
    cr_assert_str_eq(num[5], "-12");
    cr_assert_str_eq(num[6], "01");
    cr_assert_str_eq(op, "+/*+-/");
    cr_assert(num[7] == 0);
}

Test(fill_num, normal_fill_num_2_all_pos)
{
    char calc_poi[17] = "3+6/42*877%965-12";
    char op[6];
    char *num[7];

    op[5] = '\0';
    num[6] = 0;
    calc_num_size(calc_poi, num);
    fill_num(calc_poi, num, op);
    cr_assert_str_eq(num[0], "03");
    cr_assert_str_eq(num[1], "06");
    cr_assert_str_eq(num[2], "042");
    cr_assert_str_eq(num[3], "0877");
    cr_assert_str_eq(num[4], "0965");
    cr_assert_str_eq(num[5], "012");
    cr_assert_str_eq(op, "+/*%-");
    cr_assert(num[6] == 0);
}

Test(fill_num, normal_fill_num_2_all_neg)
{
    char calc_poi[22] = "-3+-6/-42*-877%-965--1";
    char op[6];
    char *num[7];

    op[5] = '\0';
    num[6] = 0;
    calc_num_size(calc_poi, num);
    fill_num(calc_poi, num, op);
    cr_assert_str_eq(num[0], "-3");
    cr_assert_str_eq(num[1], "-6");
    cr_assert_str_eq(num[2], "-42");
    cr_assert_str_eq(num[3], "-877");
    cr_assert_str_eq(num[4], "-965");
    cr_assert_str_eq(num[5], "-1");
    cr_assert_str_eq(op, "+/*%-");
    cr_assert(num[6] == 0);
}