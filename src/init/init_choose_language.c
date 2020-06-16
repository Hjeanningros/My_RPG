/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** choose_language
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int init_choose_language(gui_t *game)
{
    game->object[BG_LANGUAGE]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[FRENCH_FLAG]->position = (sfVector2f){.x = 716, .y = 295};
    game->object[FRENCH_FLAG]->rect = (sfIntRect){0, 0, 167, 126};
    game->object[ENGLISH_FLAG]->position = (sfVector2f){.x = 716, .y = 510};
    game->object[ENGLISH_FLAG]->rect = (sfIntRect){0, 0, 167, 124};
    return (1);
}