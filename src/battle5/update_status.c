/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int reset_win_5(gui_t *game)
{
    game->info->scene = END;
    game->info->trans = TRUE;
    game->battle5->finish = 1;
    game->player->next_attack = game->player->attack;
    game->battle5->hp = game->battle5->hp_max;
    game->battle5->status = PLAYER_TURN;
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
    (game->battle5->hp / game->battle5->hp_max), 87};
    game->battle5->start = 1;
}

int update_different_status_5(gui_t *game)
{
    if (game->battle5->status == PLAYER_ATTACK) {
        update_player_attack_5(game);
    }
    if (game->battle5->status == PLAYER_BOOST) {
        update_player_boost_5(game);
    }
    if (game->battle5->status == REMOVE_ENEMY_HP) {
        update_remove_enemy_hp_5(game);
    }
    if (game->battle5->status == ENEMY_ATTACK) {
        update_enemy_attack_5(game);
    }
    if (game->battle5->status == REMOVE_PLAYER_HP) {
        update_player_hp_5(game);
    }
    return (1);
}
