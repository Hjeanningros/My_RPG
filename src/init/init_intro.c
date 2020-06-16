/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int init_intro(gui_t *game)
{
    game->object[IMG_INTRO]->rect =
    (sfIntRect){860, 400, WIN_WIDTH, WIN_HEIGHT};
    game->object[BAND_BOT]->position.y = 900;
    game->object[BAND_TOP]->position.y = -900;
    sfSprite_setPosition(game->object[BAND_TOP]->sprite,
    game->object[BAND_TOP]->position);
    sfSprite_setPosition(game->object[BAND_BOT]->sprite,
    game->object[BAND_BOT]->position);
    sfSprite_setTextureRect(game->object[IMG_INTRO]->sprite,
    game->object[IMG_INTRO]->rect);
    game->stat_intro = 0;
    return (1);
}