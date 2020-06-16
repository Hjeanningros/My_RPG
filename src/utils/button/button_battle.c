/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button battle
*/

#include "../../../include/game.h"
#include "../../../include/macro.h"
#include "../../../include/prototype.h"

void b_attack(gui_t *game, sfMouseButtonEvent e, battle_t *battle)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[BUTTON_ATTACK]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        battle->status = PLAYER_ATTACK;
    }
}

void b_boostattack(gui_t *game, sfMouseButtonEvent e, battle_t *battle)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[BUTTON_BOOSTATTACK]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        battle->status = PLAYER_BOOST;
    }
}

void b_escape(gui_t *game, sfMouseButtonEvent e, battle_t *battle)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[BUTTON_ESCAPE]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        battle->status = PLAYER_TURN;
        game->info->scene = FOREST_MAP;
        game->info->trans = TRUE;
        game->player->next_attack = game->player->attack;
        battle->hp = battle->hp_max;
        game->object[HEAL_GREEN_PLAYER]->rect = (sfIntRect){0, 0, 490 *
        (game->player->pv / game->player->pv_max), 87};
        game->object[HEAL_GREEN_ENEMIES]->rect = (sfIntRect){0, 0, 490 *
        (battle->hp / battle->hp_max), 87};
        battle->start = 1;
    }
}