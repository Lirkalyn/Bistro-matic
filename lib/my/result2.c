/*
** EPITECH PROJECT, 2019
** result-bistro
** File description:
** file for the result (for bistromatic)
*/

void find_a(char *str, int *last_a_pos, int *num_a)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            *last_a_pos = i;
            *num_a += 1;
        }
    }
}