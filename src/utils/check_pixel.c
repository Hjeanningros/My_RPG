/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int check_colision(gui_t *g, unsigned int x, unsigned int y)
{
    g->map_check = sfImage_getPixel(g->map, x, y);
    if (g->map_check.r == 254 && g->map_check.g == 0 && g->map_check.b == 0 ||
        g->map_check.r == 254 && g->map_check.g == 0 && g->map_check.b == 2) {
        return (1);
    } else {
        return (0);
    }
}

int check_opasity(gui_t *g, unsigned int x, unsigned int y)
{
    g->map_check = sfImage_getPixel(g->map, x, y);
    if (g->map_check.r == 0 && g->map_check.g == 0 && g->map_check.b == 254) {
        return (1);
    } else {
        return (0);
    }
}

int check_pnj_1(gui_t *g, unsigned int x, unsigned int y)
{
    g->map_check = sfImage_getPixel(g->map, x, y);
    if (g->map_check.r == 255 && g->map_check.g == 0 && g->map_check.b == 216)
        return (1);
    if (g->map_check.r == 0 && g->map_check.g == 255 && g->map_check.b == 244)
        return (1);
    if (g->map_check.r == 254 && g->map_check.g == 255 && g->map_check.b == 1)
        return (1);
    if (g->map_check.r == 255 && g->map_check.g == 193 && g->map_check.b == 0)
        return (1);
    if (g->map_check.r == 167 && g->map_check.g == 0 && g->map_check.b == 254)
        return (1);
    if (g->map_check.r == 0 && g->map_check.g == 84 && g->map_check.b == 165)
        return (1);
    else
        return (0);
}

int check_pnj(gui_t *g, unsigned int x, unsigned int y)
{
    int save = check_pnj_1(g, x, y);

    g->map_check = sfImage_getPixel(g->map, x, y);
    if (save == 1)
        return (1);
    if (g->map_check.r == 243 && g->map_check.g == 101 && g->map_check.b == 35)
        return (1);
    if (g->map_check.r == 96 && g->map_check.g == 57 && g->map_check.b == 18)
        return (1);
    if (g->map_check.r == 237 && g->map_check.g == 22 && g->map_check.b == 90)
        return (1);
    if (g->map_check.r == 147 && g->map_check.g == 38 && g->map_check.b == 143)
        return (1);
    if (g->map_check.r == 0 && g->map_check.g == 166 && g->map_check.b == 80)
        return (1);
    if (g->map_check.r == 154 && g->map_check.g == 135 && g->map_check.b == 120)
        return (1);
    else {
        return (0);
    }
}