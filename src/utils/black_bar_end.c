/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** black bar end
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int end_black_bar(gui_t *game)
{
    static int i = 0;
    if (i == 16 && game->object[BAND_END_BOT]->position.y > 750) {
        game->object[BAND_END_BOT]->position.y -= 1;
        game->object[BAND_END_TOP]->position.y += 1;
        i = 0;
        sfSprite_setPosition(game->object[BAND_END_TOP]->sprite,
        game->object[BAND_END_TOP]->position);
        sfSprite_setPosition(game->object[BAND_END_BOT]->sprite,
        game->object[BAND_END_BOT]->position);
    }
    i++;
}