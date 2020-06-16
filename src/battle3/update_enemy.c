/*
** EPITECH PROJECT, 2020
** PRG
** File description:
** update enemy
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int update_enemy_attack3_2(gui_t *game)
{
    static int i = 0;
    static int j = 0;
    unsigned int max_value =
    sfTexture_getSize(game->object[ENEMY_ATTACK_3]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[ARMOR1_HURT]);
        move_rect(game->object[ENEMY_ATTACK_3]);
        i = 0;
    } else
        i++;
    if (game->object[ENEMY_ATTACK_3]->rect.left +
    game->object[ENEMY_ATTACK_3]->rect.width
    >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle3->status = REMOVE_PLAYER_HP;
        game->player->pv -= game->battle3->attack;
        game->object[ENEMY_ATTACK_3]->rect.left = 0;
        j = 0;
    }
}

int update_enemy_attack_3(gui_t *game)
{
    update_enemy_attack3_2(game);
    sfSprite_setTextureRect(game->object[ENEMY_ATTACK_3]->sprite,
    game->object[ENEMY_ATTACK_3]->rect);
    sfSprite_setTextureRect(game->object[ARMOR1_HURT]->sprite,
    game->object[ARMOR1_HURT]->rect);
    return (1);
}

int update_remove_enemy_hp_3(gui_t *game)
{
    static int i = 0;
    update_player_turn_3(game);
    if (game->object[HEAL_GREEN_ENEMIES]->rect.width <= 0) {
        reset_win_3(game);
    }
    if (game->object[HEAL_GREEN_ENEMIES]->rect.width > (490 *
    (game->battle3->hp / game->battle3->hp_max)) &&
    game->object[HEAL_GREEN_ENEMIES]->rect.width != 0) {
        game->object[HEAL_GREEN_ENEMIES]->rect.width -= 1;
    } else if (i == 600) {
        game->battle3->status = ENEMY_ATTACK;
        i = 0;
    } else {
        i++;
    }
    return (1);
}

int reset_battle_player_die_3(gui_t *game)
{
    game->object[FOREST]->rect = (sfIntRect){7350, 4200, WIN_WIDTH, WIN_HEIGHT};
    game->player->pos_x = 7350 + (WIN_WIDTH / 2);
    game->player->pos_y = 4200 + (WIN_HEIGHT / 2);
    game->info->scene = DEATH;
    game->info->trans = TRUE;
    game->player->next_attack = game->player->attack;
    game->player->pv = game->player->pv_max;
    game->battle3->hp = game->battle3->hp_max;
    game->battle3->status = PLAYER_TURN;
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
    (game->battle3->hp / game->battle3->hp_max), 87};
    game->battle3->start = 1;
}

int update_player_hp_3(gui_t *game)
{
    static int i = 0;
    update_player_turn_3(game);
    if (game->object[HEAL_GREEN_PLAYER]->rect.width <= 0) {
        reset_battle_player_die_3(game);
    }
    if (game->object[HEAL_GREEN_PLAYER]->rect.width > (490 *
    (game->player->pv/ game->player->pv_max)) &&
    game->object[HEAL_GREEN_PLAYER]->rect.width != 0) {
        game->object[HEAL_GREEN_PLAYER]->rect.width -= 1;
    } else if (i == 300) {
        game->battle3->status = PLAYER_TURN;
        i = 0;
    } else {
        i++;
    }
    return (1);
}