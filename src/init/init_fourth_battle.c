/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init fourth battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_battle_4(gui_t *game)
{
    game->battle4->hp = 150;
    game->battle4->attack = 20;
    game->battle4->status = PLAYER_TURN;
    game->battle4->hp_max = 150;
    game->battle4->finish = 0;
    game->battle4->start = 1;
    game->object[ENEMY_IDLE_4]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_IDLE_4]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_HURT_4]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_HURT_4]->position = (sfVector2f){.x = 700, .y = 355};
    game->object[ENEMY_ATTACK_4]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_ATTACK_4]->position = (sfVector2f){.x = 700, .y = 355};
    return (1);
}