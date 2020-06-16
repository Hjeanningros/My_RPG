/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** display status
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int display_player_turn(gui_t *game)
{
    displayer(game->window, game->object[IDLE_BL]);
    displayer(game->window, game->object[ENEMY_IDLE_1]);
    return (1);
}

int display_player_attack(gui_t *game)
{
    displayer(game->window, game->object[ATTACK_BL]);
    displayer(game->window, game->object[ENEMY_HURT_1]);
    return (1);
}

int display_player_boost(gui_t *game)
{
    update_particles(game);
    displayer(game->window, game->object[BOOST_BL]);
    displayer(game->window, game->object[ENEMY_IDLE_1]);
    draw_particles(game->window, game->buffer);
    return (1);
}

int displayer_enemy_attack(gui_t *game)
{
    displayer(game->window, game->object[HURT_BL]);
    displayer(game->window, game->object[ENEMY_ATTACK_1]);
    return (1);
}

int display_status(gui_t *game)
{
    if (game->battle1->status == PLAYER_TURN) {
        display_player_turn(game);
    }
    if (game->battle1->status == PLAYER_ATTACK) {
        display_player_attack(game);
    }
    if (game->battle1->status == PLAYER_BOOST) {
        display_player_boost(game);
    }
    if (game->battle1->status == REMOVE_ENEMY_HP) {
        display_player_turn(game);
    }
    if (game->battle1->status == ENEMY_ATTACK) {
        displayer_enemy_attack(game);
    }
    if (game->battle1->status == REMOVE_PLAYER_HP) {
        display_player_turn(game);
    }
    return (1);
}