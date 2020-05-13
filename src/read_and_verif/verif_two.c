/*
** EPITECH PROJECT, 2020
** verif_two
** File description:
** verif_two
*/

#include "lem_in.h"

int verif_if_char(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            count++;
    return (count);
}

int verif_exend_line(char *str)
{
    char **tab;
    if (count_char(str, ' ') >= 3 && count_char(str, 45) == 0) {
        tab = my_str_to_word(str, ' ');
        if (tab[3][0] == '#') {
            for (int i = 0; tab[i] != NULL; i++)
                free (tab[i]);
            free (tab);
            return (0);
        }
        for (int i = 0; tab[i] != NULL; i++)
            free (tab[i]);
        free (tab);
    }
    return (1);
}