/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** update player
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int update_player_turn_5(gui_t *game)
{
    static int i = 0;

    if (i == 20) {
        move_rect(game->object[ARMOR1_IDLE]);
        move_rect(game->object[ARMOR2_IDLE]);
        move_rect(game->object[ENEMY_IDLE_5]);
        i = 0;
    } else {
        i++;
    }
    sfSprite_setTextureRect(game->object[ARMOR1_IDLE]->sprite,
    game->object[ARMOR1_IDLE]->rect);
    sfSprite_setTextureRect(game->object[ARMOR2_IDLE]->sprite,
    game->object[ARMOR2_IDLE]->rect);
    sfSprite_setTextureRect(game->object[ENEMY_IDLE_5]->sprite,
    game->object[ENEMY_IDLE_5]->rect);
    return (1);
}

int update_player_attack5_2(gui_t *game)
{
    static int i = 0; static int j = 0; unsigned int max_value =
    sfTexture_getSize(game->object[ARMOR1_ATTACK]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[ARMOR1_ATTACK]);
        move_rect(game->object[ARMOR2_ATTACK]);
        move_rect(game->object[ENEMY_HURT_5]);
        i = 0;
    } else
        i++;
    if (game->object[ARMOR1_ATTACK]->rect.left +
    game->object[ARMOR1_ATTACK]->rect.width >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle5->status = REMOVE_ENEMY_HP;
        game->battle5->hp -= game->player->next_attack;
        game->player->next_attack = game->player->attack;
        game->object[ARMOR1_ATTACK]->rect.left = 0;
        game->object[ARMOR2_ATTACK]->rect.left = 0;
        j = 0;
    }
}

int update_player_attack_5(gui_t *game)
{
    update_player_attack5_2(game);
    sfSprite_setTextureRect(game->object[ARMOR1_ATTACK]->sprite,
    game->object[ARMOR1_ATTACK]->rect);
    sfSprite_setTextureRect(game->object[ARMOR2_ATTACK]->sprite,
    game->object[ARMOR2_ATTACK]->rect);
    sfSprite_setTextureRect(game->object[ENEMY_HURT_5]->sprite,
    game->object[ENEMY_HURT_5]->rect);
    return (1);
}

int update_player_boost5_2(gui_t *game)
{
    static int i = 0; static int j = 0;
    unsigned int max_value =
    sfTexture_getSize(game->object[ARMOR1_BOOST]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[ARMOR1_BOOST]);
        move_rect(game->object[ARMOR2_BOOST]);
        move_rect(game->object[ENEMY_IDLE_5]);
        i = 0;
    } else
        i++;
    if (game->object[ARMOR1_BOOST]->rect.left +
    game->object[ARMOR1_BOOST]->rect.width >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle5->status = ENEMY_ATTACK;
        game->player->next_attack += 80;
        game->object[ARMOR1_BOOST]->rect.left = 0;
        game->object[ARMOR2_BOOST]->rect.left = 0;
        j = 0;
    }
}

int update_player_boost_5(gui_t *game)
{
    update_player_boost5_2(game);
    sfSprite_setTextureRect(game->object[ARMOR1_BOOST]->sprite,
    game->object[ARMOR1_BOOST]->rect);
    sfSprite_setTextureRect(game->object[ARMOR2_BOOST]->sprite,
    game->object[ARMOR2_BOOST]->rect);
    sfSprite_setTextureRect(game->object[ENEMY_IDLE_5]->sprite,
    game->object[ENEMY_IDLE_5]->rect);
    return (1);
}