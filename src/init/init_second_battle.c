/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init second battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_battle_2(gui_t *game)
{
    game->battle2->hp = 250;
    game->battle2->attack = 10;
    game->battle2->status = PLAYER_TURN;
    game->battle2->hp_max = 250;
    game->battle2->finish = 0;
    game->battle2->start = 1;
    game->object[ENEMY_IDLE_2]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_IDLE_2]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_HURT_2]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_HURT_2]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_ATTACK_2]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_ATTACK_2]->position = (sfVector2f){.x = 700, .y = 355};
    return (1);
}