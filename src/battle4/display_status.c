/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** display status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int display_player_turn_4(gui_t *game)
{
    if (game->player->lvl == 1) {
        displayer(game->window, game->object[ARMOR1_IDLE]);
    }
    if (game->player->lvl == 2) {
        displayer(game->window, game->object[ARMOR2_IDLE]);
    }
    displayer(game->window, game->object[ENEMY_IDLE_4]);
    return (1);
}

int display_player_attack_4(gui_t *game)
{
    if (game->player->lvl == 1) {
        displayer(game->window, game->object[ARMOR1_ATTACK]);
    }
    if (game->player->lvl == 2) {
        displayer(game->window, game->object[ARMOR2_ATTACK]);
    }
    displayer(game->window, game->object[ENEMY_HURT_4]);
    return (1);
}

int display_player_boost_4(gui_t *game)
{
    update_particles(game);
    if (game->player->lvl == 1) {
        displayer(game->window, game->object[ARMOR1_BOOST]);
    }
    if (game->player->lvl == 2) {
        displayer(game->window, game->object[ARMOR2_BOOST]);
    }
    displayer(game->window, game->object[ENEMY_IDLE_4]);
    draw_particles(game->window, game->buffer);
    return (1);
}

int displayer_enemy_attack_4(gui_t *game)
{
    if (game->player->lvl == 1) {
        displayer(game->window, game->object[ARMOR1_HURT]);
    }
    if (game->player->lvl == 2) {
        displayer(game->window, game->object[ARMOR2_HURT]);
    }
    displayer(game->window, game->object[ENEMY_ATTACK_4]);
    return (1);
}

int display_status_4(gui_t *game)
{
    if (game->battle4->status == PLAYER_TURN) {
        display_player_turn_4(game);
    }
    if (game->battle4->status == PLAYER_ATTACK) {
        display_player_attack_4(game);
    }
    if (game->battle4->status == PLAYER_BOOST) {
        display_player_boost_4(game);
    }
    if (game->battle4->status == REMOVE_ENEMY_HP) {
        display_player_turn_4(game);
    }
    if (game->battle4->status == ENEMY_ATTACK) {
        displayer_enemy_attack_4(game);
    }
    if (game->battle4->status == REMOVE_PLAYER_HP) {
        display_player_turn_4(game);
    }
    return (1);
}