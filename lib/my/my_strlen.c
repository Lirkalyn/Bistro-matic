/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** find the size of the string
*/

int my_strlen(char const *str)
{
    int i;
    for (i = 0 ; str[i] != '\0' ; i++);
    return (i);
}
