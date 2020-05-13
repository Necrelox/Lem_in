/*
** EPITECH PROJECT, 2020
** set_settings
** File description:
** set_settings
*/

#include "lem_in.h"

void set_case_room(lem_s *lem, char *str)
{
    char **tab = my_str_to_word(str, ' ');
    lem->room = my_strdup(tab[0]);
    lem->x = my_getnbr(tab[1]);
    lem->y = my_getnbr(tab[2]);
    for (int i = 0; tab[i] != NULL; i++)
        free (tab[i]);
    free (tab);
}

lem_s *set_ant(read_s *line)
{
    read_s *temp = line->first;
    lem_s *lem = NULL;
    if (!(lem = malloc(sizeof(*lem))))
        return (NULL);
    lem->ant = my_getnbr(temp->line);
    return (lem);
}
