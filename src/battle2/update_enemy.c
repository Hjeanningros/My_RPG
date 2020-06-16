/*
** EPITECH PROJECT, 2020
** PRG
** File description:
** update enemy
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int update_enemy_attack2_2(gui_t *game)
{
    static int i = 0;
    static int j = 0;
    unsigned int max_value =
    sfTexture_getSize(game->object[ENEMY_ATTACK_2]->texture).x;
    if (i == 20 && j < 3) {
        move_rect(game->object[HURT_BL]);
        move_rect(game->object[ENEMY_ATTACK_2]);
        i = 0;
    } else
        i++;
    if (game->object[ENEMY_ATTACK_2]->rect.left +
    game->object[ENEMY_ATTACK_2]->rect.width
    >= max_value && i == 0)
        j++;
    if (j == 3) {
        game->battle2->status = REMOVE_PLAYER_HP;
        game->player->pv -= game->battle2->attack;
        game->object[ENEMY_ATTACK_2]->rect.left = 0;
        j = 0;
    }
}

int update_enemy_attack_2(gui_t *game)
{
    update_enemy_attack2_2(game);
    sfSprite_setTextureRect(game->object[ENEMY_ATTACK_2]->sprite,
    game->object[ENEMY_ATTACK_2]->rect);
    sfSprite_setTextureRect(game->object[HURT_BL]->sprite,
    game->object[HURT_BL]->rect);
    return (1);
}

int update_remove_enemy_hp_2(gui_t *game)
{
    static int i = 0;
    update_player_turn_2(game);
    if (game->object[HEAL_GREEN_ENEMIES]->rect.width <= 0) {
        reset_win_2(game);
    }
    if (game->object[HEAL_GREEN_ENEMIES]->rect.width > (490 *
    (game->battle2->hp / game->battle2->hp_max)) &&
    game->object[HEAL_GREEN_ENEMIES]->rect.width != 0) {
        game->object[HEAL_GREEN_ENEMIES]->rect.width -= 1;
    } else if (i == 600) {
        game->battle2->status = ENEMY_ATTACK;
        i = 0;
    } else {
        i++;
    }
    return (1);
}

int reset_battle_player_die_2(gui_t *game)
{
    game->object[FOREST]->rect =
    (sfIntRect){1000, 11700, WIN_WIDTH, WIN_HEIGHT};
    game->player->pos_x = 1000 + (WIN_WIDTH / 2);
    game->player->pos_y = 11700 + (WIN_HEIGHT / 2);
    game->info->scene = DEATH;
    game->info->trans = TRUE;
    game->player->next_attack = game->player->attack;
    game->player->pv = game->player->pv_max;
    game->battle2->hp = game->battle2->hp_max;
    game->battle2->status = PLAYER_TURN;
    game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
    (game->player->pv / game->player->pv_max), 87};
    game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
    (game->battle2->hp / game->battle2->hp_max), 87};
    game->battle2->start = 1;
}

int update_player_hp_2(gui_t *game)
{
    static int i = 0;
    update_player_turn_2(game);
    if (game->object[HEAL_GREEN_PLAYER]->rect.width <= 0) {
        reset_battle_player_die_2(game);
    }
    if (game->object[HEAL_GREEN_PLAYER]->rect.width > (490 *
    (game->player->pv/ game->player->pv_max)) &&
    game->object[HEAL_GREEN_PLAYER]->rect.width != 0) {
        game->object[HEAL_GREEN_PLAYER]->rect.width -= 1;
    } else if (i == 300) {
        game->battle2->status = PLAYER_TURN;
        i = 0;
    } else {
        i++;
    }
    return (1);
}