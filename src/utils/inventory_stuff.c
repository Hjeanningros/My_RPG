/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** inventory
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void b_armor1(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[ARMOR_INV]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) &&
        game->inventory->armor1 == TRUE) {
        game->player->lvl = 1;
        game->player->pv_max = 200;
        game->player->armor = 30;
        game->player->attack = 50;
        game->player->next_attack = game->player->attack;
        if (game->player->pv > game->player->pv_max) {
            game->player->pv = game->player->pv_max;
        }
    }
}

void b_potion(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[POTION_INV]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) &&
        game->inventory->nb_potion > 0) {
        game->player->pv += 100;
        if (game->player->pv > game->player->pv_max) {
            game->player->pv = game->player->pv_max;
        }
        game->inventory->nb_potion -= 1;
    }
}

void b_armor2(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[SARMOR_INV]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y) &&
        game->inventory->armor2 == TRUE) {
        game->player->lvl = 2;
        game->player->pv_max = 300;
        game->player->armor = 50;
        game->player->attack = 70;
        game->player->next_attack = game->player->attack;
    }
}

void update_text_inv(gui_t *game)
{
    game->player->hp = (int)game->player->pv;
    sfText_setString(game->text[INV_HP]->text, int_to_str(game->player->hp));
    sfText_setString(game->text[INV_ATTACK]->text,
    int_to_str(game->player->attack));
    sfText_setString(game->text[INV_ARMOR]->text,
    int_to_str(game->player->armor));
    sfText_setString(game->text[INV_MONEY]->text,
    int_to_str(game->player->money));
    sfText_setString(game->text[INV_SLASH]->text, "I");
    sfText_setString(game->text[INV_HP_MAX]->text,
    int_to_str((int)game->player->pv_max));
    sfText_setString(game->text[INV_NB_POPO]->text,
    int_to_str(game->inventory->nb_potion));
    sfText_setString(game->text[INV_NB_IRON]->text,
    int_to_str(game->inventory->nb_iron));
}