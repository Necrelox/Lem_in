/*
** EPITECH PROJECT, 2020
** structure
** File description:
** structure
*/

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

typedef struct lem_t
{
    char *type;
    int infinite;
    int ant;
    char *room;
    int x, y;
    struct lem_t *next, *prev, *first;
}lem_s;

typedef struct read_t
{
    char *line;
    int error;
    int nbline;
    struct read_t *next, *prev, *first;
}read_s;


#endif /* !STRUCTURE_H_ */
