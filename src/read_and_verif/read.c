/*
** EPITECH PROJECT, 2020
** read
** File description:
** read
*/

#include "lem_in.h"

void free_chain_read(read_s *line)
{
    read_s *temp = line->first;
    while (line != NULL) {
        temp = line;
        //printf("%s   (%d)\n", temp->line, temp->error);
        line = line->next;
        free (temp->line);
        free (temp);
    }
}

void create_case_read(read_s *line, char *buff)
{
    read_s *newcase = malloc(sizeof(*newcase));
    static int tun = 0;
    if (count_char(buff, 45) && tun == 0) {
        tun = 1;
        create_case_read(line, "#tunnels");
    }
    newcase->first = line->first;
    buff = transfo_end_str(buff);
    newcase->line = my_strdup(buff);
    for (; line->next != NULL; line = line->next);
    newcase->nbline = line->nbline + 1;
    line->next = newcase;
    newcase->error = 0;
    newcase->prev = line;
    newcase->next = NULL;
}

read_s *init_chain_read(char *buff)
{
    read_s *line = malloc(sizeof(*line));
    buff = transfo_end_str(buff);
    line->line = my_strdup(buff);
    line->nbline = 0;
    line->error = 0;
    line->next = NULL;
    line->prev = NULL;
    line->first = line;
    return (line);
}

read_s *read_file(void)
{
    char *buff = NULL;
    size_t size = 10;
    if (!(buff = malloc(sizeof(char) * 10)))
        return (NULL);
    int op = getline(&buff, &size, stdin);
    if (op == -1) {
        free (buff);
        return (NULL);
    }
    read_s *line = init_chain_read(buff);
    create_case_read(line, "#rooms");
    for (op = getline(&buff, &size, stdin);
        op != -1; op = getline(&buff, &size, stdin))
            create_case_read(line, buff);
    free (buff);
    return (line);
}