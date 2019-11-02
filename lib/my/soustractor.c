/*
** EPITECH PROJECT, 2019
** soustractor
** File description:
** Ceci va gérer les soustractions
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char *el_soustractor(char *num1, char *num2)
{
    int l1 = my_strlen(num1);
    int l2 = my_strlen(num2);
    char *tmp_num, *res;
    char *tmp_n1 = malloc(sizeof(num1));
    char *tmp_n2 = malloc(sizeof(num2));
    if (l1 < l2) {
        tmp_num = malloc(sizeof(num2));
        my_strcpy(tmp_num, num1);
        my_revstr(tmp_num);
        for (int i = l1 - 1 ; i != l2 ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (el_soureturnator(num1, num2, (substraction(tmp_num, num2, res)), tmp_n1, tmp_n2));
    } else if (l2 < l1) {
        tmp_num = malloc(sizeof(num1));
        res = malloc(sizeof(num1));
        my_strcpy(tmp_num, num2);
        my_revstr(tmp_num);
        for (int i = l2 - 1 ; i != l1 ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (el_soureturnator(num1, num2, (substraction(tmp_num, num1, res)), tmp_n1, tmp_n2));
    } else {
        if (nbr1_smaller(num1, num2) == 1)
            return (el_soureturnator(num1, num2, (substraction(num1, num2, res)), tmp_n1, tmp_n2));
        else {
            res = malloc(sizeof(num1));
            return (el_soureturnator(num1, num2, (substraction(num2, num1, res)), tmp_n1, tmp_n2));
        }
    }
}

char *el_soureturnator(char *num1, char *num2, char *result, char *tmp_n1, char *tmp_n2)
{
    int i = my_strlen(result);
    my_strcpy(tmp_n1, num1);
    my_strcpy(tmp_n2, num2);
    tmp_n1[0] = '0';
    tmp_n2[0] = '0';
    if (num1[0] == '-' && num2[0] != '-') {
        result = el_sumator(tmp_n1, tmp_n2);
        result[0] = '-';
        return (result);
    } else if (num2[0] == '-' && num1[0] != '-') {
        result = el_sumator(tmp_n1, tmp_n2);
        return (result);
    } else if (num1[0] == '-' && num2[0] == '-') {
        result = el_soustractor(tmp_n2, tmp_n1);
        if (nbr1_smaller(num1, num2) == 1)
            result[0] = '0';
        else result[0] = '-';
        return (result);
    } else if (nbr1_smaller(num1, num2) == 1 &&
      my_strlen(num1) <= my_strlen(num2)) {
        if (result[i - 1] != '0')
            result[i] = '-';
        else result[i - 1] = '-';
        return (my_revstr(result));
    } else {
        if (result[i - 1] != '0')
            result[i] = '0';
        return (my_revstr(result));
    }
}

char *substraction(char *num1, char *num2, char *result)
{
    int tmp;
    int c = 0;
    int carry = 0;
    int i = my_strlen(num1) - 1;
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
