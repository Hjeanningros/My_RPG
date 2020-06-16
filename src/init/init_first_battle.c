/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** first_battle init
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_battle_1(gui_t *game)
{
    game->battle1->hp = 100;
    game->battle1->attack = 30;
    game->battle1->status = PLAYER_TURN;
    game->battle1->hp_max = 100;
    game->battle1->finish = 0;
    game->battle1->start = 1;
    game->object[ENEMY_IDLE_1]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_IDLE_1]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_HURT_1]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_HURT_1]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_ATTACK_1]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_ATTACK_1]->position = (sfVector2f){.x = 700, .y = 355};
    return (1);
}