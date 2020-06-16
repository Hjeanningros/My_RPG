/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** setting function
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int setting_button(gui_t *game, sfEvent e)
{
    b_on_off_music(game, game->object[B_ON_OFF_MUSIC], e.mouseButton);
    b_on_off_sound(game, game->object[B_ON_OFF_SOUND], e.mouseButton);
    b_plus_music(game, game->object[B_PLUS], e.mouseButton);
    b_minus_music(game, game->object[B_MINUS], e.mouseButton);
    button_x2(game, game->object[B_RES1], e.mouseButton);
    button_x4(game, game->object[B_RES2], e.mouseButton);
    button_x8(game, game->object[B_RES3], e.mouseButton);
}
