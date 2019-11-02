/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i, j;
    for (i = 0 ; src[i] != '\0' ; i++);
    for (j = 0 ; j != i + 1 ; j++)
    {
        dest[j] = src[j];
    }
    return (dest);
}
