/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar
*/

#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}