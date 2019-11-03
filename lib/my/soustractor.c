/*
** EPITECH PROJECT, 2019
** soustractor
** File description:
** Ceci va gérer les soustractions
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char *l1_smaller_than_l2(char *tmp_num, char *num1, char *num2)
{
    tmp_num = malloc(sizeof(char) * my_strlen(num2) + 2);
    tmp_num[my_strlen(num2) + 1] = '\0';
    my_strcpy(tmp_num, num1);
    my_revstr(tmp_num);
    for (int i = my_strlen(num1) - 1 ; i != my_strlen(num2) ; i++)
        tmp_num[i] = '0';
    my_revstr(tmp_num);
    return (tmp_num);
}

char *el_soustractor(char *num1, char *num2)
{
    char *tmp;

    if (my_strlen(num1) < my_strlen(num2)) {
        tmp = l1_smaller_than_l2(tmp, num1, num2);
        return (el_soureturnator(num1, num2, substraction(tmp, num2)));
    } else if (my_strlen(num2) < my_strlen(num1)) {
        tmp = malloc(sizeof(char) * my_strlen(num1) + 2);
        tmp[my_strlen(num1) + 1] = '\0';
        my_strcpy(tmp, num2);
        my_revstr(tmp);
        for (int i = my_strlen(num2) - 1 ; i != my_strlen(num1) ; i++)
            tmp[i] = '0';
        my_revstr(tmp);
        return (el_soureturnator(num1, num2, (substraction(tmp, num1))));
    } else {
        if (nbr1_smaller(num1, num2) == 1)
            return (el_soureturnator(num1, num2, substraction(num1, num2)));
        else return (el_soureturnator(num1, num2, substraction(num2, num1)));
    }
}

char *el_soureturnator(char *num1, char *num2, char *result)
{
    char *tmp_n1 = make_tmp_n1(num1);
    char *tmp_n2 = make_tmp_n2(num2);

    if (num1[0] == '-' && num2[0] != '-') {
        result = el_sumator(tmp_n1, tmp_n2);
        result[0] = '-';
    } else if (num2[0] == '-' && num1[0] != '-') {
        result = el_sumator(tmp_n1, tmp_n2);
    } else if (num1[0] == '-' && num2[0] == '-') {
        result = num1_and_num2_neg(num1, num2, result);
    } else if (nbr1_smaller(num1, num2) == 1 &&
    my_strlen(num1) <= my_strlen(num2)) {
        result = num1_smaller_than_num2(my_strlen(result), result);
    } else {
        if (result[my_strlen(result) - 1] != '0')
            result[my_strlen(result)] = '0';
        result = my_revstr(result);
    } result[my_strlen(result)] = '\0';
    return (result);
}

char *substraction(char *num1, char *num2)
{
    int tmp;
    int c = 0;
    int carry = 0;
    int i = my_strlen(num1) - 1;
    char *result;

    result = malloc(sizeof(char) * i + 2);
    for (i ; i != 0 ; i--, c++) {
        tmp = (num2[i] - '0') - ((num1[i] - '0') + carry);
        carry = 0;
        if (tmp < 0) {
            tmp = tmp +10;
            carry = 1;
        }
        result[c] = tmp + '0';
    }
    return (result);
}