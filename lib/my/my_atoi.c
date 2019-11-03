/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** fonction my_atoi
*/

int my_atoi(char *lol)
{
    int i;
    int l;
    int a = 0;
    int b = 1;
    int j;

    if ( lol[0] == '-' )
        i = 1, l = 2;
    else i = 0, l = 1;
    j = i;
    for ( i ; lol[i] != '\0' ; i++ );
    for ( int k = 0 ; k != i - l ; k++ )
        b = b * 10;
    for ( j ; lol[j] != '\0' ; j++ ) {
        a = (b * (lol[j] - '0')) + a;
        b = b / 10;
    }
    if ( lol[0] == '-' )
        a = a - (a * 2);
    return (a);
}
