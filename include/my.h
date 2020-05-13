/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include
*/

#define _POSIX_C_SOURCE 200809L
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include  <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <time.h>


//lib
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char *str);
int verif_if_number(char *str);
char *my_strdup(char *str);
int	my_strcmp(char *s1, char *s2);

// str_to_word_array
int count_separator(char *str, char separator);
char **my_str_to_word(char *str, char separator);