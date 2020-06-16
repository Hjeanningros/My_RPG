/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu.c
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void first_part_intro(gui_t *game)
{
        game->object[BAND_BOT]->position.y -= 1;
        game->object[BAND_TOP]->position.y += 1;
        if (game->object[BAND_BOT]->position.y == 750)
            game->stat_intro = 1;
        sfSprite_setPosition(game->object[BAND_TOP]->sprite,
                            game->object[BAND_TOP]->position);
        sfSprite_setPosition(game->object[BAND_BOT]->sprite,
                            game->object[BAND_BOT]->position);
}

void second_part_intro(gui_t *game)
{
    game->object[BAND_BOT]->position.y -= 1;
    game->object[BAND_TOP]->position.y += 1;
    if (game->object[BAND_BOT]->position.y == 450) {
        game->stat_intro = 3;
    }
    sfSprite_setPosition(game->object[BAND_TOP]->sprite,
                        game->object[BAND_TOP]->position);
    sfSprite_setPosition(game->object[BAND_BOT]->sprite,
                        game->object[BAND_BOT]->position);
}