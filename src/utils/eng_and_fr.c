/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** eng and fr
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_french(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[FRENCH_FLAG]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->lang = 0;
        game->info->scene = INTRO;
    }
}

void b_english(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[ENGLISH_FLAG]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->lang = 1;
        game->info->scene = INTRO;
    }
}