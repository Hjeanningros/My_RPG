/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu.c
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void can_speak(gui_t *game)
{
    if ((game->diag == MARCHAND || game->diag == MARCHAND_ENG)) {
        if (sfKeyboard_isKeyPressed(sfKeyB) && game->player->money >= 30) {
            game->inventory->nb_potion += 1;
            game->player->money -= 30;
        }
    }
}