/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** invert string
*/

char *my_revstr(char *str)
{
    int i, u;
    for ( i = 0 ; str[i] != '\0' ; i++ );
    int r = i;
    char arr[r];
    for ( u = 0 ; u != r ; u++ )
    {
        i = i - 1;
        arr[u] = str[i];
    }
    for ( u = 0 ; u != r ; u++ )
    {
        str[i] = arr[u];
        i = i + 1;
    }
    return (str);
}
