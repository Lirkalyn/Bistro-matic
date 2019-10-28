/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display numbers
*/

int my_put_nbr(int nb)
{
    if ( nb <= -2147483648 )
        return (0);
    if ( nb < 0 ) {
        my_putchar('-');
        nb = -nb;
    }
    if ( nb >= 10 ) {
        my_put_nbr( nb / 10 );
        my_put_nbr( nb % 10 );
    }
    else
        my_putchar( nb + 48 );
    return (0);
}
