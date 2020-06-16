/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init save
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int init_save(gui_t *game)
{
    game->object[BG_SAVE]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[SAVE1]->position = (sfVector2f){.x = 675, .y = 295};
    game->object[SAVE1]->rect = (sfIntRect){0, 0, 250, 73};
    game->object[SAVE2]->position = (sfVector2f){.x = 675, .y = 410};
    game->object[SAVE2]->rect = (sfIntRect){0, 0, 250, 73};
    game->object[SAVE3]->position = (sfVector2f){.x = 675, .y = 525};
    game->object[SAVE3]->rect = (sfIntRect){0, 0, 250, 73};
    return (1);
}