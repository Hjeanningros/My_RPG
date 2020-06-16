/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init thrid battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_battle_3(gui_t *game)
{
    game->battle3->hp = 200;
    game->battle3->attack = 50;
    game->battle3->status = PLAYER_TURN;
    game->battle3->hp_max = 200;
    game->battle3->finish = 0;
    game->battle3->start = 1;
    game->object[ENEMY_IDLE_3]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_IDLE_3]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_HURT_3]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_HURT_3]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_ATTACK_3]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_ATTACK_3]->position = (sfVector2f){.x = 700, .y = 355};
    return (1);
}