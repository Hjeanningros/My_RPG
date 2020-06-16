/*
** EPITECH PROJECT, 2020
** PRG
** File description:
** update enemy
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int update_enemy_attack5_2(gui_t *game)
{
    static int i = 0;
    static int j = 0;
    unsigned int max_value =
    sfTexture_getSize(game->object[ENEMY_ATTACK_5]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[ARMOR1_HURT]);
        move_rect(game->object[ARMOR2_HURT]);
        move_rect(game->object[ENEMY_ATTACK_5]);
        i = 0;
    } else
        i++;
    if (game->object[ENEMY_ATTACK_5]->rect.left +
    game->object[ENEMY_ATTACK_5]->rect.width
    >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle5->status = REMOVE_PLAYER_HP;
        game->player->pv -= game->battle5->attack;
        game->object[ENEMY_ATTACK_5]->rect.left = 0;
        j = 0;
    }
}

int update_enemy_attack_5(gui_t *game)
{
    update_enemy_attack5_2(game);
    sfSprite_setTextureRect(game->object[ENEMY_ATTACK_5]->sprite,
    game->object[ENEMY_ATTACK_5]->rect);
    sfSprite_setTextureRect(game->object[ARMOR1_HURT]->sprite,
    game->object[ARMOR1_HURT]->rect);
    sfSprite_setTextureRect(game->object[ARMOR2_HURT]->sprite,
    game->object[ARMOR2_HURT]->rect);
    return (1);
}

int update_remove_enemy_hp_5(gui_t *game)
{
    static int i = 0;
    update_player_turn_5(game);
    if (game->object[HEAL_GREEN_ENEMIES]->rect.width <= 0) {
        reset_win_5(game);
    }
    if (game->object[HEAL_GREEN_ENEMIES]->rect.width > (490 *
    (game->battle5->hp / game->battle5->hp_max)) &&
    game->object[HEAL_GREEN_ENEMIES]->rect.width != 0) {
        game->object[HEAL_GREEN_ENEMIES]->rect.width -= 1;
    } else if (i == 600) {
        game->battle5->status = ENEMY_ATTACK;
        i = 0;
    } else {
        i++;
    }
    return (1);
}

int reset_battle_player_die_5(gui_t *game)
{
    game->object[FOREST]->rect = (sfIntRect){5000, 5400, WIN_WIDTH, WIN_HEIGHT};
    game->player->pos_x = 5000 + (WIN_WIDTH / 2);
    game->player->pos_y = 5400 + (WIN_HEIGHT / 2);
    game->info->scene = DEATH;
    game->info->trans = TRUE;
    game->player->next_attack = game->player->attack;
    game->player->pv = game->player->pv_max;
    game->battle5->hp = game->battle5->hp_max;
    game->battle5->status = PLAYER_TURN;
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
    (game->battle5->hp / game->battle5->hp_max), 87};
    game->battle5->start = 1;
}

int update_player_hp_5(gui_t *game)
{
    static int i = 0;
    update_player_turn_5(game);
    if (game->object[HEAL_GREEN_PLAYER]->rect.width <= 0) {
        reset_battle_player_die_5(game);
    }
    if (game->object[HEAL_GREEN_PLAYER]->rect.width > (490 *
    (game->player->pv/ game->player->pv_max)) &&
    game->object[HEAL_GREEN_PLAYER]->rect.width != 0) {
        game->object[HEAL_GREEN_PLAYER]->rect.width -= 1;
    } else if (i == 300) {
        game->battle5->status = PLAYER_TURN;
        i = 0;
    } else {
        i++;
    }
    return (1);
}