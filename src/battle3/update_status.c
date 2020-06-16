/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int reset_win_3(gui_t *game)
{
    game->info->scene = FOREST_MAP;
    game->info->trans = TRUE;
    game->battle3->finish = 1;
    game->inventory->potion = TRUE;
    game->inventory->iron = TRUE;
    game->inventory->nb_iron += 2;
    game->player->next_attack = game->player->attack;
    game->battle3->hp = game->battle3->hp_max;
    game->battle3->status = PLAYER_TURN;
    game->battle3->start = 1;
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
    (game->battle3->hp / game->battle3->hp_max), 87};
}

int update_different_status_3(gui_t *game)
{
    if (game->battle3->status == PLAYER_ATTACK) {
        update_player_attack_3(game);
    }
    if (game->battle3->status == PLAYER_BOOST) {
        update_player_boost_3(game);
    }
    if (game->battle3->status == REMOVE_ENEMY_HP) {
        update_remove_enemy_hp_3(game);
    }
    if (game->battle3->status == ENEMY_ATTACK) {
        update_enemy_attack_3(game);
    }
    if (game->battle3->status == REMOVE_PLAYER_HP) {
        update_player_hp_3(game);
    }
    return (1);
}
