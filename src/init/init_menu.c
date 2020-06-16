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

int init_menu(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5_CP; i += 2)
        game->object[i]->position = (sfVector2f){.x = 1600, .y = 0};
    game->object[BG_MENU]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[B_PLAY]->position = (sfVector2f){.x = 675, .y = 285};
    game->object[B_PLAY]->rect = (sfIntRect){0, 0, 250, 73};
    game->object[B_KEY]->position = (sfVector2f){.x = 675, .y = 390};
    game->object[B_KEY]->rect = (sfIntRect){0, 0, 250, 73};
    game->object[B_SETTINGS]->position = (sfVector2f){.x = 675, .y = 495};
    game->object[B_SETTINGS]->rect = (sfIntRect){0, 0, 250, 73};
    game->object[B_QUIT]->position = (sfVector2f){.x = 675, .y = 600};
    game->object[B_QUIT]->rect = (sfIntRect){0, 0, 250, 73};
    return (1);
}