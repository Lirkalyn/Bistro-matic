/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all basic function
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char a);
void my_putstr(char *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_atoi(char const *);
char *show_result(int n, char *result);
char *my_strcpy(char *dest, char const *src);
void string_changer(char *str, char *operand, int size);
void base_changer(char *str, char *base, int size);
char *rev_base_changer(char *str, char *base);
void convert(char *str, char *operand, int size, char *base);

#endif

