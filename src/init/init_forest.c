/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init_menu
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_forest(gui_t *game)
{
    game->object[FOREST]->rect =
    (sfIntRect){1000, 11700, WIN_WIDTH, WIN_HEIGHT};
    game->player->pos_x = 1000 + (WIN_WIDTH / 2);
    game->player->pos_y = 11700 + (WIN_HEIGHT / 2);
    game->diag = -1;
    game->event = 0;
    game->adv = 0;
    game->lang = 0;
    return (1);
}