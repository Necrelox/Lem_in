/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** lem_in
*/

#ifndef LEM_IN_H_
#define LEM_IN_H_

#include "my.h"
#include "structure.h"
                            /* __Prototype__*/

        // main.c
int main (void);

        // parse_and_lem/parse.c
void lem_step_one_room(read_s *line);
read_s *parse_read(int *pass);
int parse_lem(void);

        // read_and_verif/read.c
void free_chain_read(read_s *line);
void create_case_read(read_s *line, char *buff);
read_s *init_chain_read(char *buff);
read_s *read_file(void);

        // read_and_verif/verif.c
int count_char(char *str, char c);
char *transfo_end_str(char *str);
int verif_line(char *str);
void set_error_map(read_s *line);
int verif_map(read_s *line);

        // read_and_verif/verif.c
int verif_if_char(char *str);
int verif_exend_line(char *str);

        // prepare_lem/set_settings.c
void set_case_room(lem_s *lem, char *str);
lem_s *set_ant(read_s *line);

        // prepare_lem/room.c
void free_chain_lem(lem_s *lem);
char *set_type_room(char *str);
void create_room(lem_s *lem, read_s *loop, int inf);
void loop_room(lem_s *lem, read_s *line);
lem_s *init_room(read_s *line);

        // parse_and_lem/search_path.c
lem_s *search_path_one(read_s *line, lem_s *room);

        // parse_and_lem/chain_path.c
void free_chain_path(lem_s *path);
void create_case_path(lem_s *path, lem_s *room);
lem_s *create_path(read_s *line, int v, lem_s *room);
lem_s *init_chain_path(lem_s *room);


#endif /* !LEM_IN_H_ */
