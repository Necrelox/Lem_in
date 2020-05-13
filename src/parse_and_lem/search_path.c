/*
** EPITECH PROJECT, 2020
** search_path
** File description:
** search_path
*/

#include "lem_in.h"

int verif_if_end(lem_s *path)
{
    if (path != NULL) {
        lem_s *tmp = path->first;
        for (; tmp != NULL; tmp = tmp->next) {
            if (tmp->type != NULL)
                if (my_strcmp(tmp->type, "##end") == 0)
                    return (1);
        }
    }
    return (0);
}

int verif_start_or_not(char *str, lem_s *room)
{
    char **tab = my_str_to_word(str, 45);
    lem_s *room2 = room->first;
    for (; my_strcmp(tab[0], room->room) != 0; room = room->next);
    for (; my_strcmp(tab[1], room2->room) != 0; room2 = room2->next);
    for (int i = 0; tab[i] != NULL; i++)
        free (tab[i]);
    free(tab);
    if (room->type != NULL && room2->type != NULL)
        if (my_strcmp(room->type, "##start") == 0 &&
            my_strcmp(room2->type, "##start") == 0)
                return (0);
    if (room->type != NULL)
        if (my_strcmp(room->type, "##start") == 0)
            return (1);
    if (room2->type != NULL)
        if (my_strcmp(room2->type, "##start") == 0)
            return (2);
    return (0);
}

lem_s *search_path_one(read_s *line, lem_s *room)
{
    lem_s *path = NULL;
    line = line->first;
    for (; count_char(line->line, 45) == 0 && line != NULL;
        line = line->next);
    read_s *tmp = line;
    for (int verif = 0; tmp != NULL; tmp = tmp->next, verif = 0) {
            verif = verif_start_or_not(tmp->line, room);
            if (verif == 1)
                path = create_path(tmp, verif, room);<
            if (verif == 2)
                path = create_path(tmp, verif, room);
            else if (verif == 0) continue;
            if ((verif == 1 || verif == 2) && verif_if_end(path) == 0) {
                free_chain_path(path), path = NULL; }
            if ((verif == 1 || verif == 2) && verif_if_end(path) == 1)
                break;
    }
    if (path != NULL)
        return (path);
    return (NULL);
}