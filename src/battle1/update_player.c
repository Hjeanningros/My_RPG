/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update player
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int update_player_turn(gui_t *game)
{
    static int i = 0;

    if (i == 20) {
        move_rect(game->object[IDLE_BL]);
        move_rect(game->object[ENEMY_IDLE_1]);
        i = 0;
    } else {
        i++;
    }
    sfSprite_setTextureRect(game->object[IDLE_BL]->sprite,
    game->object[IDLE_BL]->rect);
    sfSprite_setTextureRect(game->object[ENEMY_IDLE_1]->sprite,
    game->object[ENEMY_IDLE_1]->rect);
    return (1);
}

int update_player_attack2(gui_t *game)
{
    static int i = 0;
    static int j = 0;
    unsigned int max_value =
    sfTexture_getSize(game->object[ATTACK_BL]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[ATTACK_BL]);
        move_rect(game->object[ENEMY_HURT_1]);
        i = 0;
    } else
        i++;
    if (game->object[ATTACK_BL]->rect.left +
    game->object[ATTACK_BL]->rect.width >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle1->status = REMOVE_ENEMY_HP;
        game->battle1->hp -= game->player->next_attack;
        game->player->next_attack = game->player->attack;
        game->object[ATTACK_BL]->rect.left = 0;
        j = 0;
    }
}

int update_player_attack(gui_t *game)
{
    update_player_attack2(game);
    sfSprite_setTextureRect(game->object[ATTACK_BL]->sprite,
    game->object[ATTACK_BL]->rect);
    sfSprite_setTextureRect(game->object[ENEMY_HURT_1]->sprite,
    game->object[ENEMY_HURT_1]->rect);
    return (1);
}

int update_player_boost2(gui_t *game)
{
    static int i = 0;
    static int j = 0;
    unsigned int max_value =
    sfTexture_getSize(game->object[BOOST_BL]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[BOOST_BL]);
        move_rect(game->object[ENEMY_IDLE_1]);
        i = 0;
    } else
        i++;
    if (game->object[BOOST_BL]->rect.left + game->object[BOOST_BL]->rect.width
    >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle1->status = ENEMY_ATTACK;
        game->player->next_attack += 20;
        game->object[HURT_BL]->rect.left = 0;
        j = 0;
    }
}

int update_player_boost(gui_t *game)
{
    update_player_boost2(game);
    sfSprite_setTextureRect(game->object[BOOST_BL]->sprite,
    game->object[BOOST_BL]->rect);
    sfSprite_setTextureRect(game->object[ENEMY_IDLE_1]->sprite,
    game->object[ENEMY_IDLE_1]->rect);
    return (1);
}