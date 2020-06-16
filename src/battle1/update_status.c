/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int reset_win_1(gui_t *game)
{
    game->adv = 1;
    game->diag = POPUP_POPO + (game->lang * 1);
    game->info->scene = FOREST_MAP;
    game->info->trans = TRUE;
    game->battle1->finish = 1;
    game->inventory->potion = TRUE;
    game->inventory->nb_potion += 3;
    game->player->next_attack = game->player->attack;
}

int update_different_status(gui_t *game)
{
    if (game->battle1->status == PLAYER_ATTACK) {
        update_player_attack(game);
    }
    if (game->battle1->status == PLAYER_BOOST) {
        update_player_boost(game);
    }
    if (game->battle1->status == REMOVE_ENEMY_HP) {
        update_remove_enemy_hp(game);
    }
    if (game->battle1->status == ENEMY_ATTACK) {
        update_enemy_attack(game);
    }
    if (game->battle1->status == REMOVE_PLAYER_HP) {
        update_player_hp(game);
    }
    return (1);
}
