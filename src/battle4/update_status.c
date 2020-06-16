/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int reset_win_4(gui_t *game)
{
    game->info->scene = FOREST_MAP;
    game->info->trans = TRUE;
    game->battle4->finish = 1;
    game->battle4->attack += 5;
    game->player->money += 30;
    game->player->next_attack = game->player->attack;
    game->battle4->hp_max += 5;
    game->battle4->hp = game->battle4->hp_max;
    game->battle4->status = PLAYER_TURN;
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
    (game->battle4->hp / game->battle4->hp_max), 87};
    game->battle4->start = 1;
}

int update_different_status_4(gui_t *game)
{
    if (game->battle4->status == PLAYER_ATTACK) {
        update_player_attack_4(game);
    }
    if (game->battle4->status == PLAYER_BOOST) {
        update_player_boost_4(game);
    }
    if (game->battle4->status == REMOVE_ENEMY_HP) {
        update_remove_enemy_hp_4(game);
    }
    if (game->battle4->status == ENEMY_ATTACK) {
        update_enemy_attack_4(game);
    }
    if (game->battle4->status == REMOVE_PLAYER_HP) {
        update_player_hp_4(game);
    }
    return (1);
}
