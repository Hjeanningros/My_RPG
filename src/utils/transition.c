/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** transition between scene
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void transition(gui_t *game)
{
    static int i = 0;
    static int a = 255;
    sfColor color = sfColor_fromRGBA(0, 0, 0, a);
    ++i;
    if (i >= 3 && a > 0) {
        sfSprite_setColor(game->object[FONDU]->sprite, color);
        i = 0;
        a -= 10;
    }
    if (a <= 0) {
        game->info->trans = FALSE;
        a = 220;
    }
    displayer(game->window, game->object[FONDU]);
}

void logo(gui_t *game)
{
    static int i = 50;
    static int a = 1;
    sfColor color = sfColor_fromRGBA(255, 255, 255, a);

    game->object[LOGO]->position = (sfVector2f){.x = 500, .y = 200};
    ++i;
    if (i >= 3 && a <= 255) {
        sfSprite_setColor(game->object[LOGO]->sprite, color);
        i = 0;
        a += 10;
    }
    displayer(game->window, game->object[LOGO]);
}