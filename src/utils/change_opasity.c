/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void change_opasity(gui_t *g)
{
    sfColor opasity;
    if (check_opasity(g, g->player->pos_x, g->player->pos_y) == 1) {
        opasity = (sfColor){0, 0, 0, 100};
        sfSprite_setColor(g->player->sprite[g->player->status +
                        (g->player->lvl * 2)]->sprite, opasity);
    } else if (check_opasity(g, g->player->pos_x + 30, g->player->pos_y) == 1 ||
        check_opasity(g, g->player->pos_x, g->player->pos_y + 30) == 1 ||
        check_opasity(g, g->player->pos_x - 30, g->player->pos_y) == 1 ||
        check_opasity(g, g->player->pos_x, g->player->pos_y - 30) == 1) {
        opasity = (sfColor){255, 255, 255, 150};
        sfSprite_setColor(g->player->sprite[g->player->status +
                        (g->player->lvl * 2)]->sprite, opasity);
    } else {
        opasity = (sfColor){255, 255, 255, 255};
        sfSprite_setColor(g->player->sprite[g->player->status +
                        (g->player->lvl * 2)]->sprite, opasity);
    }
}