/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init final battle
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

int init_battle_5(gui_t *game)
{
    game->battle5->hp = 300;
    game->battle5->attack = 90;
    game->battle5->status = PLAYER_TURN;
    game->battle5->hp_max = 300;
    game->battle5->finish = 0;
    game->battle5->start = 1;
    game->object[ENEMY_ATTACK_5]->scale = (sfVector2f){.x = 0.8, .y = 0.8};
    game->object[ENEMY_IDLE_5]->scale = (sfVector2f){.x = 0.8, .y = 0.8};
    game->object[ENEMY_HURT_5]->scale = (sfVector2f){.x = 0.8, .y = 0.8};
    game->object[ENEMY_IDLE_5]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_IDLE_5]->position = (sfVector2f){.x = 730, .y = 385};
    game->object[ENEMY_HURT_5]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_HURT_5]->position = (sfVector2f){.x = 730, .y = 385};
    game->object[ENEMY_ATTACK_5]->rect = (sfIntRect){0, 0, 350, 350};
    game->object[ENEMY_ATTACK_5]->position = (sfVector2f){.x = 730, .y = 385};
    return (1);
}