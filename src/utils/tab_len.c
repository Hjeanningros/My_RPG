/*
** EPITECH PROJECT, 2020
** Lem-in
** File description:
** tab_len
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int tab_len(char **tab)
{
    int count = 0;
    for (; tab[count] != NULL; count++);
    return (count);
}