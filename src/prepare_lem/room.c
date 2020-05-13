/*
** EPITECH PROJECT, 2020
** room
** File description:
** room
*/

#include "lem_in.h"

void free_chain_lem(lem_s *lem)
{
    lem_s *temp = lem->first;
    while (lem != NULL) {
        temp = lem;
        lem = lem->next;
        free (temp->room);
        free (temp);
    }
}

char *set_type_room(char *str)
{
        if (my_strcmp(str, "##start") == 0)
            return ("##start");
        if (my_strcmp(str, "##end") == 0)
            return ("##end");
    return (NULL);
}

void create_room(lem_s *lem, read_s *loop, int inf)
{
    lem_s *newcase = malloc(sizeof(*newcase));
    newcase->infinite = inf;
    set_case_room(newcase, loop->line);
    for (; lem->next != NULL; lem = lem->next);
    lem->next = newcase;
    newcase->next = NULL;
    newcase->prev = lem;
    newcase->first = lem->first;
    newcase->type = NULL;
    if (newcase->prev->type != NULL)
        newcase->type = newcase->prev->type;
    if (inf == 1)
        newcase->type = set_type_room(loop->prev->line);
}

void loop_room(lem_s *lem, read_s *line)
{
    int inf = lem->first->infinite;
    read_s *loop = line->first->next->next;
    loop = loop->next;
    for (; loop != NULL; loop = loop->next) {
        if (my_strcmp(loop->line, "#rooms") == 0 ||
            my_strcmp(loop->line, "#tunnels") == 0) {
                inf = 0;
                continue;
            }
        if (my_strcmp(loop->line, "##start") == 0 ||
            my_strcmp(loop->line, "##end") == 0) {
                inf = 1;
                continue;
            }
        if (count_char(loop->line, ' ') >= 2 && count_char(loop->line, 45) == 0)
            create_room(lem, loop, inf);
        inf = 0;
    }

}

lem_s *init_room(read_s *line)
{
    line = line->first->next;
    int inf = 0;
    while (my_strcmp(line->line, "#rooms") == 0 ||
        my_strcmp(line->line, "#tunnels") == 0)
            line = line->next;
    while (my_strcmp(line->line, "##start") == 0 ||
        my_strcmp(line->line, "##end") == 0) {
            inf = 1, line = line->next;
        }
    lem_s *lem;
    if (!(lem = malloc(sizeof(*lem))))
        return (NULL);
    lem->first = lem, lem->type = NULL;
    lem->next = NULL, lem->prev = NULL;
    if (inf == 1)
        lem->type = set_type_room(line->line);
    lem->infinite = inf;
    set_case_room(lem, line->line);
    return (lem);

}