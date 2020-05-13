/*
** EPITECH PROJECT, 2020
** chain_path
** File description:
** chain_path
*/

#include "lem_in.h"

void free_chain_path(lem_s *path)
{
    lem_s *temp = path->first;
    while (path != NULL) {
        temp = path;
        path = path->next;
        free (temp->room);
        free (temp->type);
        free (temp);
    }
}

void create_case_path(lem_s *path, lem_s *room)
{
    lem_s *newcase = malloc(sizeof(*newcase));
    newcase->first = path->first;
    for (;path->next != NULL; path = path->next);
    path->next = newcase;
    newcase->next = NULL;
    newcase->prev = path;
    newcase->room = my_strdup(room->room);
    if (room->type != NULL)
        newcase->type = my_strdup(room->type);
    else
        newcase->type = NULL;
    newcase->infinite = room->infinite;
    newcase->ant = 0;
}

lem_s *create_path(read_s *line, int v, lem_s *room)
{
    char **tab = my_str_to_word(line->line, 45);
    for (room = room->first; my_strcmp(tab[v -1], room->room) != 0;
        room = room->next);
    lem_s *path = init_chain_path(room);
    if (v == 1)
        for (room = room->first; my_strcmp(tab[1], room->room) != 0;
        room = room->next);
    if (v == 2)
        for (room = room->first; my_strcmp(tab[0], room->room) != 0;
        room = room->next);
    create_case_path(path, room);
    for (int i = 0; tab[i] != NULL; i++)
        free (tab[i]);
    free (tab);
    return (path);
}

lem_s *init_chain_path(lem_s *room)
{
    lem_s *path = malloc(sizeof(*path));
    path->next = NULL, path->prev = NULL;
    path->first = path;
    path->room = my_strdup(room->room);
    path->infinite = room->infinite;
    path->type = NULL;
    if (path->type != NULL)
        path->type = my_strdup(room->type);
    path->ant = 0;
    return (path);
}