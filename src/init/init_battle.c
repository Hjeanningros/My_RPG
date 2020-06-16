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

int init_battle2(gui_t *game)
{
    game->object[HEAL_GREEN_ENEMIES]->position = (sfVector2f){.x = 1005, .y =
    56};
    game->object[HEAL_GREEN_PLAYER]->position = (sfVector2f){.x = 105, .y =
    56};
    game->object[HEAL_RED_ENEMIES]->position = (sfVector2f){.x = 1000, .y =
    50};
    game->object[HEAL_RED_PLAYER]->position = (sfVector2f){.x = 100, .y = 50};
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490, 87};
    game->object[HEAL_RED_PLAYER]->rect = (sfIntRect){0, 0, 500, 99};
    game->object[HEAL_RED_ENEMIES]->rect = (sfIntRect){0, 0, 500, 99};
    game->object[BUTTON_ATTACK]->rect = (sfIntRect){0, 0, 150, 150};
    game->object[BUTTON_BOOSTATTACK]->rect = (sfIntRect){0, 0, 150, 150};
    game->object[BUTTON_ESCAPE]->rect = (sfIntRect){0, 0, 150, 150};
    game->object[BUTTON_ATTACK]->position = (sfVector2f){.x = 350, .y = 725};
    game->object[BUTTON_BOOSTATTACK]->position = (sfVector2f){.x = 725, .y =
    725};
    game->object[BUTTON_ESCAPE]->position = (sfVector2f){.x = 1100, .y = 725};
    return (1);
}

int init_battle(gui_t *game)
{
    game->object[BG_BATTLE]->rect = (sfIntRect){0, 0, 1600, 900};
    game->object[IDLE_BL]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[IDLE_BL]->position = (sfVector2f){.x = 550, .y = 355};
    game->object[ATTACK_BL]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ATTACK_BL]->position = (sfVector2f){.x = 550, .y = 355};
    game->object[BOOST_BL]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[BOOST_BL]->position = (sfVector2f){.x = 550, .y = 355};
    game->object[HURT_BL]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[HURT_BL]->position = (sfVector2f){.x = 550, .y = 355};
    for (int i = ARMOR1_ATTACK; i <= ARMOR2_BOOST; i++) {
        game->object[i]->rect = (sfIntRect){0, 0, 350, 350};
        game->object[i]->position = (sfVector2f){.x = 550, .y = 355};
    }
    init_battle2(game);
    return (1);
}