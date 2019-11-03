/*
** EPITECH PROJECT, 2019
** base and operand changer
** File description:
** change custom base and operand to have a clean base and operand
*/

#include "my.h"

void string_changer(char *str, char *operand, int size)
{
    int i;
    int j;
    char *normal_operand = "()+-*/%";

    for (i = 0; i < size; i++) {
        for (j = 0; j < 7; j++) {
            if (str[i] == operand[j]) {
                str[i] = normal_operand[j];
            }
        }
    }
}

void base_changer(char *str, char *base, int size)
{
    int i;
    int j;
    char *normal_base = "0123456789";

    for (i = 0; i < size; i++) {
        for (j = 0; j < 10; j++) {
            if (str[i] == base[j]) {
                str[i] = normal_base[j];
            }
        }
    }
}

char *rev_base_changer(char *str, char *base)
{
    int i;
    int j;
    char *normal_base = "0123456789";

    for (i = 0; i < my_strlen(str); i++) {
        for (j = 0; j < 10; j++) {
            if (str[i] == normal_base[j]) {
                str[i] = base[j];
            }
        }
    }
    return str;
}

void convert(char *str, char *operand, int size, char *base)
{
    string_changer(str, operand, size);
    base_changer(str, base, size);
}