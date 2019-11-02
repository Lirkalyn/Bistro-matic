/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Display characters
*/

#include <unistd.h>

void my_putchar(char a)
{
    write(1, &a, 1);
}
