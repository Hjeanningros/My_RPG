/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** display status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int display_player_turn_3(gui_t *game)
{
    displayer(game->window, game->object[ARMOR1_IDLE]);
    displayer(game->window, game->object[ENEMY_IDLE_3]);
    return (1);
}

int display_player_attack_3(gui_t *game)
{
    displayer(game->window, game->object[ARMOR1_ATTACK]);
    displayer(game->window, game->object[ENEMY_HURT_3]);
    return (1);
}

int display_player_boost_3(gui_t *game)
{
    update_particles(game);
    displayer(game->window, game->object[ARMOR1_BOOST]);
    displayer(game->window, game->object[ENEMY_IDLE_3]);
    draw_particles(game->window, game->buffer);
    return (1);
}

int displayer_enemy_attack_3(gui_t *game)
{
    displayer(game->window, game->object[ARMOR1_HURT]);
    displayer(game->window, game->object[ENEMY_ATTACK_3]);
    return (1);
}

int display_status_3(gui_t *game)
{
    if (game->battle3->status == PLAYER_TURN) {
        display_player_turn_3(game);
    }
    if (game->battle3->status == PLAYER_ATTACK) {
        display_player_attack_3(game);
    }
    if (game->battle3->status == PLAYER_BOOST) {
        display_player_boost_3(game);
    }
    if (game->battle3->status == REMOVE_ENEMY_HP) {
        display_player_turn_3(game);
    }
    if (game->battle3->status == ENEMY_ATTACK) {
        displayer_enemy_attack_3(game);
    }
    if (game->battle3->status == REMOVE_PLAYER_HP) {
        display_player_turn_3(game);
    }
    return (1);
}