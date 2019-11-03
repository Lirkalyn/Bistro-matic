/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** error.h
*/

#ifndef _ERROR_H_
#define _ERROR_H_

int operator_in_the_base(char *base);
int two_identical_digits(char *base);
int invalid_expression(char *str);
int unknown_digit(char *str);
int not_enought_brackets(char *str);
int divide_by_zero(char *str);
int all_error(char *av1, char *av2, char *expr);

#endif
