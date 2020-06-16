/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init end
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int init_end(gui_t *game)
{
    game->object[BG_END]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[BG_END]->position = (sfVector2f){.x = 0, .y = 0};
    game->object[BAND_END_BOT]->position.y = 900;
    game->object[BAND_END_TOP]->position.y = -900;
    sfSprite_setPosition(game->object[BAND_END_TOP]->sprite,
    game->object[BAND_END_TOP]->position);
    sfSprite_setPosition(game->object[BAND_END_BOT]->sprite,
    game->object[BAND_END_BOT]->position);
    return (1);
}