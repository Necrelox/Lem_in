/*
** EPITECH PROJECT, 2020
** parse
** File description:
** parse
*/

#include "lem_in.h"

void lem_step_one_room(read_s *line)
{
    lem_s *lem[3];
    lem[0] = set_ant(line);
    lem[1] = init_room(line);
    loop_room(lem[1], line);
    lem_s *tp = lem[1]->first;
    for (; tp != NULL; tp = tp->next)
        printf ("room: %s , x: %d,  y: %d,  (%d) type: (%s)\n", tp->room, tp->x, tp->y, tp->infinite, tp->type);
    lem[2] = search_path_one(line, lem[1]);
    if (lem[2] != NULL) {
        lem_s *pa = lem[2]->first;
        printf ("\n\n");
        for (; pa != NULL; pa = pa->next)
            printf ("%s -->", pa->room);
        free_chain_path(lem[2]);
    }
    free (lem[0]);
    free_chain_lem(lem[1]);
    free_chain_read(line);
}

read_s *parse_read(int *pass)
{
    read_s *line;
    line = read_file();
    if (line == NULL)
        return (NULL);
    *pass = verif_map(line);
    set_error_map(line);
    return (line);
}

int parse_lem(void)
{
    int pass = 0;
    read_s *line =  parse_read(&pass);
    if (line == NULL)
        return (84);
    read_s *tmp = line->first;
    for (; tmp != NULL && tmp->error == 0; tmp = tmp->next) {
        my_putstr(tmp->line);
        my_putchar('\n');
    }
    if (tmp != NULL || pass == 1) {
        free_chain_read(line);
        return (84);
    }
    lem_step_one_room(line);
    return (0);
}
