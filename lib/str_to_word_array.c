/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** str_to_word_array
*/

#include "my.h"

int count_separator(char *str, char separator)
{
    int i = 0, count = 0;

    for (;str[i] != '\0'; i++) {
        if (str[i] == separator || str[i] == '\n')
            count++;
    }
    return (count);
}

char **my_str_to_word(char *str, char separator)
{
    int i = 0, j = 0, k = 0, count = count_separator(str, separator) + 1;
    char **tab;

    tab = malloc(sizeof(char *) * (count + 1));
    for (;i < count; i++)
        tab[i] = malloc(sizeof(char) *my_strlen(str));
    for (i = 0; i < count; i++) {
        for (j = 0; str[k] != separator && str[k] != '\n'
            && str[k] != '\0'; k++, j++) {
                tab[i][j] = str[k];
        }
        tab[i][j] = '\0';
        k++;
    }
    tab[i] = NULL;
    return (tab);
}