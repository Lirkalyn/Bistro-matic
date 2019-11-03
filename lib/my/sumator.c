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
    char *tmp_num;

    if (my_strlen(num1) < my_strlen(num2)) {
        tmp_num = malloc(sizeof(char) * my_strlen(num2) + 1);
        tmp_num[my_strlen(num2)] = '\0';
        my_strcpy(tmp_num, num1);
        my_revstr(tmp_num);
        for (int i = my_strlen(num1) - 1 ; i != my_strlen(num2) ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (sum_result(num1, num2, addsum(tmp_num, num2)));
    } else if (my_strlen(num2) < my_strlen(num1)) {
        tmp_num = malloc(sizeof(char) * my_strlen(num1) + 1);
        tmp_num[my_strlen(num1)] = '\0';
        my_strcpy(tmp_num, num2);
        my_revstr(tmp_num);
        for (int i = my_strlen(num2) - 1 ; i != my_strlen(num1) ; i++)
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
    char *tmp_num;

    if (num1[0] == '-' && num2[0] != '-') {
        tmp_num = malloc(sizeof(char) * my_strlen(num1) + 1);
        tmp_num[my_strlen(num1) + 1] = '\0';
        my_strcpy(tmp_num, num1);
        tmp_num[0] = '0';
        return (el_soustractor(num2, tmp_num));
    } else if (num2[0] == '-' && num1[0] != '-') {
        tmp_num = malloc(sizeof(char) * my_strlen(num2) + 1);
        tmp_num[my_strlen(num2) + 1] = '\0';
        my_strcpy(tmp_num, num2);
        tmp_num[0] = '0';
        return (el_soustractor(num1, tmp_num));
    } else {
        if (num1[0] == '-' && num2[0] == '-')
            result[my_strlen(result)] = '-';
        else result[my_strlen(result)] = '0';
        my_revstr(result);
        result[(my_strlen(result))] = '\0';
    } return (result);
}