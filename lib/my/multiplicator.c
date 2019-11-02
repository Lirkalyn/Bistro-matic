/*
** EPITECH PROJECT, 2019
** multiplicator
** File description:
** Ceci va gérer les multiplications.
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char *el_multiplicator(char *num1, char *num2)
{
    char **res;
    int l = 0;
    int carry = 0;
    int tmp = 0;

    if ( my_strlen(num1) > my_strlen(num2) )
        res = malloc(sizeof(char *) * my_strlen(num1) + 2);
    else res = malloc(sizeof(char *) * my_strlen(num2) + 2);
    for ( int i = my_strlen(num1) - 1 ; i != 0 ; i--, l++ ) {
        res[l] = malloc(sizeof(char *) * my_strlen(num1) + my_strlen(num2) + 2);
        for ( int k = 0 ; k != l ; k++ )
            res[l][k] = '0';
        for ( int j = my_strlen(num2) - 1, c = l ; j != 0 ; j--, c++ ) {
            tmp = (num1[i] - '0') * (num2[j] - '0') + carry, carry = 0;
            if ( tmp > 9 && j != 1) {
                carry = tmp / 10, res[l][c] = (tmp % 10) + '0';
            } else if ( tmp > 9 ) {
                res[l][c] = (tmp % 10) + '0', res[l][c + 1] = (tmp / 10) + '0';
            } else res[l][c] = tmp + '0';
        }
    } return (el_additionator(l - 1, res, num1, num2));
}

char *el_additionator(int l, char **res, char *num1, char *num2)
{
    int tmp;
    int carry = 0;
    int k = -1;
    char *result;

    result = malloc(sizeof(char) * my_strlen(res[l]) + 2);
    for ( int i = 0 ; res[l][i] != '\0' ; i++ ) {
        tmp = 0;
        for ( int j = l ; j != k && res[j][i] != '\0' ; j-- ) {
            tmp = (res[j][i] - '0') + tmp + carry, carry = 0;
            if ( j != 0 && res[j - 1][i] == '\0' )
                k++;
        } if ( tmp > 9 && res[l][i + 1] != '\0' ) {
            carry = tmp / 10, result[i] = (tmp % 10) + '0';
        } else if ( tmp > 9 ) {
            result[i] = (tmp % 10) + '0', result[i + 1] = (tmp / 10) + '0';
        } else result[i] = tmp + '0';
    } return (returnator(result, num1, num2));
}

char *returnator(char *result, char *num1, char *num2)
{
    int i = my_strlen(result);

    if ( num1[0] == '-' && num2[0] == '-' ) {
        result[i] = '0';
        return (my_revstr(result));
    } else if ( num1[0] == '-' || num2[0] == '-' ) {
        result[i] = '-';
        return (my_revstr(result));
    } else {
        result[i] = '0';
        return (my_revstr(result));
    }
}