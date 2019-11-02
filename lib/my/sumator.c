/*
** EPITECH PROJECT, 2019
** sumator
** File description:
** Ceci va gérer les additions
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char *el_sumator(char *num1, char *num2)
{
    int l1 = my_strlen(num1);
    int l2 = my_strlen(num2);
    char *tmp_num;
    if (l1 < l2) {
        tmp_num = malloc(sizeof(char) * l2 + 1);
        my_strcpy(tmp_num, num1);
        my_revstr(tmp_num);
        for (int i = l1 - 1 ; i != l2 ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (sum_result(num1, num2, addsum(tmp_num, num2)));
    } else if (l2 < l1) {
        tmp_num = malloc(sizeof(char) * l1 + 1);
        my_strcpy(tmp_num, num2);
        my_revstr(tmp_num);
        for (int i = l2 - 1 ; i != l1 ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (sum_result(num1, num2, addsum(tmp_num, num1)));
    } else return (sum_result(num1, num2, addsum(num1, num2)));
}

char *addsum(char *num1, char *num2)
{
    int tmp;
    int c = 0;
    int carry = 0;
    int i = my_strlen(num1) - 1;
    char *result = malloc(sizeof(char) * i + 2);
    for (i ; i != 0 ; i--, c++) {
        tmp = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = 0;
        if (tmp > 9) {
            carry = tmp / 10;
            tmp = tmp % 10;
        }
        result[c] = tmp + '0';
    } if (carry == 1)
        result[c] = 1 + '0';
    return (result);
}

char *sum_result(char *num1, char *num2, char *result)
{
    int i = my_strlen(result);
    if (num1[0] == '-' && num2[0] == '-')
        result[i] = '-';
    else if (num1[0] == '-' && num2[0] != '-') {
        return (el_soustractor(num2, num1));
    } else if (num2[0] == '-' && num1[0] != '-') {
        return (el_soustractor(num1, num2));
    } else if (result[i - 1] != '-') {
        result[i] = '0';
    } return (my_revstr(result));
}
