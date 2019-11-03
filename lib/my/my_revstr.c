/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** invert string
*/

#include <stddef.h>

int check_error2(char *src)
{
    if (src == NULL)
        return (1);
    return (0);
}

int my_strlen2(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    int i;
    int len;
    char tmp;

    if (check_error2(str)) {
        return (NULL);
    } else {
        len = (my_strlen2(str) - 1);
        for (i = 0; str[i] != '\0'; i++)
        {
            tmp = str[i];
            str[i] = str[(len - i)];
            str[(len - i)] = tmp;
            if (i == (len / 2))
                return (str);
        }
    }
    return (str);
}