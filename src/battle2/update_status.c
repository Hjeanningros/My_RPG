/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int reset_win_2(gui_t *game)
{
    game->adv = 2;
    game->diag = POPUP_STUFF + (game->lang * 1);
    game->info->scene = FOREST_MAP;
    game->info->trans = TRUE;
    game->battle2->finish = 1;
    game->inventory->armor1 = TRUE;
    game->player->next_attack = game->player->attack;
}

int update_different_status_2(gui_t *game)
{
    if (game->battle2->status == PLAYER_ATTACK) {
        update_player_attack_2(game);
    }
    if (game->battle2->status == PLAYER_BOOST) {
        update_player_boost_2(game);
    }
    if (game->battle2->status == REMOVE_ENEMY_HP) {
        update_remove_enemy_hp_2(game);
    }
    if (game->battle2->status == ENEMY_ATTACK) {
        update_enemy_attack_2(game);
    }
    if (game->battle2->status == REMOVE_PLAYER_HP) {
        update_player_hp_2(game);
    }
    return (1);
}
