/*
** EPITECH PROJECT, 2020
** verif
** File description:
** verif
*/

#include "lem_in.h"

int count_char(char *str, char c)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        str[i] == c ? count++ :0;
    return (count);
}

char *transfo_end_str(char *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    if (str[i] == '\n')
        str[i] = '\0';
    return (str);
}

int verif_line(char *str)
{
    char **tab;
    if (count_char(str, ' ') == 0 && count_char(str, 45) == 1)
        return (0);
    if (verif_exend_line(str) == 0)
        return (0);
    if (count_char(str, ' ') == 2 && count_char(str, 45) == 0) {
        tab = my_str_to_word(str, ' ');
        if (verif_if_number(tab[1]) > 0 && verif_if_char(tab[1]) == 0
            && verif_if_number(tab[2]) > 0 && verif_if_char(tab[2]) == 0) {
                for (int i = 0; tab[i] != NULL; i++)
                    free(tab[i]);
                free (tab);
                return (0);
            }
        for (int i = 0; tab[i] != NULL; i++)
            free(tab[i]);
        free (tab);
    }
    return (1);

}

void set_error_map(read_s *line)
{
    read_s *temp = line->first;
    if (verif_if_number(temp->line) == 0 || verif_if_char(temp->line) > 0)
        temp->error = 1;
    temp = temp->next;
    for (; temp != NULL; temp = temp->next) {
        if (my_strcmp(temp->line, "#rooms") == 0 ||
            my_strcmp(temp->line, "##start") == 0 ||
            my_strcmp(temp->line, "##end") == 0 ||
            my_strcmp(temp->line, "#tunnels") == 0)
                continue;
        temp->error = verif_line(temp->line);
    }
}

int verif_map(read_s *line)
{
    read_s *temp = line->first;
    int se = 0;

    for (;temp != NULL; temp = temp->next) {
        my_strcmp("##start", temp->line) == 0 ? se++ : 0;
        my_strcmp("##end", temp->line) == 0 ? se++ : 0;
    }
    if (se == 2)
        return (0);
    return (1);
}